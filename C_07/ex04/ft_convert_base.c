/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:31:16 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/27 11:31:27 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int				get_power(int base, int power);
int				get_digit_value(char *base, char ch);
char			*decimal_to_any(
					unsigned int nbr, char *base, int base_length, int *length);
char			*copy_result(char *middleware, int length, int sign);
unsigned int	any_to_decimal(char *nbr, char *base, int legnth);

int	is_space(char ch)
{
	if (ch <= ' ' || ch > '~')
		return (1);
	return (0);
}

char	*clean_front(char *str, int *sign)
{
	char	*ptr;
	int		negatives;
	int		is_ptr_space;

	*sign = 0;
	ptr = str;
	negatives = 0;
	while (*ptr != '\0')
	{
		is_ptr_space = is_space(*ptr);
		if (!(is_ptr_space || *ptr == '-' || *ptr == '+')
			|| (ptr != str && is_ptr_space && !is_space(*(ptr - 1))))
			break ;
		if (*ptr == '-')
			negatives++;
		ptr++;
	}
	if (negatives % 2 == 1)
		*sign = 1;
	return (ptr);
}

int	get_base_length(char *base)
{
	int	itrj;
	int	length;

	length = 0;
	while (base[length] != '\0')
	{
		if (!((base[length] >= 'a' && base[length] <= 'z')
				|| (base[length] >= 'A' && base[length] <= 'Z')
				|| (base[length] >= '0' && base[length] <= '9')))
			return (-1);
		else
		{
			itrj = length + 1;
			while (base[itrj] != '\0')
			{
				if (base[length] == base[itrj])
					return (-1);
				itrj++;
			}
		}
		length = length + 1;
	}
	return (length);
}

char	*atoi_base(char *nbr, char *bases[2], int lengths[2])
{
	char			*result;
	char			*middleware;
	int				sign;
	int				length;
	unsigned int	number;

	sign = 0;
	result = NULL;
	nbr = clean_front(nbr, &sign);
	number = any_to_decimal(nbr, bases[0], lengths[0]);
	if (number <= (((unsigned int)INT_MAX) + 1))
	{
		middleware = decimal_to_any(number, bases[1], lengths[1], &length);
		result = copy_result(middleware, length, sign);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_length;
	int		base_to_length;
	int		lengths[2];
	char	*bases[2];
	char	*result;

	result = NULL;
	base_from_length = get_base_length(base_from);
	base_to_length = get_base_length(base_to);
	if (base_from_length > 1 && base_to_length > 1)
	{
		bases[0] = base_from;
		bases[1] = base_to;
		lengths[0] = base_from_length;
		lengths[1] = base_to_length;
		result = atoi_base(nbr, bases, lengths);
	}
	return (result);
}

// int main(void)
// {
// 	char *nbr = "42";
// 	char *base_from = "0123456789";
// 	char *base_to = "01";
// 	// char *nbr = "-10000000000000000000000000000000";
// 	// char *base_from = "01";
// 	// char *base_to = "0123456789";
// 	printf("%s\n", ft_convert_base(nbr, base_from, base_to));
// 	return (0);
// }
