#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while(start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while(end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int actual_size = start_size;
    int new_borns;
    int passed_away;
    int years;
    for(years = 0; actual_size < end_size; years++)
    {
        new_borns = actual_size / 3;
        passed_away = actual_size / 4;
        actual_size = actual_size + new_borns - passed_away;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
