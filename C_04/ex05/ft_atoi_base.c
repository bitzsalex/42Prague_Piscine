/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 07:49:53 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 07:49:55 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);
void	get_base_info(char *base, int *is_valid, int *length);
void	putnbr(int num, char *base, int length);
char	*clean_front(char *str, int *sign);

char	*clean_front(char *str, int *sign)
{
	char	*ptr;
	int		negatives;

	ptr = str;
	negatives = 0;
	while (*ptr != '\0'
		&& (*ptr <= ' ' || *ptr > '~' || *ptr == '-' || *ptr == '+'))
	{
		if ((ptr != str && (*ptr <= ' ' || *ptr > '~')
				&& (*(ptr - 1) == '-' || *(ptr - 1) == '+')))
			break ;
		if (*ptr == '-')
			negatives++;
		ptr++;
	}
	if (negatives % 2 == 1)
		*sign = -1;
	return (ptr);
}

void	get_base_info(char *base, int *is_invalid, int *length)
{
	int	itrj;

	*is_invalid = 0;
	*length = 0;
	while (base[*length] != '\0' && *is_invalid == 0)
	{
		if (!((base[*length] >= 'a' && base[*length] <= 'z')
				|| (base[*length] >= 'A' && base[*length] <= 'Z')
				|| (base[*length] >= '0' && base[*length] <= '9')))
			*is_invalid = 1;
		else
		{
			itrj = *length + 1;
			while (base[itrj] != '\0' && *is_invalid == 0)
			{
				if (base[*length] == base[itrj])
					*is_invalid = 1;
				itrj++;
			}
		}
		*length = *length + 1;
	}
}

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

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	result;
	int				is_base_invalid;
	int				length;
	int				multiplier;
	int				digits;

	get_base_info(base, &is_base_invalid, &length);
	if (is_base_invalid || length <= 1)
		return (0);
	result = 0;
	digits = 0;
	multiplier = 1;
	str = clean_front(str, &multiplier);
	while (str[digits] != '\0' && get_digit_value(base, str[digits]) != -1)
		digits++;
	while (digits > 0)
		result += get_digit_value(base, *str++) * get_power(length, --digits);
	return ((int)(result * multiplier));
}
