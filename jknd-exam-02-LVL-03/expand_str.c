#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_a_valid_separator(char c)
{
    return (c == ' ' || c == '\t');
}

void expand_string(char *data)
{
    if (!data)
    {
        write(1, "\n", 1);
        return ;
    }
    while (*data)
    {
        if (is_a_valid_separator(*data))
        {
            while (*data && is_a_valid_separator(*data))
            {
                data++;
            }
            if (*data)
            {
                write(1, "   ", 3);
            }
        }
        if (*data && !is_a_valid_separator(*data))
        {
            write(1, data, 1);
            data++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    expand_string(argv[1]);
    write(1, "\n", 1);
    return (0);
}
