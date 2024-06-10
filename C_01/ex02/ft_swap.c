#include <stdio.h>

void ft_swap(int *a, int *b);

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int a;
	int b;

	a = 10;
	b = 66;
	ft_swap(&a, &b);
	printf("after swap a=%d and b=%d\n", a, b);
}
