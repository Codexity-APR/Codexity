List of vulnerabilities detected: 
Error: Buffer Overrun L1   Offset added: 99 Size: 4 by call to `int_to_string`.
 Example: 
  10.     scanf("%d", &n);
  11.     char str[100] = "";
  12.     int_to_string(n, str, sizeof(str));
          ^
  13.     printf("%d in words is: %s\n", n, str);
  14.     return 0;


#include <stdio.h>
#include <string.h>
void int_to_string(int n, char *str, size_t size);
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    char str[100] = "";
    int_to_string(n, str, sizeof(str));
    printf("%d in words is: %s\n", n, str);
    return 0;
}
void int_to_string(int n, char *str, size_t size)
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
        strncpy(str, digits[n], size - 1);
        str[size - 1] = '\0';
    }
    else if (n < 100)
    {
        snprintf(str, size, "%s%s", tens[n / 10], digits[n % 10]);
    }
    else if (n < 1000)
    {
        snprintf(str, size, "%sHundred %s%s", digits[n / 100], tens[(n % 100) / 10], digits[(n % 100) % 10]);
    }
    else if (n < 10000)
    {
        snprintf(str, size, "%sThousand %sHundred %s%s", digits[n / 1000], digits[(n % 1000) / 100], tens[((n % 1000) % 100) / 10], digits[((n % 1000) % 100) % 10]);
    }
}