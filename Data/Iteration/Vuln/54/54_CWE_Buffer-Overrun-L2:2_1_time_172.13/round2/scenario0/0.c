List of vulnerabilities detected: 
Error: Buffer Overrun L1   Offset added: 99 Size: 4.
 Example: 
  25.     if (n < 20)
  26.     {
  27.         strncpy(str, digits[n], 99); // Changed buffer size to 99
              ^
  28.         str[99] = '\0';
  29.     }

Error: Buffer Overrun L1   Offset added: 99 Size: 1.
 Example: 
  34.         if (onesDigit == 0)
  35.         {
  36.             strncpy(str, tens[tensDigit], 99); // Changed buffer size to 99
                  ^
  37.             str[99] = '\0';
  38.         }


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
        strncpy(str, digits[n], 99); // Changed buffer size to 99
        str[99] = '\0';
    }
    else if (n < 100)
    {
        int tensDigit = n / 10;
        int onesDigit = n % 10;
        if (onesDigit == 0)
        {
            strncpy(str, tens[tensDigit], 99); // Changed buffer size to 99
            str[99] = '\0';
        }
        else
        {
            snprintf(str, 99, "%s-%s", tens[tensDigit], digits[onesDigit]); // Changed buffer size to 99
            str[99] = '\0';
        }
    }
    else if (n < 1000)
    {
        int hundredsDigit = n / 100;
        int remainingDigits = n % 100;
        snprintf(str, 99, "%s Hundred ", digits[hundredsDigit]); // Changed buffer size to 99
        str[99] = '\0';
        int_to_string(remainingDigits, str + strlen(str));
    }
    else
    {
        int thousandsDigit = n / 1000;
        int remainingDigits = n % 1000;
        snprintf(str, 99, "%s Thousand ", digits[thousandsDigit]); // Changed buffer size to 99
        str[99] = '\0';
        int_to_string(remainingDigits, str + strlen(str));
    }
}