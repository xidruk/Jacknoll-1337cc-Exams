#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int is_valid_spl(char c)
{
    return (c == ' ');
}

void display_epur_str(char *data)
{
    if (!data)
    {
        write(1, "\n", 1);
        return ;
    }
    while (is_valid_spl(*data))
    {
        data++;
    }
    
    while (*data)
    {
        if (!is_valid_spl(*data))
        {
            write (1, data, 1);
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
        write (1, "\n", 1);
        return (1);
    }
    display_epur_str(argv[1]);
    return (0);
}
