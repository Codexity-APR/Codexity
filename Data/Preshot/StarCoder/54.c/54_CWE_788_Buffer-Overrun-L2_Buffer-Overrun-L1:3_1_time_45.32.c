#include <stdio.h>
#include <string.h>

void int_to_string(int n, char *str);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    char str[100] = {0};
    int_to_string(n, str);
    printf("%d in words is: %s\n", n, str);
    return 0;
}

void int_to_string(int n, char *str)
{
    if (n < 0 || n > 9999 || str == NULL)
    {
        return;
    }

    char *digits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",
                      "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (n < 20)
    {
#ifdef _MSC_VER
        strncpy_s(str, 100, digits[n], _TRUNCATE);
#else
        strncpy(str, digits[n], 100);
#endif
    }
    else if (n < 100)
    {
        strncpy(str, tens[n / 10], 100);
        if (n % 10 != 0)
        {
            strncat(str, "-", 100 - strlen(str));
            strncat(str, digits[n % 10], 100 - strlen(str));
        }
    }
    else
    {
        strncpy(str, digits[n / 100], 100);
        strncat(str, " Hundred", 100 - strlen(str));
        if (n % 100 != 0)
        {
            strncat(str, " And ", 100 - strlen(str));
            int_to_string(n % 100, str + strlen(str));
        }
    }
}