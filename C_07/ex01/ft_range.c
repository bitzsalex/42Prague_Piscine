/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:25:44 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/15 11:25:47 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	itr;
	int	diff;

	if (max > min)
	{
		diff = max - min;
		itr = 0;
		ptr = malloc(diff * sizeof(int));
		if (ptr != NULL)
		{
			while (min < max)
			{
				ptr[itr] = min;
				min++;
				itr++;
			}
		}
	}
	return (ptr);
}
