#include <stdio.h>

void ft_ft(int *nbr);

void ft_ft(int *nbr)
{
	*nbr = 42;
}

int main()
{
	int num = 10;
	printf("%d", num);
	ft_ft(&num);
	printf("%d", num);
	return (0);
}
