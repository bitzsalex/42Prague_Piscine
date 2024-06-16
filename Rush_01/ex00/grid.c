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

extern int	g_size;

// creates the board and initiates the board with 0
int	**ft_create_board(int size)
{
	int	itr;
	int	itrj;
	int	**board;

	itr = 0;
	board = (int **)malloc(size * sizeof(int *));
	while (itr < size && board != NULL)
	{
		itrj = 0;
		board[itr] = malloc(size * sizeof(int));
		if (board[itr] == NULL)
		{
			board = NULL;
			break ;
		}
		while (itrj < size)
			board[itr][itrj++] = 0;
		itr++;
	}
	if (board == NULL)
		ft_print_str("Program crashed while creating the board!");
	return (board);
}

// loop through the board and print the content
void	ft_print_board(int **board, int size)
{
	char	ch[3];
	int		itr;
	int		itrj;

	itr = 0;
	ch[0] = ' ';
	ch[2] = '\0';
	while (itr < size)
	{
		itrj = 0;
		while (itrj < size)
		{
			ch[1] = board[itr][itrj++] + '0';
			ft_print_str(ch);
		}
		ft_print_str("\n");
		itr++;
	}
}
