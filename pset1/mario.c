#include <stdio.h>
#include <cs50.h>



void print_spaces(threshold)
{
    for (int i = 1; i < threshold; i++)
    {
        printf(" ");
    }
    return;

}
void print_hashes(repeat_times)
{
    for (int i = 0; i <= repeat_times; i++)
    {
        printf("#");
    }
    return;

}

void print_left_hashes(step_lenght, threshold)
{
    print_spaces(threshold);
    print_hashes(step_lenght);
    printf("  ");
    return;

}

void print_right_hashes(step_lenght)
{
    print_hashes(step_lenght);
    printf("\n");
    return;
}

void print_pyramid_step(step_lenght, threshold)
{
    print_left_hashes(step_lenght, threshold);
    print_right_hashes(step_lenght);
        
    return;
}

void print_pyramid(height)
{
    int threshold = height;
    for (int step_lenght = 0; step_lenght < height; step_lenght++)
    {
        print_pyramid_step(step_lenght, threshold);
        threshold--;
    }
    return;
}

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    print_pyramid(height);
    return 0;
}
