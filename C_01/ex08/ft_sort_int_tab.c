#include <stdio.h>

void swap(int *a, int *b);
void ft_sort_int_tab(int *tab, int size);

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_sort_int_tab(int *tab, int size)
{
	int outer;
	int inner;

	outer = 1;
	while (outer < size)
	{
		inner = outer;
		while (inner > 0 && *(tab + inner) < *(tab + inner - 1))
		{
			swap(tab + inner, tab + inner - 1);
			inner--;
		}
		outer++;
	}
}

int main()
{
	// int arr[] = {27, 63, 12, 85, 44, 9, 78, 56, 34, 91};
	int arr[] = {67, 35, 90, 77, 55, 26};
	int size = sizeof(arr) / sizeof(arr[0]);
	ft_sort_int_tab(arr, size);
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}
