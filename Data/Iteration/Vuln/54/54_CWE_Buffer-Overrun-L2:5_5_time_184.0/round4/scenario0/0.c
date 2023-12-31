List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  56.     else if (n < 10000)
  57.     {
  58.         strcat(str, digits[n / 1000]);
              ^
  59.         strcat(str, " Thousand");
  60.         if (n % 1000 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  41.     else if (n < 1000)
  42.     {
  43.         strcat(str, digits[n / 100]);
              ^
  44.         strcat(str, " Hundred");
  45.         if (n % 100 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  36.         {
  37.             strcat(str, " ");
  38.             strcat(str, digits[n % 10]);
                  ^
  39.         }
  40.     }

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  28.     if (n < 20)
  29.     {
  30.         strcat(str, digits[n]);
              ^
  31.     }
  32.     else if (n < 100)

Error: Buffer Overrun L2   Offset: [0, 7] Size: 1.
 Example: 
  46.         {
  47.             strcat(str, " ");
  48.             strcat(str, tens[(n % 100) / 10]);
                  ^
  49.             if (n % 10 != 0)
  50.             {

Error: Buffer Overrun L2   Offset: [0, 7] Size: 1.
 Example: 
  32.     else if (n < 100)
  33.     {
  34.         strcat(str, tens[n / 10]);
              ^
  35.         if (n % 10 != 0)
  36.         {


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
            strcat(str, " ");
            strcat(str, tens[(n % 100) / 10]);
            if (n % 10 != 0)
            {
                strcat(str, " ");
                strcat(str, digits[n % 10]);
            }
        }
    }
    else if (n < 10000)
    {
        strcat(str, digits[n / 1000]);
        strcat(str, " Thousand");
        if (n % 1000 != 0)
        {
            strcat(str, " ");
            strcat(str, digits[(n % 1000) / 100]);
            strcat(str, " Hundred");
            if (n % 100 != 0)
            {
                strcat(str, " ");
                strcat(str, tens[(n % 100) / 10]);
                if (n % 10 != 0)
                {
                    strcat(str, " ");
                    strcat(str, digits[n % 10]);
                }
            }
        }
    }
}