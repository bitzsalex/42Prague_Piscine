/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:10:21 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 23:14:57 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb);
int	ft_find_next_prime(int nb);

int	is_prime(int nb)
{
	int	itr;

	if (nb <= 1)
		return (0);
	itr = 2;
	while (itr < nb)
		if (nb % itr++ == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
