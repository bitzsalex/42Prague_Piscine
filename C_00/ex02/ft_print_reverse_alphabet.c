#include <unistd.h>

void ft_print_reverse_alphabet(void);

void ft_print_reverse_alphabet(void)
{
    // the same ASCII conversion will happen
    // as we saw in the previous exercise
    int iterator = 'z';

    while (iterator >= 'a')
    {
        write(1, &iterator, 1);
        iterator--;
    }
}

int main()
{
    ft_print_reverse_alphabet();
    return 0;
}