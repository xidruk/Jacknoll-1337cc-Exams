#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// is a valid hex sequence

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_lower_case_hexsec(char c)
{
    return (c >= 'a' && c <= 'f');
}

int is_upper_case_hexsec(char c)
{
    return (c >= 'A' && c <= 'F');
}

int atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int result = 0;
    int digit;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        if (is_digit(*str))
            digit = *str - '0';
        else if (is_lower_case_hexsec(*str))
            digit = *str - 'a' + 10;
        else if (is_upper_case_hexsec(*str))
            digit = *str - 'A' + 10;
        else 
            break;
        if (digit >= str_base)
            break;
        result = result * str_base + digit;
        str++;
    }
    return result * sign;
}
