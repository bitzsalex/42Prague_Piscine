/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:31:44 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/27 11:31:46 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_digit_value(char *base, char ch)
{
	int	itr;

	itr = 0;
	while (*(base + itr) != '\0')
	{
		if (*(base + itr) == ch)
			return (itr);
		itr++;
	}
	return (-1);
}

int	get_power(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

// 34 here because the max bit size for int plus 2
char	*decimal_to_any(
		unsigned int nbr, char *base, int base_length, int *length)
{
	char	*result;

	*length = 0;
	result = (char *)malloc(sizeof(char) * 34);
	if (result != NULL)
	{
		while (nbr != 0)
		{
			result[*length] = base[nbr % base_length];
			nbr /= base_length;
			(*length)++;
		}
		result[*length] = '\0';
	}
	return (result);
}

unsigned int	any_to_decimal(char *nbr, char *base, int legnth)
{
	int				digits;
	int				itr;
	unsigned int	result;

	result = 0;
	digits = 0;
	while (nbr[digits] != '\0'
		&& get_digit_value(base, nbr[digits]) != -1)
		digits++;
	itr = 0;
	while (itr < digits)
	{
		result += get_digit_value(base, nbr[itr])
			* get_power(legnth, (digits - itr - 1));
		itr++;
	}
	return (result);
}

char	*copy_result(char *middleware, int length, int sign)
{
	int		itr;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (length + sign + 1));
	if (ptr != NULL)
	{
		itr = 0;
		if (sign)
			ptr[0] = '-';
		while (--length >= 0)
		{
			ptr[itr + sign] = middleware[length];
			itr++;
		}
		ptr[itr + sign] = '\0';
	}
	free(middleware);
	return (ptr);
}
