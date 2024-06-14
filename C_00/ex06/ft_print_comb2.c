/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:33:48 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/10 17:33:52 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	print_comb(int num1, int num2);

void	print_comb(int num1, int num2)
{
	int		tens1;
	int		tens2;
	int		ones1;
	int		ones2;
	char	str[5];

	tens1 = num1 / 10;
	tens2 = num2 / 10;
	ones1 = num1 % 10;
	ones2 = num2 % 10;
	str[0] = tens1 + '0';
	str[1] = ones1 + '0';
	str[2] = ' ';
	str[3] = tens2 + '0';
	str[4] = ones2 + '0';
	write(1, str, 5);
}

void	ft_print_comb2(void)
{
	int		outer;
	int		inner;
	char	separater[2];

	separater[0] = ',';
	separater[1] = ' ';
	outer = 0;
	while (outer < 99)
	{
		inner = outer + 1;
		while (inner <= 99)
		{
			print_comb(outer, inner);
			if (!(outer == 98 && inner == 99))
				write(1, separater, 2);
			inner++;
		}
		outer++;
	}
}
