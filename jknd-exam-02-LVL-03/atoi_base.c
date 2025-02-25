#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_a_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_valid_lowercase(char c)
{
    return (c >= 'a' && c <= 'f');
}

int is_valid_uppercase(char c)
{
    return (c >= 'A' && c <= 'F');
}

int	ft_atoi_base(const char *str, int str_base)
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
        if (is_a_digit(*str))
            digit = *str - '0';
        else if (is_valid_lowercase(*str))
            digit = *str - 'a' + 10;
        else if (is_valid_uppercase(*str))
            digit = *str - 'A' + 10;
        else
            break;
        if (digit >= str_base)
            break;
        result = result * str_base + digit;
        str++;
    }
    return (result * sign);
}

int main(void)
{
    printf("%d", ft_atoi_base("1A", 16));
    return (0);
}
