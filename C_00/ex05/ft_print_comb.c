#include <unistd.h>

void ft_print_comb(void);

void ft_print_comb(void) {
    for (int i = '0'; i <= '7'; i++) {
        for (int j = i + 1; j <= '8'; j++) {
            for (int k = j + 1; k <= '9'; k++) {
                int size = i == '7' && k == '9' ? 3 : 5;
                char str[size] = {i, j, k};
                if (!(i == '7' && k == '9')) {
                    str[3] = ',';
                    str[4] = ' ';
                }
                write(1, str, size);
            }
        }
    }
}

int main() {
    ft_print_comb();
    return 0;
}