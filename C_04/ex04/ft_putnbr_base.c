/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 06:42:30 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 06:42:33 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	get_base_info(char *base, int *is_valid, int *length);
void	putnbr(int num, char *base, int length);
int		is_alphanum(char ch);

int	is_alphanum(char ch)
{
	if ((ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}

void	get_base_info(char *base, int *is_invalid, int *length)
{
	int	itr;
	int	itrj;

	itr = 0;
	*is_invalid = 0;
	while (base[itr] != '\0' && *is_invalid == 0)
	{
		if (!is_alphanum(base[itr]))
			*is_invalid = 1;
		else
		{
			itrj = itr + 1;
			while (base[itrj] != '\0' && *is_invalid == 0)
			{
				if (base[itr] == base[itrj])
					*is_invalid = 1;
				itrj++;
			}
		}
		itr++;
	}
	*length = itr;
}

void	putnbr(int num, char *base, int length)
{
	unsigned int	unum;

	if (num == 0)
		write(1, "0", 1);
	else
	{
		unum = num;
		if (num < 0)
		{
			unum = num * -1;
			write(1, "-", 1);
		}
		if ((unum / length) != 0)
			putnbr(unum / length, base, length);
		write(1, base + (unum % length), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	is_base_invalid;
	int	length;

	get_base_info(base, &is_base_invalid, &length);
	if (is_base_invalid || length <= 1)
		return ;
	putnbr(nbr, base, length);
}
