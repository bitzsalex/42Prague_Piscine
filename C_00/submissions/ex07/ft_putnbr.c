/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:34:01 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/10 17:34:03 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int num);

void	ft_putnbr(int num)
{
	char	printed_char;
	char	number_digits[12];
	int		counter;

	printed_char = '\0';
	counter = 0;
	if (num < 0)
	{
		printed_char = '-';
		num *= -1;
		write(1, &printed_char, 1);
	}
	while (num > 0)
	{
		number_digits[counter] = (num % 10) + '0';
		num = num / 10;
		counter++;
	}
	while (--counter >= 0)
		write(1, (number_digits + counter), 1);
}
