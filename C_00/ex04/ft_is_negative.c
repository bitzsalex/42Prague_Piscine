#include <unistd.h>

void ft_is_negative(int n);

void ft_is_negative(int n) {
    char value;

    // check whether n is greater or equal to 0
    if (n >= 0) value = 'P';
    else value = 'N';
    write(1, &value, 1);
}

int main() {
    int p = 10, ng = 0, n = -10;
    ft_is_negative(p);
    ft_is_negative(ng);
    ft_is_negative(n);
    return 0;
}