List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  52.     else if (n < 10000)
  53.     {
  54.         strcat(str, digits[n/1000]);
              ^
  55.         strcat(str, " Thousand");
  56.         if (n % 1000 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  42.     else if (n < 1000)
  43.     {
  44.         strcat(str, digits[n/100]);
              ^
  45.         strcat(str, " Hundred");
  46.         if (n % 100 != 0)

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  37.         {
  38.             strcat(str, " ");
  39.             strcat(str, digits[n % 10]);
                  ^
  40.         }
  41.     }

Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  29.     if (n < 20)
  30.     {
  31.         strcat(str, digits[n]);
              ^
  32.     }
  33.     else if (n < 100)

Error: Buffer Overrun L2   Offset: [0, 7] Size: 1.
 Example: 
  33.     else if (n < 100)
  34.     {
  35.         strcat(str, tens[n/10]);
              ^
  36.         if (n % 10 != 0)
  37.         {


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
        strcat(str, tens[n/10]);
        if (n % 10 != 0)
        {
            strcat(str, " ");
            strcat(str, digits[n % 10]);
        }
    }
    else if (n < 1000)
    {
        strcat(str, digits[n/100]);
        strcat(str, " Hundred");
        if (n % 100 != 0)
        {
            strcat(str, " ");
            int_to_string(n % 100, str);
        }
    }
    else if (n < 10000)
    {
        strcat(str, digits[n/1000]);
        strcat(str, " Thousand");
        if (n % 1000 != 0)
        {
            strcat(str, " ");
            int_to_string(n % 1000, str);
        }
    }
}