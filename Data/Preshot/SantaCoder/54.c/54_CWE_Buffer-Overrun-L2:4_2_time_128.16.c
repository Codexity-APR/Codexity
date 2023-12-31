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

    char *digits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",
                      "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (n < 20)
    {
        strcpy(str, digits[n]);
    }
    else if (n < 100)
    {
        strcpy(str, tens[n/10]);
        if (n % 10)
        {
            strcat(str, " ");
            strcat(str, digits[n % 10]);
        }
    }
    else if (n < 1000)
    {
        strcpy(str, digits[n/100]);
        strcat(str, " Hundred");
        if (n % 100)
        {
            strcat(str, " and ");
            int_to_string(n % 100, str + strlen(str));
        }
    }
    else if (n < 1000000)
    {
        int_to_string(n / 1000, str);
        strcat(str, " Thousand");
        if (n % 1000)
        {
            if (n % 1000 < 100)
            {
                strcat(str, " and");
            }
            strcat(str, " ");
            int_to_string(n % 1000, str + strlen(str));
        }
    }
    else if (n < 1000000000)
    {
        int_to_string(n / 1000000, str);
        strcat(str, " Million");
        if (n % 1000000)
        {
            if (n % 1000000 < 100)
            {
                strcat(str, " and");
            }
            strcat(str, " ");
            int_to_string(n % 1000000, str + strlen(str));
        }
    }
}