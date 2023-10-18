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
        strcat(str, digits[n]); // Convert single digits to words
    }
    else if (n < 100)
    {
        strcat(str, tens[n / 10]); // Convert tens place to words
        if (n % 10 != 0)
        {
            strcat(str, "-");
            strcat(str, digits[n % 10]); // Convert ones place to words
        }
    }
    else if (n < 1000)
    {
        strcat(str, digits[n / 100]); // Convert hundreds place to words
        strcat(str, " Hundred");
        if (n % 100 != 0)
        {
            strcat(str, " and ");
            int_to_string(n % 100, str); // Recursively convert remaining two digits
        }
    }
    else
    {
        strcat(str, digits[n / 1000]); // Convert thousands place to words
        strcat(str, " Thousand ");
        if (n % 1000 != 0)
        {
            int_to_string(n % 1000, str); // Recursively convert remaining three digits
        }
    }
}