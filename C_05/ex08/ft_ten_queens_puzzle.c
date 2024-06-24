/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:14:05 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/24 15:14:08 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int result)
{
	if (result < 0)
		result *= -1;
	return (result);
}

void	ft_print_board(char board[10])
{
	int		itr;
	char	printable;

	itr = 0;
	while (itr < 10)
	{
		printable = board[itr];
		write(1, &printable, 1);
		itr++;
	}
	write(1, "\n", 1);
}

int	ft_is_safe(char board[10], int row, int column)
{
	int	itr;
	int	prev_row;

	itr = 0;
	while (itr < 10)
	{
		if (board[itr] != '.')
		{
			prev_row = board[itr] - '0';
			if (prev_row == row
				|| ft_abs(itr - column) == ft_abs(prev_row - row))
				return (0);
		}
		itr++;
	}
	return (1);
}

int	ft_place_queens(char board[10], int current_column, int *solutions)
{
	int	row;

	if (current_column == 10)
	{
		ft_print_board(board);
		(*solutions)++;
		board[current_column - 1] = '.';
		return (1);
	}
	row = 0;
	while (row < 10)
	{
		if (ft_is_safe(board, row, current_column))
		{
			board[current_column] = row + '0';
			if (ft_place_queens(board, current_column + 1, solutions))
			{
				row++;
				continue ;
			}
			board[current_column] = '.';
		}
		row++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[11];
	int		solutions;
	int		itr;

	itr = 0;
	solutions = 0;
	while (itr < 10)
		board[itr++] = '.';
	board[itr] = '\0';
	ft_place_queens(board, 0, &solutions);
	return (solutions);
}
