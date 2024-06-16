/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 07:02:02 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/16 07:02:03 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**ft_create_board(int size)
{
	int	itr;
	int	**board;

	itr = 0;
	board = (int **)malloc(size * sizeof(int *));
	while (itr < size && board != NULL)
	{
		board[itr] = malloc(size * sizeof(int));
		if (board[itr] == NULL)
		{
			board = NULL;
			break ;
		}
		itr++;
	}
	if (board == NULL)
		ft_print_str("Program crashed while creating the board!");
	return (board);
}

void	ft_print_board(int **board, int size)
{
	char	ch;
	int		itr;
	int		itrj;

	itr = 0;
	while (itr < size)
	{
		itrj = 0;
		while (itrj < size)
		{
			ch = board[itr][itrj++] + '0';
			write(1, &ch, 1);
		}
		ft_print_str("\n");
		itr++;
	}
}
