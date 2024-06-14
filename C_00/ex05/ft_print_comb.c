/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:33:33 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/10 17:33:38 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	print_comb(int outer, int inner, int deep_inner);

void	print_comb(int outer, int inner, int deep_inner)
{
	char	separator[2];
	char	str[3];

	separator[0] = ',';
	separator[1] = ' ';
	str[0] = outer + '0';
	str[1] = inner + '0';
	str[2] = deep_inner + '0';
	write(1, str, 3);
	if (!(outer == 7 && deep_inner == 9))
		write(1, separator, 2);
}

void	ft_print_comb(void)
{
	int	outer;
	int	inner;
	int	deep_inner;

	outer = 0;
	while (outer <= 7)
	{
		inner = outer + 1;
		while (inner <= 8)
		{
			deep_inner = inner + 1;
			while (deep_inner <= 9)
			{
				print_comb(outer, inner, deep_inner);
				deep_inner++;
			}
			inner++;
		}
		outer++;
	}
}
