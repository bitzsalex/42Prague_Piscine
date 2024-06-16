/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 07:01:32 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/16 07:01:35 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// validity checking helper functions
void	update_current_count(int value, int *higher, int *count);
int		ft_check_from_left(int **board, int *views, int row);
int		ft_check_from_right(int **board, int *views, int row);
int		ft_check_from_top(int **board, int *views, int col);
int		ft_check_from_bottom(int **board, int *views, int col);

// helper functions
char	*ft_left_trim(char *str);
void	ft_print_str(char *str);
int		ft_are_arguments_correct(int argc, char **argv);
void	ft_initialize(int argc, char **argv);

// input processing functions
int		ft_are_all_numbers(char *str);
int		ft_extract_view(char **str);
int		*ft_extract_views(char *str, int length);
int		ft_are_all_in_range(int *arr, int length, int max);
int		*ft_get_input_array(char *str, int *length);

// grid processing functions
int		**ft_create_board(int size);
void	ft_print_board(int **board, int size);

// puzzle solver functions
int		ft_check_row_view(int **board, int *views, int row);
int		ft_check_col_view(int **board, int *views, int col);
int		ft_is_safe(int **board, int num, int row, int col);
int		ft_is_it_solved(int **board, int *views);
int		ft_solver(int **board, int *views, int row, int col);
