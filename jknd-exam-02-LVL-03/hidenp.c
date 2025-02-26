#include <unistd.h>

void display_hiden(char *f_str, char *s_str)
{
    if (*f_str == '\0' && *s_str == '\0')
    {
        write (1, "1", 1);
        return ;
    }
    while (*s_str)
    {
        if (*f_str == *s_str)
            f_str++;
        if (*f_str == '\0')
        {
            write (1, "1", 1);
            return ;
        }
        s_str++;
    }
    write (1, "0", 1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (1);
    }
    display_hiden(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}