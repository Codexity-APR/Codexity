#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode();
NODEPTR insertionSort(NODEPTR head);

int main() {
    int i, n, temp;
    NODEPTR head, lptr, prevlptr;
    printf("No of input integers to be sorted\n");
    scanf("%d", &n);
    if (n < 2) {
        printf("n should be at least 2 \n");
        return 0;
    }
    printf("\nType space-separated array of %d integers\n", n);
    scanf("%d", &temp);

    head = getnode();
    head->info = temp;
        head->next = NULL;
        prevlptr = head;
        for (i = 2; i <= n; i++) {
            scanf("%d", &temp);
            lptr = getnode();
            lptr->info = temp;
            lptr->next = NULL;
            prevlptr->next = lptr;
            prevlptr = lptr;
        }
        printf("\nUnsorted list:\n");
        for (lptr = head; lptr != NULL; lptr = lptr->next)
            printf("%d ", lptr->info);
        printf("\n");
        head = insertionSort(head);
        printf("\nSorted list:\n");
        for (lptr = head; lptr != NULL; lptr = lptr->next)
            printf("%d ", lptr->info);
        printf("\n");
        return 0;
    }

    NODEPTR getnode() {
        NODEPTR p;
        p = (NODEPTR) malloc(sizeof(struct node));
        return p;
    }

    NODEPTR insertionSort(NODEPTR head) {
        NODEPTR p, q, r, s, temp;
        p = head;
        q = head->next;
        head->next = NULL;
        while (q != NULL) {
            r = q->next;
            if (q->info < p->info) {
                q->next = p;
                p = q;
            } else {
                s = p;
                while (s->next != NULL && s->next->info < q->info)
                    s = s->next;
                q->next = s->next;
                s->next = q;
            }
            q = r;
        }
        return p;
    }
