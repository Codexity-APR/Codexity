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
    char *digits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    if (n < 20)
    {
        strncpy(str, digits[n], 99);
        str[99] = '\0';
    }
    else if (n < 100)
    {
        int tensDigit = n / 10;
        int onesDigit = n % 10;
        if (onesDigit == 0)
        {
            strncpy(str, tens[tensDigit], 99);
            str[99] = '\0';
        }
        else
        {
            snprintf(str, 99, "%s-%s", tens[tensDigit], digits[onesDigit]);
            str[99] = '\0';
        }
    }
    else if (n < 1000)
    {
        int hundredsDigit = n / 100;
        int remainingDigits = n % 100;
        snprintf(str, 99, "%s Hundred ", digits[hundredsDigit]);
        str[99] = '\0';
        int_to_string(remainingDigits, str + strlen(str));
    }
    else
    {
        int thousandsDigit = n / 1000;
        int remainingDigits = n % 1000;
        snprintf(str, 99, "%s Thousand ", digits[thousandsDigit]);
        str[99] = '\0';
        int_to_string(remainingDigits, str + strlen(str));
    }
}