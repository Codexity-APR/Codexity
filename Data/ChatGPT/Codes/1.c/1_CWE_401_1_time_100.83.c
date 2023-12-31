#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef unsigned char u8;
typedef unsigned short int u16;

struct icmp_header {
  unsigned char type;
  unsigned char code;
  unsigned short checksum;
  unsigned short id;
  unsigned short seq;
};

// Function to calculate the checksum
unsigned short in_cksum(unsigned short *ptr, int nbytes) {
  register long sum; /* assumes long == 32 bits */
  u_short oddbyte;
  register u_short answer; /* assumes u_short == 16 bits */

  sum = 0;
  while (nbytes > 1) {
    sum += *ptr++;
    nbytes -= 2;
  }

  if (nbytes == 1) {
    oddbyte = 0;
    *((u_char *)&oddbyte) = *(u_char *)ptr;
    sum += oddbyte;
  }

  sum = (sum >> 16) + (sum & 0xffff); /* add hi 16 to low 16 */
  sum += (sum >> 16);                 /* add carry */
  answer = ~sum;                      /* truncate to 16 bits */
  return (answer);
}

int main(int argc, char **argv) {
  int payload_size = 0, sent = 0, sent_size;
  unsigned long daddr = inet_addr("PUBLIC_IP");
  unsigned long saddr = inet_addr("PRIVATE_IP");

  // Raw socket - if you use IPPROTO_ICMP, then the kernel will fill in the correct ICMP header checksum, if IPPROTO_RAW, then it won't
  int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

  if (sockfd < 0) {
    perror("could not create socket");
    return 1;
  }

  int on = 1;

  // We shall provide IP headers
  if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, (const char *)&on, sizeof(on)) == -1) {
    perror("setsockopt");
    return 1;
  }

  // Allow socket to send datagrams to broadcast addresses
  if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (const char *)&on, sizeof(on)) == -1) {
    perror("setsockopt");
    return 1;
  }

  // Calculate total packet size
  int packet_size = sizeof(struct iphdr) + sizeof(struct icmp_header) + payload_size;

  char *buffer = (char *)malloc(packet_size);
  char *packet = (char *)malloc(packet_size);

  if (!packet) {
    perror("out of memory");
    return 1;
  }

  // IP header
  struct iphdr *ip = (struct iphdr *)packet;
  // ICMP header
  struct icmp_header *icmphdr = (struct icmp_header *)(packet + sizeof(struct iphdr));

  // Zero out the packet buffer
  memset(packet, 0, packet_size);
  memset(buffer, 0, packet_size);

  ip->version = 4;
  ip->ihl = 5;
  ip->tos = 0;
  ip->tot_len = htons(packet_size);
  ip->id = rand();
  ip->frag_off = 0;
  ip->ttl = 255;
  ip->protocol = IPPROTO_ICMP;
  ip->saddr = saddr;
  ip->daddr = daddr;

  // ICMP header
  icmphdr->type = ICMP_ECHO; // Echo request
  icmphdr->code = 0;
  icmphdr->id = 5;
  icmphdr->seq = 66;
  // Checksum
  icmphdr->checksum = 0;

  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = daddr;
  memset(&servaddr.sin_zero, 0, sizeof(servaddr.sin_zero));

  int ls = sizeof(servaddr);
  int rf;

  // Send and receive packets
  while (sent < 100) {
    // Recalculate the ICMP header checksum since we are filling the payload with random characters every time
    icmphdr->checksum = 0;
    icmphdr->checksum = htons(in_cksum((unsigned short *)icmphdr, sizeof(struct icmp_header) + payload_size));

    // Send the packet
    if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
      perror("sendto");
      return 1;
    }
    
    // Increment the sent count
    sent++;
  }

  free(packet);
  free(buffer);
  close(sockfd);

  return 0;
}