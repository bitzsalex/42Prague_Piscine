/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:26:21 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/15 00:26:23 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare_params(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return ((int)*s1 - (int)*s2);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (-1 * (int)*s2);
	return (0);
}

void	sort_params(char **argv, int argc)
{
	int		itr;
	int		itrj;
	char	*tmp;

	itr = 2;
	while (itr < argc)
	{
		itrj = itr;
		while (itrj > 1 && compare_params(argv[itrj - 1], argv[itrj]) > 0)
		{
			tmp = argv[itrj];
			argv[itrj] = argv[itrj - 1];
			argv[itrj - 1] = tmp;
			itrj--;
		}
		itr++;
	}
}

int	main(int argc, char **argv)
{
	int	itr;
	int	chr;

	sort_params(argv, argc);
	itr = 1;
	while (itr < argc)
	{
		chr = 0;
		while (argv[itr][chr] != '\0')
			chr++;
		write(1, argv[itr], chr);
		write(1, "\n", 1);
		itr++;
	}
	return (0);
}
