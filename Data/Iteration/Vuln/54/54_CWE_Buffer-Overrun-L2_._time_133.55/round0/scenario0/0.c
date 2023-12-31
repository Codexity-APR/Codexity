List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [3, 9] Size: 4.
 Example: 
  29.     if (n < 20)
  30.     {
  31.         strcpy(str, digits[n]);
              ^
  32.     }
  33.     else if (n < 100)


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
        sprintf(str, "%s%s", tens[n / 10], digits[n % 10]);
    }
    else if (n < 1000)
    {
        sprintf(str, "%sHundred %s%s", digits[n / 100], tens[(n % 100) / 10], digits[(n % 100) % 10]);
    }
    else if (n < 10000)
    {
        sprintf(str, "%sThousand %sHundred %s%s", digits[n / 1000], digits[(n % 1000) / 100], tens[((n % 1000) % 100) / 10], digits[((n % 1000) % 100) % 10]);
    }
}