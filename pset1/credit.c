#include <stdio.h>
#include <cs50.h>
#include <math.h>


int get_number_lenght(long number)
{
    int length = 0;
    while(number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_first_two_numbers(long number)
{
    int lenght = get_number_lenght(number);
    for (int i = 0; i < (lenght - 2); i++)
    {
        number /= 10;
    }
    return number;
}

bool number_has_valid_length(long card_number)
{
    int length = get_number_lenght(card_number);
    if (length >= 13 && length <= 16 && length != 14)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool first_numbers_are_correct(long card_number)
{
    int first_numbers = get_first_two_numbers(card_number);
    switch(first_numbers){
        case 4:
            break;
        case 34:
            break;
        case 37:
            break;
        case 51:
            break;
        case 52:
            break;
        case 53:
            break;
        case 54:
            break;
        case 55:
            break;
        default:
            return false;
    }
    return true;
    
}

long remove_right_numbers(long card_number, int i)
{
    int length = get_number_lenght(card_number);
    return card_number / pow(10, (length - 1) - i);
}

int remove_left_numbers(long card_number, int i)
{
    int length = get_number_lenght(card_number);
    long multiplier = (pow(10, (length  - i)));
    long left_numbers = (card_number / multiplier) * multiplier;
    return card_number - left_numbers; 
}

int get_number_by_index(long card_number,int i)
{
    int length = get_number_lenght(card_number);
    card_number = remove_right_numbers(card_number, i);
    return remove_left_numbers(card_number, i);
}

bool number_has_two_digits(number)
{
    int length = get_number_lenght(number);
    return length == 2;
}

int sum_digits(number)
{
    return number - 9;
}

int sum_every_other_number(long card_number)
{
    int sum = 0;
    int length = get_number_lenght(card_number);
    int number;
    for (int i = (length - 2); i >=0; i -= 2)
    {
       number = get_number_by_index(card_number, i);
       number *= 2;

       if (number_has_two_digits(number))
       {
           number = sum_digits(number);
       }

       sum += number;
    }
    return sum;
}

int sum_remaining_numbers(long card_number)
{
    int sum = 0;
    int length = get_number_lenght(card_number);
    int number;
    for (int i = (length - 1); i >=0; i -= 2)
    {
       number = get_number_by_index(card_number, i);
       sum += number;
    }
    return sum;
}

bool luhns_algorithm_is_valid(long card_number)
{
    int sum = sum_every_other_number(card_number);
    sum += sum_remaining_numbers(card_number);
    return sum % 10 == 0;

}

bool card_number_is_valid(long card_number)
{
    if (!number_has_valid_length(card_number))
    {
        return false;
    }
    else if(!first_numbers_are_correct(card_number))
    {
        return false;
    }
    else if (!luhns_algorithm_is_valid(card_number))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void print_card_type(long card_number)
{
    int first_numbers = get_first_two_numbers(card_number);
    if (first_numbers >= 40 && first_numbers < 50)
    {
        first_numbers /= 10;
    }
    switch(first_numbers){
        case 4:
            printf("Visa\n");
            break;
        case 34:
            printf("AMEX\n");
            break;
        case 37:
            printf("AMEX\n");
            break;
        case 51:
            printf("AMEX\n");
            break;
        case 52:
            printf("MASTERCARD\n");
            break;
        case 53:
            printf("MASTERCARD\n");
            break;
        case 54:
            printf("MASTERCARD\n");
            break;
        case 55:
            printf("MASTERCARD\n");
            break;
        default:
            break;
    }
    return;
}

int main(void)
{

    long card_number = get_long("Number: ");
    if (luhns_algorithm_is_valid(card_number))
    {
        print_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}
