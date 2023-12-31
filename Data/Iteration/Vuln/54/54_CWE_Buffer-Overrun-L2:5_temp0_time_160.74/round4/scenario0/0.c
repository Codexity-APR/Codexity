List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  50.     else
  51.     {
  52.         strcat(str, digits[n / 1000]);
              ^
  53.         strcat(str, " Thousand");
  54.         if (n % 1000 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  40.     else if (n < 1000)
  41.     {
  42.         strcat(str, digits[n / 100]);
              ^
  43.         strcat(str, " Hundred");
  44.         if (n % 100 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  35.         {
  36.             strcat(str, " ");
  37.             strcat(str, digits[n % 10]);
                  ^
  38.         }
  39.     }

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

Error: Buffer Overrun L2   Offset: [0, 99] Size: 20 by call to `int_to_string`.
 Example: 
  10.     scanf("%d", &n);
  11.     char str[100] = "";
  12.     int_to_string(n, str);
          ^
  13.     printf("%d in words is: %s\n", n, str);
  14.     return 0;

 Error type: CWE-788 at line: 47. Error message: Either the condition 'n<1000' is redundant or the array 'digits[20]' is accessed at index 99, which is out of bounds.

 Error type: CWE-788 at line: 62. Error message: Either the condition 'n>9999' is redundant or the array 'digits[20]' is accessed at index 99, which is out of bounds.


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
            strcat(str, " ");
            strcat(str, digits[n % 10]);
        }
    }
    else if (n < 1000)
    {
        strcat(str, digits[n / 100]);
        strcat(str, " Hundred");
        if (n % 100 != 0)
        {
            strcat(str, " and ");
            strcat(str, digits[n % 100]);
        }
    }
    else
    {
        strcat(str, digits[n / 1000]);
        strcat(str, " Thousand");
        if (n % 1000 != 0)
        {
            strcat(str, " and ");
            strcat(str, digits[(n % 1000) / 100]);
            strcat(str, " Hundred");
            if (n % 100 != 0)
            {
                strcat(str, " and ");
                strcat(str, digits[n % 100]);
            }
        }
    }
}