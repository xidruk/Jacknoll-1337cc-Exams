#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int type_convertor(char *data)
{
    int _Res;

    _Res = 0;
    while (*data)
    {
        _Res = _Res * 10 + (*data - '0');
        data++;
    }
    // printf("%d", _Res);
    return _Res;
}

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

int is_prime(int num)
{
    if (num <= 1)
    {
        return (0);
    }
    if (num <= 3)
    {
        return (1);
    }
    if (num % 2 == 0 || num % 3 == 0)
    {
        return (0);
    }
    int i = 5;
    while (i * i <= num)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return (0);
        i+= 6;
    }
    return (1);
}

void collect_primes(int num)
{
    int _Prime_collector;

    _Prime_collector = 0;
    while (num > 0)
    {
        if (is_prime(num))
        {
            _Prime_collector += num;
        }
        num--;
    }
    print_number(_Prime_collector);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write (1, "\n", 1);
        return (1);
    }
    int res = type_convertor(argv[1]);
    // print_number(res);
    collect_primes(res);
    write(1, "\n", 1);
    return (0);
}