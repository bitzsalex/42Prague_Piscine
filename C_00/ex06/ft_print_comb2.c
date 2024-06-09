#include <unistd.h>

void ft_print_comb2(void);

void ft_print_comb2(void) {
    for (int i = 0; i <= 1; i++) {
        int digits = 1;

        while (digits <= 3) {
            int counter = 1;
            int size = digits == 1 ? 1 : (10 - digits) * (digits - 1);
            
            while (counter <= size) {
                 for (int j = 0; j <= 9; j++) {
                    char str[] = {i + '0', digits + '0', counter + '0', j + '0', ', ', ' '};
                    write(1, str, 5);
                }
                counter++;
            }
            digits++;
        }
    }
}