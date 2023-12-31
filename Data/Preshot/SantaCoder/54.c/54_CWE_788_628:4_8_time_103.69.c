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
        sprintf(str, "%s %s", tens[n / 10], digits[n % 10]);
    }
    else if (n < 1000)
    {
        sprintf(str, "%s Hundred %s", digits[n / 100], tens[n / 10 % 10]);
        if (n % 10)
        {
            sprintf(str, "%s %s", str, digits[n % 10]);
        }
    }
    else if (n < 1000000)
    {
        sprintf(str, "%s Thousand %s", digits[n / 1000], digits[n / 100 % 10]);
        if (n / 100 % 10)
        {
            sprintf(str, "%s Hundred", str);
        }
        if (n % 1000 >= 100)
        {
            sprintf(str, "%s %s Hundred", str, digits[n % 1000 / 100]);
        }
        if (n % 100)
        {
            sprintf(str, "%s %s", str, int_to_string(n % 100));
        }
    }
    else if (n < 1000000000)
    {
        sprintf(str, "%s Million %s", int_to_string(n / 1000000), int_to_string(n % 1000000));
    }
}