/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 05:30:24 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 05:30:27 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int num);
void	print_char(char ch);

void	print_char(char ch)
{
	write(1, &ch, 1);
}

void	ft_putnbr(int num)
{
	unsigned int	unum;

	if (num == 0)
		print_char('0');
	else
	{
		unum = num;
		if (num < 0)
		{
			unum = num * -1;
			print_char('-');
		}
		if ((unum / 10) != 0)
			ft_putnbr(unum / 10);
		print_char((unum % 10) + '0');
	}
}
