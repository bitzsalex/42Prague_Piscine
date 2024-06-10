#include <unistd.h>

int g_digit_count = 10;

void ft_print_combn(int n);
int are_all_next9s(int arr[], int length);
void fill_all(int arr[], int length, int init, int start_index);
void adjust_increment(int arr[], int length);

int are_all_next9s(int arr[], int length)
{
    int itr = 1;

    while (itr < length)
    {
        if (arr[itr] != 9)
            return (0);
        itr++;
    }

    return (1);
}

void fill_all(int arr[], int length, int init, int start_index)
{
    int add = init;

    while (start_index < length)
    {
        if (add > 9)
            break;

        arr[start_index] = add;
        start_index++;
        add++;
    }
}

void print_combs(int arr[], int length)
{
    int itr = 0;
    char printed_char = '\0';
    char separator[] = ", ";

    while (itr < length)
    {
        printed_char = arr[itr] + '0';
        write(1, &printed_char, 1);
        itr++;
    }

    if (!(arr[0] == (g_digit_count - length) && are_all_next9s(arr, length)))
        write(1, separator, 2);
}

void adjust_increment(int arr[], int length)
{
    int itr = length - 1;

    while (itr > 0)
    {
        if (arr[itr] < 9)
        {
            fill_all(arr, length, arr[itr] + 1, itr);
            break;
        }
        itr--;
    }
}

void ft_print_combn(int n)
{
    int outer = 0;
    int inner = 0;
    int digitCombs[g_digit_count]; // the max size

    while (outer <= (g_digit_count - n))
    {
        fill_all(digitCombs, n, outer, 0);
        print_combs(digitCombs, n);

        while (!are_all_next9s(digitCombs, n))
        {
            inner = digitCombs[n - 1] + 1;

            while (inner <= 9)
            {
                digitCombs[n - 1] = inner;
                print_combs(digitCombs, n);
                inner++;
            }

            adjust_increment(digitCombs, n);
            print_combs(digitCombs, n);
        }

        outer++;
    }
}

int main()
{
    print_all_combinations(4);
    // ft_print_combn(9);
    return 0;
}