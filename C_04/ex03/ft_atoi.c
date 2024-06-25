/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 06:25:39 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 06:29:23 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*clean_front(char *str, int *sign);
int		ft_atoi(char *str);

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
		*sign = -1;
	return (ptr);
}

// unsigned int because of -2,147,483,648
int	ft_atoi(char *str)
{
	unsigned int	result;
	int				multiplier;

	result = 0;
	multiplier = 1;
	str = clean_front(str, &multiplier);
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int)(result * multiplier));
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi("   \t   ---++175074925"));
	return (0);
}
