/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:19:42 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/16 14:19:44 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int	g_size;

void	update_current_count(int value, int *higher, int *count)
{
	if (value > *higher)
	{
		*higher = value;
		*count = *count + 1;
	}
}

int	ft_check_from_left(int **board, int *views, int row)
{
	int	itr;
	int	count;
	int	current_higher;

	itr = 0;
	count = 0;
	current_higher = 0;
	while (itr < g_size)
	{
		update_current_count(board[row][itr], &current_higher, &count);
		itr++;
	}
	if (count == views[(g_size * 2) + row])
		return (1);
	return (0);
}

int	ft_check_from_right(int **board, int *views, int row)
{
	int	itr;
	int	count;
	int	current_higher;

	count = 0;
	current_higher = 0;
	itr = g_size - 1;
	while (itr >= 0)
	{
		update_current_count(board[row][itr], &current_higher, &count);
		itr--;
	}
	if (count == views[(g_size * 3) + row])
		return (1);
	return (0);
}

int	ft_check_from_top(int **board, int *views, int col)
{
	int	itr;
	int	count;
	int	current_higher;

	itr = 0;
	count = 0;
	current_higher = 0;
	while (itr < g_size)
	{
		update_current_count(board[itr][col], &current_higher, &count);
		itr++;
	}
	if (count == views[col])
		return (1);
	return (0);
}

int	ft_check_from_bottom(int **board, int *views, int col)
{
	int	itr;
	int	count;
	int	current_higher;

	count = 0;
	current_higher = 0;
	itr = g_size - 1;
	while (itr >= 0)
	{
		update_current_count(board[itr][col], &current_higher, &count);
		itr--;
	}
	if (count == views[g_size + col])
		return (1);
	return (0);
}
