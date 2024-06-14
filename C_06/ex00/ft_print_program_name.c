/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:52:54 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 23:52:58 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*ptr;

	if (argc)
	{
		ptr = argv[0];
		while (*ptr != '\0')
		{
			write(1, ptr, 1);
			ptr++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
