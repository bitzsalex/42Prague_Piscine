#include <unistd.h>

void ft_print_comb(void);

void ft_print_comb(void) {
    char separator[] = ", ";
    int outer = 0, inner, deepInner;

    while (outer <= 7) {
        inner = outer + 1;
        
        while (inner <= 8) {
            deepInner = inner + 1;

            while (deepInner <= 9) {
                // initialize the string
                char str[3] = {outer + '0', inner + '0', deepInner + '0'};
                write(1, str, 3);
                // print separator if we are not at the end
                if (!(outer == 7 && deepInner == 9))
                    write(1, separator, 2);

                deepInner++;
            }
            inner++;
        }
        outer++;
    }
}

int main() {
    ft_print_comb();
    return 0;
}