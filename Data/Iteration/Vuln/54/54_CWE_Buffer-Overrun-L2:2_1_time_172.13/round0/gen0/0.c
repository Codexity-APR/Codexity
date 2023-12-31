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
        strcpy(str, digits[n]);
    }
    else if (n < 100)
    {
        int tensDigit = n / 10;
        int onesDigit = n % 10;
        if (onesDigit == 0)
        {
            strcpy(str, tens[tensDigit]);
        }
        else
        {
            sprintf(str, "%s-%s", tens[tensDigit], digits[onesDigit]);
        }
    }
    else if (n < 1000)
    {
        int hundredsDigit = n / 100;
        int remainingDigits = n % 100;
        sprintf(str, "%s Hundred ", digits[hundredsDigit]);
        int_to_string(remainingDigits, str + strlen(str));
    }
    else
    {
        int thousandsDigit = n / 1000;
        int remainingDigits = n % 1000;
        sprintf(str, "%s Thousand ", digits[thousandsDigit]);
        int_to_string(remainingDigits, str + strlen(str));
    }
}