#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

typedef struct node* NODEPTR;

NODEPTR getnode();
NODEPTR insertion_sort(NODEPTR head);

int main() {
  int i, n, temp;
  NODEPTR head, lptr, prevlptr;

  printf("Enter the number of integers to be sorted: ");
  scanf("%d", &n);

  if (n < 2) {
    printf("n should be at least 2.\n");
    return 0;
  }

  printf("\nType space-separated array of %d integers: ", n);
  scanf("%d", &temp);

  head = getnode();
  head->info = temp;
  head->next = NULL;
  prevlptr = head;

  for (i = 1; i < n; i++) {
    lptr = getnode();
    scanf("%d", &temp);
    lptr->info = temp;
    lptr->next = NULL;
    prevlptr->next = lptr;
    prevlptr = lptr;
  }

  head = insertion_sort(head);
  lptr = head;

  while (lptr != NULL) {
    printf("%d ", lptr->info);
    lptr = lptr->next;
  }

  printf("\n");
  return 0;
}

NODEPTR getnode() {
  NODEPTR temp = (NODEPTR)malloc(sizeof(struct node));
  return temp;
}

NODEPTR insertion_sort(NODEPTR head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  NODEPTR sorted_list = NULL;
  NODEPTR current_node = head;

  while (current_node != NULL) {
    NODEPTR next_node = current_node->next;

    if (sorted_list == NULL || sorted_list->info >= current_node->info) {
      current_node->next = sorted_list;
      sorted_list = current_node;
    } else {
      NODEPTR temp = sorted_list;

      while (temp != NULL && temp->next != NULL && temp->next->info < current_node->info) {
        temp = temp->next;
      }

      current_node->next = temp->next;
      temp->next = current_node;
    }

    current_node = next_node;
  }

  return sorted_list;
}