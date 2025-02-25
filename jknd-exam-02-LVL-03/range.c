#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int get_total_size(int start, int end)
{
    int _Size;

    _Size = 0;
    while (start <= end)
    {
        start++;
        _Size++;
    }
    return (_Size);
}

// ft_range Using Malloc

int     *ft_range(int start, int end)
{
    int _size = get_total_size(start, end);
    int *array;
    int _idX;

    _idX = 0;
    array = malloc(_size *sizeof(int));
    if (!array)
    {
        return (NULL);
    }
    printf("Check Point\n");
    printf("---------------------------------------------------\n");
    while (start <= end && _idX < _size)
    {
        array[_idX] = start++;
        printf("TMP_VAL in Array : %d | TMP_VAL in START %d\n", array[_idX], start);
        _idX++;
    }
    printf("End Check\n");
    printf("---------------------------------------------------\n");
    return (array);
}

/*
int main(void)
{
    int size = get_total_size(1, 3);
    int *array = ft_range(1, 3);
    int index = 0;
    while (index < size)
    {
        printf("Index : %d  | Value %d\n", index, array[index]);
        index++;
    }
    free(array);
    return (0);
}
    */