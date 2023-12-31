List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  49.     else
  50.     {
  51.         strcat(str, digits[n / 1000]);
              ^
  52.         strcat(str, " Thousand ");
  53.         if (n % 1000 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  39.     else if (n < 1000)
  40.     {
  41.         strcat(str, digits[n / 100]);
              ^
  42.         strcat(str, " Hundred ");
  43.         if (n % 100 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  34.         if (n % 10 != 0)
  35.         {
  36.             strcat(str, digits[n % 10]);
                  ^
  37.         }
  38.     }

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  27.     if (n < 20)
  28.     {
  29.         strcat(str, digits[n]);
              ^
  30.     }
  31.     else if (n < 100)

Error: Buffer Overrun L2   Offset: [0, 7] Size: 1.
 Example: 
  31.     else if (n < 100)
  32.     {
  33.         strcat(str, tens[n / 10]);
              ^
  34.         if (n % 10 != 0)
  35.         {


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
        strcat(str, digits[n]);
    }
    else if (n < 100)
    {
        strcat(str, tens[n / 10]);
        if (n % 10 != 0)
        {
            strcat(str, digits[n % 10]);
        }
    }
    else if (n < 1000)
    {
        strcat(str, digits[n / 100]);
        strcat(str, " Hundred ");
        if (n % 100 != 0)
        {
            strcat(str, "and ");
            int_to_string(n % 100, str);
        }
    }
    else
    {
        strcat(str, digits[n / 1000]);
        strcat(str, " Thousand ");
        if (n % 1000 != 0)
        {
            int_to_string(n % 1000, str);
        }
    }
}