#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 99
#define NUM_DIGITS 20
#define NUM_TENS 10

void int_to_string(int n, char *str);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    char str[MAX_STR_LEN+1] = ""; // initialize to empty string
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

    char *digits[NUM_DIGITS] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",
                      "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[NUM_TENS] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (n < 20)
    {
#ifdef _MSC_VER
        strncpy_s(str, MAX_STR_LEN+1, digits[n], strlen(digits[n])); // use safe string copy function
#else
        strncpy(str, digits[n], MAX_STR_LEN+1);
#endif
    }
    else if (n < 100)
    {
        strncpy(str, tens[n / 10], MAX_STR_LEN+1);
        if (n % 10!= 0)
        {
            strncat(str, "-", MAX_STR_LEN-strlen(str));
            strncat(str, digits[n % 10], MAX_STR_LEN-strlen(str));
        }
    }
    else
    {
        strncpy(str, digits[n / 100], MAX_STR_LEN+1);
        strncat(str, " Hundred", MAX_STR_LEN-strlen(str));
        if (n % 100!= 0)
        {
            strncat(str, " And ", MAX_STR_LEN-strlen(str));
            int_to_string(n % 100, str);
        }
    }
}