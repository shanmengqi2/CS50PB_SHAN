#include "cs50.h"
#include <stdio.h>

int main(void)
{
    int change;
    int current_total = 0;
    int coin_count = 0;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    while (current_total < change)
    {
        if ((current_total + 25) <= change)
        {
            current_total = current_total + 25;
            coin_count++;
        }
        else if ((current_total + 10) <= change)
        {
            current_total = current_total + 10;
            coin_count++;
        }
        else if ((current_total + 5) <= change)
        {
            current_total = current_total + 5;
            coin_count++;
        }
        else if ((current_total + 1) <= change)
        {
            current_total = current_total + 1;
            coin_count++;
        }
    }
    printf("%i\n", coin_count);
}
