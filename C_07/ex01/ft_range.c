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

	ptr = NULL;
	if (max > min)
	{
		diff = max - min;
		if (diff < 0)
			diff *= -1;
		itr = 0;
		ptr = malloc(diff);
		while (min < max)
		{
			ptr[itr] = min;
			min++;
			itr++;
		}
	}
	return (ptr);
}
