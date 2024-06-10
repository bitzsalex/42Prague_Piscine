#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

void ft_ultimate_div_mod(int *a, int *b)
{
	int tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}

int main()
{
	int a = 23, b = 4;
	printf("Before calling a=%d and b=%d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("after calling a=%d and b=%d\n", a, b);
}
