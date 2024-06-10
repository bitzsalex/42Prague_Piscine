#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

void ft_rev_int_tab(int *tab, int size)
{
	int last_index;
	int half;
	int counter;
	int tmp;

	last_index = size - 1;
	half = size / 2;
	counter = 0;
	while (counter < half)
	{
		tmp = *(tab + counter);
		*(tab + counter) = *(tab + (last_index - counter));
		*(tab + (last_index - counter)) = tmp;
		counter++;
	}
}

int main()
{
	// int arr[] = {67};
	// int arr[] = {67, 35};
	// int arr[] = {67, 35, 90};
	int arr[] = {67, 35, 90, 26};
	// int arr[] = {67, 35, 90, 77, 55, 26};
	int size = sizeof(arr) / sizeof(arr[0]);
	ft_rev_int_tab(arr, size);
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}
