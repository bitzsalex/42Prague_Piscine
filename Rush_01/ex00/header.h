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
// grid/board processing functions
int		**ft_create_board(int size);
void	ft_print_board(int **board, int size);
