/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:53:00 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/15 11:53:03 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	itr;

	itr = 0;
	ptr = malloc((max - min) * sizeof(int));
	if (ptr != NULL)
	{
		while (min < max)
		{
			ptr[itr] = min;
			min++;
			itr++;
		}
	}
	return (ptr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	return (max - min);
}
