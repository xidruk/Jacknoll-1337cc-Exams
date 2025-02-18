#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_a_valid_separator(char c)
{
    return (c == ' ' || c == '\t');
}

void display_only_one_space(char *data)
{
    if (!data)
    {
        write(1, "\n", 1);
        return ;
    }
    while (*data)
    {
        if (!is_a_valid_separator(*data))
        {
            write(1, data, 1);
            data++;
        }
        else
        {
            while (*data && is_a_valid_separator(*data))
            {
                data++;
            }
            if (*data)
            {
                write(1, " ", 1);
            }
        }
    }
    write(1, "\n", 1);
}


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    display_only_one_space(argv[1]);
    return (0);
}
