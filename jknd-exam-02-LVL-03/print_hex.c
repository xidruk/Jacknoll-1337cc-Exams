#include "unistd.h"



unsigned int type_convertor(char *data)
{
    unsigned int _Res;

    _Res = 0;
    while (*data)
    {
        _Res = _Res * 10 + (*data - '0');
        data++;
    }
    // printf("%d", _Res);
    return (_Res);
}

void print_hex(unsigned int n)
{
    char *hex = "0123456789abcdef";
    int i = 0;
    char buffer[9];

    if (n == 0)
    {
        write (1, "0", 1);
        return ;
    }
    while (n > 0)
    {
        buffer[i++] = hex[n % 16];
        n /= 16;
    }
    while (i--)
    {
        write(1, &buffer[i], 1);
    }
}


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write (1, "\n", 1);
        return (1);
    }
    print_hex(type_convertor(argv[1]));
    write(1, "\n", 1);
    return (0);
}