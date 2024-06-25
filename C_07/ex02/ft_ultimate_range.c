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
	int	init;

	ptr = NULL;
	if (max > min)
	{
		init = min;
		ptr = (int *)malloc((max - min) * sizeof(int));
		if (ptr != NULL)
		{
			while (min < max)
			{
				ptr[min - init] = min;
				min++;
			}
		}
	}
	return (ptr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	returnable;

	returnable = max - min;
	*range = NULL;
	if (max > min)
	{
		*range = ft_range(min, max);
		if (*range == NULL)
			returnable = -1;;
	}
	else
		returnable = 0;
	return (returnable);
}
