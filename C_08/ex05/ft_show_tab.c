/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:55:35 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/26 00:55:38 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);
int		ft_length(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int num);

int	ft_length(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	ft_putstr(char *str)
{
	int	length;

	length = ft_length(str);
	write(1, str, length);
}

void	ft_putnbr(int num)
{
	char	printable;

	if ((num / 10) != 0)
		ft_putnbr(num / 10);
	printable = (num % 10) + '0';
	write(1, &printable, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (*par->str != '0')
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		par++;
	}
}
