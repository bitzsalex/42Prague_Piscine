/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:14:46 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/11 13:14:49 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	last_index;
	int	half;
	int	counter;
	int	tmp;

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

// int	main(void)
// {
// 	int	arr[] = {67, 35, 90, 77, 55, 26};
// 	int	size;
// 	int	i;

// 	i = 0;
// 	size = sizeof(arr) / sizeof(arr[0]);
// 	ft_rev_int_tab(arr, size);
// 	while (i < size)
// 		printf("%d\n", arr[i++]);
// }
