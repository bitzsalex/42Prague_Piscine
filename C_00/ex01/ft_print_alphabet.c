#include <unistd.h>

void ft_print_alphabet(void);

void ft_print_alphabet(void) {
    // the data type of int here cast the character
    // to ASCII equivalent of the character
    int iterator = 'a';

    // the same ASCII conversion will happen on comparison as well
    while (iterator <= 'z') {
        write(1, &iterator, 1);
        iterator++;
    }
}

int main() {
    ft_print_alphabet();
    return 0;
}