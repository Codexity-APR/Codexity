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

int main(int argc, char **argv) {
    int payload_size = 0, sent = 0, sent_size;
    unsigned long daddr = inet_addr("PUBLIC_IP");
    unsigned long saddr = inet_addr("PRIVATE_IP");

    // Raw socket - if you use IPPROTO_ICMP, then kernel will fill in the correct ICMP header checksum, if IPPROTO_RAW, then it wont
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("could not create socket");
        return 1;
    }

    int on = 1;

    // We shall provide IP headers
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Allow socket to send datagrams to broadcast addresses
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Calculate total packet size
    int packet_size = sizeof(struct iphdr) + sizeof(struct icmp_header) + payload_size;

    // Allocate memory for packet
    char *packet = malloc(packet_size);
    if (!packet) {
        perror("out of memory");
        return 1;
    }

    // IP header
    struct iphdr* ip = (struct iphdr*) packet;

    // ICMP header
    struct icmp_header* icmphdr = (struct icmp_header*) (packet + sizeof(struct iphdr)); 

    // Zero out the packet buffer
    memset(packet, 0, packet_size);

    // Fill in the IP header fields
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

    // Fill in the ICMP header fields
    icmphdr->type = ICMP_ECHO; // Echo request
    icmphdr->code = 0;
    icmphdr->id = 5;
    icmphdr->seq = 66;
    icmphdr->checksum = 0;

    // Fill in the socket address structure
    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = daddr;

    // Send and receive packets
    while (sent < 100) {
        // Recalculate the ICMP header checksum since we are filling the payload with random characters everytime
        icmphdr->checksum = 0;
        icmphdr->checksum = htons(in_cksum((unsigned short*) icmphdr, sizeof(struct icmp_header) + payload_size));

        // Send the packet
        if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
            perror("sendto");
            return 1;
        }
        
        // Wait for the response
        struct timeval tv;
        tv.tv_sec = 3;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        // Receive the packet
        char recv_buff[packet_size] = {0};
        if (recv(sockfd, recv_buff, packet_size, 0) < 0) {
            perror("recv");
            return 1;
        }

        // Extract the ICMP header from the response
        struct icmp_header *icmp_resp = (struct icmp_header *) (recv_buff + sizeof(struct iphdr));

        // Check if the packet is an echo reply
        if (icmp_resp->type == ICMP_ECHOREPLY) {
            printf("Received an echo reply from %s\n", inet_ntoa(servaddr.sin_addr));
            sent++;
        }
    }

    // Close the socket
    close(sockfd);

    // Free the memory allocated for the packet
    free(packet);

    return 0;
}

// Checksum function
unsigned short in_cksum(unsigned short *buf, int len) {
    unsigned long sum = 0;
    for (int i = 0; i < len; i++) {
        sum += buf[i];
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short) ~sum;
}