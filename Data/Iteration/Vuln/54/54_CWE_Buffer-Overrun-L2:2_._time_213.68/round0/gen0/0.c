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
    if (n < 0 || n > 9999)
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
        int tens_digit = n / 10;
        int ones_digit = n % 10;
        if (ones_digit == 0)
        {
            strcpy(str, tens[tens_digit]);
        }
        else
        {
            sprintf(str, "%s-%s", tens[tens_digit], digits[ones_digit]);
        }
    }
    else if (n < 1000)
    {
        int hundreds_digit = n / 100;
        int remaining = n % 100;
        sprintf(str, "%s Hundred", digits[hundreds_digit]);
        if (remaining != 0)
        {
            char remaining_str[100] = "";
            int_to_string(remaining, remaining_str);
            strcat(str, " and ");
            strcat(str, remaining_str);
        }
    }
    else
    {
        int thousands_digit = n / 1000;
        int remaining = n % 1000;
        sprintf(str, "%s Thousand", digits[thousands_digit]);
        if (remaining != 0)
        {
            char remaining_str[100] = "";
            int_to_string(remaining, remaining_str);
            strcat(str, " ");
            strcat(str, remaining_str);
        }
    }
}