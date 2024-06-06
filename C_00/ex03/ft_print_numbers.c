#include <unistd.h>

void ft_print_numbers();

void ft_print_numbers() {
    int iterator = '0';

    while (iterator <= '9') {
        write(1, &iterator, 1);
        iterator++;
    }
}

int main() {
    ft_print_numbers();
    return 0;
}