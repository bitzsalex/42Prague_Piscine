/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:13:43 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/11 13:13:52 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 23;
// 	b = 4;
// 	printf("Before calling a=%d and b=%d\n", a, b);
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("after calling a=%d and b=%d\n", a, b);
// }
