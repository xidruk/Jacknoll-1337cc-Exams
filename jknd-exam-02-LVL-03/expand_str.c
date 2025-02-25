#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int is_valid_spl(char c)
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
    while (*data && is_valid_spl(*data))
    {
        data++;
    }
    while (*data)
    {
        if (!is_valid_spl(*data))
        {
            write(1, data, 1);
            data++;
        }
        else
        {
            while (*data && is_valid_spl(*data))
            {
                data++;
            }
            if (*data)
            {
                write (1, "   ", 3);
            }
        }
    }
    write (1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "'\n", 1);
        return (1);
    }
    expand_string(argv[1]);
    return (0);
}
