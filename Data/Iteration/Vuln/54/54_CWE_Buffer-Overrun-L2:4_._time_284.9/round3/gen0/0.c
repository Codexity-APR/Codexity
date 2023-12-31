#include <stdio.h>
#include <string.h>

void int_to_string(int n, char *str);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    char str[500] = ""; // Increased buffer size to accommodate larger strings
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
        int tens_digit = (n / 10) % 10;
        int ones_digit = n % 10;
        sprintf(str, "%s Hundred ", digits[hundreds_digit]);
        if (tens_digit == 0)
        {
            strcat(str, digits[ones_digit]);
        }
        else if (tens_digit == 1)
        {
            strcat(str, digits[tens_digit * 10 + ones_digit]);
        }
        else
        {
            strcat(str, tens[tens_digit]);
            if (ones_digit != 0)
            {
                strcat(str, "-");
                strcat(str, digits[ones_digit]);
            }
        }
    }
    else if (n < 10000)
    {
        int thousands_digit = n / 1000;
        int hundreds_digit = (n / 100) % 10;
        int tens_digit = (n / 10) % 10;
        int ones_digit = n % 10;
        sprintf(str, "%s Thousand ", digits[thousands_digit]);
        strcat(str, digits[hundreds_digit]);
        strcat(str, " Hundred ");
        if (tens_digit == 0)
        {
            strcat(str, digits[ones_digit]);
        }
        else if (tens_digit == 1)
        {
            strcat(str, digits[tens_digit * 10 + ones_digit]);
        }
        else
        {
            strcat(str, tens[tens_digit]);
            if (ones_digit != 0)
            {
                strcat(str, "-");
                strcat(str, digits[ones_digit]);
            }
        }
    }
}