#include <stdio.h>
#include <string.h>

void int_to_string(int n, char *str);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    char str[100] = "";
    int_to_string(n, str);
    printf("%d in words is: %s\n", n, str);
    return 0;
}

void int_to_string(int n, char *str)
{
    if (n < 0 || n > 999999999)
    {
        return;
    }

    char *digits[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
                      "Seven", "Eight", "Nine"};

    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (n == 0)
    {
        strcat(str, "Zero");
        return;
    }

    if (n < 0)
    {
        strcat(str, "Minus ");
        n = -n;
    }

    if (n >= 1000000000)
    {
        int_to_string(n / 1000000000, str);
        strcat(str, " Billion ");
        n %= 1000000000;
    }

    if (n >= 1000000)
    {
        int_to_string(n / 1000000, str);
        strcat(str, " Million ");
        n %= 1000000;
    }

    if (n >= 1000)
    {
        int_to_string(n / 1000, str);
        strcat(str, " Thousand ");
        n %= 1000;
    }

    if (n >= 100)
    {
        int_to_string(n / 100, str);
        strcat(str, " Hundred ");
        n %= 100;
    }

    if (n >= 20)
    {
        strcat(str, tens[n / 10]);
        n %= 10;
        if (n > 0)
        {
            strcat(str, " ");
        }
    }

    if (n > 0)
    {
        strcat(str, digits[n]);
    }
}