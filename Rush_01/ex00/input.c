/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 07:01:47 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/16 07:01:49 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_are_all_numbers(char *str)
{
	int	view_count;

	view_count = 0;
	while (*str != '\0')
	{
		if (*str != ' ' && !(*str >= '0' && *str <= '9'))
			return (0);
		if (*str >= '0' && *str <= '9')
			view_count++;
		str++;
	}
	return (view_count);
}

int	ft_extract_view(char **str)
{
	int	view;

	view = 0;
	*str = ft_left_trim(*str);
	while (**str != '\0' && **str != ' ')
	{
		view = (view * 10) + (**str - '0');
		*str = *str + 1;
	}
	return (view);
}

int	*ft_extract_views(char *str, int length)
{
	int	*views;
	int	counter;

	counter = 0;
	views = malloc(sizeof(int) * length);
	if (views != NULL)
	{
		while (*str != '\0')
		{
			views[counter] = ft_extract_view(&str);
			if (views[counter] > 9)
				return (NULL);
			counter++;
		}
	}
	return (views);
}

int	ft_are_all_in_range(int *arr, int length, int max)
{
	int	itr;

	itr = 0;
	while (itr < length)
	{
		if (!(arr[itr] >= 1 && arr[itr] <= max))
			return (0);
		itr++;
	}
	return (1);
}

int	*ft_get_input_array(char *str, int *length)
{
	int	*views;
	int	*input_array;

	input_array = NULL;
	str = ft_left_trim(str);
	*length = ft_are_all_numbers(str);
	if (*length > 4 && *length % 4 == 0)
	{
		views = ft_extract_views(str, *length);
		if (views != NULL)
		{
			if (ft_are_all_in_range(views, *length, *length / 4))
				input_array = views;
		}
	}
	return (input_array);
}
