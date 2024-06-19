/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 03:32:57 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 03:33:03 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char ch);
void	ft_putstr_non_printable(char *str);

void	print_hex(char ch)
{
	char	hex[3];
	int		counter;
	int		remainder;
	int		ch_ascii;

	ch_ascii = ch;
	counter = 2;
	hex[0] = '\\';
	hex[1] = '0';
	while (ch_ascii > 0 && counter > 0)
	{
		remainder = ch_ascii % 16;
		if (remainder < 10)
			hex[counter] = remainder + '0';
		else
			hex[counter] = 'a' + (remainder - 10);
		ch_ascii /= 16;
		counter--;
	}
	write(1, hex, 3);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
			print_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}
