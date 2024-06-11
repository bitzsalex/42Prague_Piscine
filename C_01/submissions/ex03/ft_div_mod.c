/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:34 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/11 12:50:37 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;
// 	int	div;
// 	int	mod;

// 	a = 23;
// 	b = 4;
// 	div = 0;
// 	mod = 0;
// 	printf("before calling div=%d and mod=%d\n", div, mod);
// 	ft_div_mod(a, b, &div, &mod);
// 	printf("after calling div=%d and mod=%d\n", div, mod);
// }
