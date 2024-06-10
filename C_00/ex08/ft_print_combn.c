#include <unistd.h>
#include <stdio.h>

int g_digit_count = 10;

int is_last_comb(char *buffer, int end);
void ft_print_combn(int n);
void generate_combination(char *buffer, int index, int start, int end);

int is_last_comb(char *buffer, int end)
{
    int itr = 1;
    char last_digit = (g_digit_count - end) + '0';

    while (itr < end)
    {
        if (buffer[itr] != (last_digit + itr))
            return 0;

        itr++;
    }

    return 1;
}

void print_combination(char *buffer, int end)
{
    int itr = 0;
    char separator[] = ", ";
    char last_digit = (g_digit_count - end) + '0';
    write(1, buffer, end);

    if (!((buffer[0] == last_digit) && is_last_comb(buffer, end)))
        write(1, separator, 2);
}

void generate_combination(char *buffer, int index, int start, int end)
{
    if (index == end)
    {
        print_combination(buffer, end);
        return;
    }

    for (int i = start; i <= 9; i++)
    {
        buffer[index] = '0' + i;
        generate_combination(buffer, index + 1, i + 1, end);
    }
}

void ft_print_combn(int n)
{
    char buffer[g_digit_count];
    generate_combination(buffer, 0, 0, n);
}

int main()
{
    ft_print_combn(2);
    return 0;
}