#include <unistd.h>

void print_number(int num)
{
    int _Idx;
    int BUFFER[11];

    _Idx = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return ;
    }
    while (num > 0)
    {
        BUFFER[_Idx] = (num % 10) + '0';
        num /= 10;
        _Idx++;
    }
    while (_Idx > 0)
    {
        write(1, &BUFFER[--_Idx], 1);
    }
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        write (1, "0", 1);
        write (1, "\n", 1);
        return (0);
    }
    if (argc > 1)
    {
        argc -= 1;
        print_number(argc);
        write (1, "\n", 1);
        return (0);
    }

    return (0);
}