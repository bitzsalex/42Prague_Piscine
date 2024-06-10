#include <unistd.h>

void ft_print_comb2(void);
void print_comb(int num1, int num2);

void print_comb(int num1, int num2) {
    int tens1 = num1 / 10, tens2 = num2 / 10;
    int ones1 = num1 % 10, ones2 = num2 % 10;
    char str[] = {
        (tens1 ? tens1 : 0) + '0', ones1 + '0', ' ',
        (tens2 ? tens2 : 0) + '0', ones2 + '0'
    };
    write(1, str, 5);
}

void ft_print_comb2(void) {
    int outer = 0, inner, size;
    char separater[] = ", ";

    // go until 98
    while (outer < 99) {
        // add by 
        inner = outer + 1;

        while (inner <= 99) {
            print_comb(outer, inner);
            if (!(outer == 98 && inner == 99))
                write(1, separater, 2);

            inner++;
        }
        outer++;
    }
}

int main() {
    ft_print_comb2();
    return 0;
}