/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 09:19:24 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/16 09:19:26 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int	g_size;

// check view row wise
int	ft_check_row_view(int **board, int *views, int row)
{
	int	itr;

	itr = 0;
	while (itr < g_size)
	{
		if (board[row][itr] == 0)
			return (1);
		itr++;
	}
	return (ft_check_from_left(board, views, row)
		&& ft_check_from_right(board, views, row));
}

// check view col wise
int	ft_check_col_view(int **board, int *views, int col)
{
	int	itr;

	itr = 0;
	while (itr < g_size)
	{
		if (board[itr][col] == 0)
			return (1);
		itr++;
	}
	return (ft_check_from_top(board, views, col)
		&& ft_check_from_bottom(board, views, col));
}

// Function to check if a number can be placed at board[row][col]
// i.e., check if 'num' is not in the current row and column
int	ft_is_safe(int **board, int num, int row, int col)
{
	int	itr;

	itr = 0;
	while (itr < g_size)
	{
		if (board[row][itr] == num || board[itr][col] == num)
			return (0);
		itr++;
	}
	return (1);
}

int	ft_is_it_solved(int **board, int *views)
{
	int	itr;

	itr = 0;
	while (itr < g_size)
	{
		if (!ft_check_row_view(board, views, itr)
			|| !ft_check_col_view(board, views, itr))
			return (0);
		itr++;
	}
	return (1);
}

// Recursive function to solve the problem
// 		First condition checks if we reached the last cell
// 		Second condition checks the end of the row to move to the next
// 		Third condition checks the current cell is already filled
// If placing num doesn't lead to a solution, remove it (backtrack)
// 		board[row][col] = 0;
int	ft_solver(int **board, int *views, int row, int col)
{
	int	itr;

	if (row == g_size - 1 && col == g_size)
		return (ft_is_it_solved(board, views));
	if (col == g_size)
	{
		if (ft_check_row_view(board, views, row))
			return (ft_solver(board, views, row + 1, 0));
		return (0);
	}
	if (board[row][col] != 0)
		return (ft_solver(board, views, row, col + 1));
	itr = 1;
	while (itr <= g_size)
	{
		if (ft_is_safe(board, itr, row, col))
		{
			board[row][col] = itr;
			if (ft_solver(board, views, row, col + 1))
				return (1);
			board[row][col] = 0;
		}
		itr++;
	}
	return (0);
}
