/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:34:11 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/10 17:34:15 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_last_comb(char *buffer, int end);
void	ft_print_combn(int n);
void	generate_combination(char *buffer, int index, int start, int end);

int	is_last_comb(char *buffer, int end)
{
	int		itr;
	char	last_digit;

	itr = 1;
	last_digit = (10 - end) + '0';
	while (itr < end)
	{
		if (buffer[itr] != (last_digit + itr))
			return (0);
		itr++;
	}
	return (1);
}

void	print_combination(char *buffer, int end)
{
	char	separator[2];
	char	last_digit;

	separator[0] = ',';
	separator[1] = ' ';
	last_digit = (10 - end) + '0';
	write(1, buffer, end);
	if (!((buffer[0] == last_digit) && is_last_comb(buffer, end)))
		write(1, separator, 2);
}

void	generate_combination(char *buffer, int index, int start, int end)
{
	int	itr;

	itr = start;
	if (index == end)
	{
		print_combination(buffer, end);
		return ;
	}
	while (itr <= 9)
	{
		buffer[index] = '0' + itr;
		generate_combination(buffer, index + 1, itr + 1, end);
		itr++;
	}
}

void	ft_print_combn(int n)
{
	char	buffer[10];

	generate_combination(buffer, 0, 0, n);
}
