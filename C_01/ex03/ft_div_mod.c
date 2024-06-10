#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main()
{
	int a = 23, b = 4, div = 0, mod = 0;
	printf("before calling div=%d and mod=%d\n", div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("after calling div=%d and mod=%d\n", div, mod);
}
