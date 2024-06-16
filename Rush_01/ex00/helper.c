/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 08:29:28 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/16 08:29:31 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_left_trim(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

void	ft_print_str(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_are_arguments_correct(int argc, char **argv)
{
	char	*error;
	int		**board;

	error = NULL;
	if (argc == 1)
		error = "Please pass the views as a single string\n";
	else if (argc > 2)
		error = "Too manay arguments passed\n";
	if (error)
	{
		ft_print_str(error);
		return (0);
	}
	return (1);
}

void	ft_initialize(int argc, char **argv)
{
	int	**board;
	int	input_length;
	int	*input_array;
	int	solution;

	if (ft_are_arguments_correct(argc, argv))
	{
		input_array = ft_get_input_array(argv[1], &input_length);
		if (input_array == NULL)
		{
			ft_print_str("Your input for the views are incorrect\n");
			return ;
		}
		g_size = input_length / 4;
		board = ft_create_board(g_size);
		for (int i = 0; i < input_length; i++)
			printf("%d", input_array[i]);
		// ft_print_board(board, g_size);
		// solution = ft_solver(board, input_array, 0, 0);
		// if (solution)
		// 	ft_print_board(board, g_size);
		// else
		// 	ft_print_str("No solutions found!\n");
	}
}
