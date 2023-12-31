List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  64.             {
  65.                 strcat(str, "-");
  66.                 strcat(str, digits[ones_digit]);
                      ^
  67.             }
  68.         }

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  52.         if (tens_digit == 0)
  53.         {
  54.             strcat(str, digits[ones_digit]);
                  ^
  55.         }
  56.         else if (tens_digit == 1)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  29.     if (n < 20)
  30.     {
  31.         strcpy(str, digits[n]);
              ^
  32.     }
  33.     else if (n < 100)

Error: Buffer Overrun L2   Offset: [0, 7] Size: 1.
 Example: 
  37.         if (ones_digit == 0)
  38.         {
  39.             strcpy(str, tens[tens_digit]);
                  ^
  40.         }
  41.         else


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
        sprintf(str + strlen(str), "%s Hundred ", digits[hundreds_digit]);
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