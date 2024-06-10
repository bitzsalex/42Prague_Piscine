#include <unistd.h>

void ft_print_comb(void);
void print_comb(int outer, int inner, int deep_inner);

void print_comb(int outer, int inner, int deep_inner)
{
    char separator[] = ", ";

    // initialize the string
    char str[3] = {outer + '0', inner + '0', deep_inner + '0'};
    write(1, str, 3);
    
    // print separator if we are not at the end
    if (!(outer == 7 && deep_inner == 9))
        write(1, separator, 2);
}

void ft_print_comb(void)
{
    int outer = 0, inner, deep_inner;

    while (outer <= 7)
    {
        inner = outer + 1;

        while (inner <= 8)
        {
            deep_inner = inner + 1;

            while (deep_inner <= 9)
            {
                print_comb(outer, inner, deep_inner);
                deep_inner++;
            }

            inner++;
        }

        outer++;
    }
}

int main()
{
    ft_print_comb();
    return 0;
}