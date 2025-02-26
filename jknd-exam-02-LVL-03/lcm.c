#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct
{
    unsigned int base_value;
    unsigned int old_value;
} __chin_STATE;


void get_next_chain_value(unsigned *num , __chin_STATE *state)
{
    if (state->base_value == 0)
        state->base_value = *num;
    
    state->old_value += state->base_value;
    *num = state->old_value;
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
    {
        return (0);
    }
    unsigned int x = a;
    __chin_STATE state_x = {0, 0};
    unsigned int time_out;
    unsigned int tracker = 0;

    time_out = UINT_MAX; // UINT_MAX value 4294967295
    while (time_out > 0)
    {
        get_next_chain_value(&x, &state_x);
        if (x % b == 0)
        {
            tracker = x;
            break;
        }
        time_out--;
    }
    if (tracker == 0)
    {
        printf("Time Out ...\n");
        return (tracker);
    }
    return (tracker);
}

int main(void)
{

    unsigned int x = 2;
    unsigned int y = 3;
    unsigned int tracker = lcm(x, y);
    printf("Matched Value : %u", tracker);

    return (0);
}