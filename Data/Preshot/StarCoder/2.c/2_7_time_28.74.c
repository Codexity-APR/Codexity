#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_CARD_LEN 16
#define MAX_PHONE_LEN 10

int main()
{
    char name[MAX_NAME_LEN + 1];
    char password[MAX_NAME_LEN + 1];
    char card[MAX_CARD_LEN + 1];
    char phone[MAX_PHONE_LEN + 1];

    printf("Enter your name (max %d characters): ", MAX_NAME_LEN);
    fgets(name, MAX_NAME_LEN + 1, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your password (max %d characters): ", MAX_NAME_LEN);
    fgets(password, MAX_NAME_LEN + 1, stdin);
    password[strcspn(password, "\n")] = '\0';

    printf("Enter your credit card number (max %d digits): ", MAX_CARD_LEN);
    fgets(card, MAX_CARD_LEN + 1, stdin);
    card[strcspn(card, "\n")] = '\0';

    printf("Enter your mobile number (max %d digits): ", MAX_PHONE_LEN);
    fgets(phone, MAX_PHONE_LEN + 1, stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Hello %s, your password is %s, your credit card number is %s, your mobile number is %s\n",
           name, password, card, phone);

    return 0;
}