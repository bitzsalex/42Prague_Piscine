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

char	*clean_front(char *str, int *sign)
{
	char	*ptr;
	int		negatives;

	ptr = str;
	negatives = 0;
	while (*ptr != '\0')
	{
		if (!(*ptr == ' ' || *ptr == '-' || *ptr == '+')
			|| (ptr != str && *ptr == ' '
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
