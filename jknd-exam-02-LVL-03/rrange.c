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
    while (end >= start && _idX < _size)
    {
        array[_idX] = end--;
        printf("TMP_VAL in Array : %d | TMP_VAL in START %d\n", array[_idX], end);
        _idX++;
    }
    printf("End Check\n");
    printf("---------------------------------------------------\n");
    return (array);
}

/*

int main(void)
{
    int size = get_total_size(-3, 3);
    int *array = ft_range(-3, 3);
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

/*

/----> Result :

Check Point
---------------------------------------------------
TMP_VAL in Array : 3 | TMP_VAL in START 2
TMP_VAL in Array : 2 | TMP_VAL in START 1
TMP_VAL in Array : 1 | TMP_VAL in START 0
TMP_VAL in Array : 0 | TMP_VAL in START -1
TMP_VAL in Array : -1 | TMP_VAL in START -2
TMP_VAL in Array : -2 | TMP_VAL in START -3
TMP_VAL in Array : -3 | TMP_VAL in START -4
End Check
---------------------------------------------------
Index : 0  | Value 3
Index : 1  | Value 2
Index : 2  | Value 1
Index : 3  | Value 0
Index : 4  | Value -1
Index : 5  | Value -2
Index : 6  | Value -3

*/