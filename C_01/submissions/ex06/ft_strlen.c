/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:14:36 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/11 13:14:39 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str += 1;
	}
	return (length);
}

// int	main(void)
// {
// 	printf("length of name is %d", ft_strlen("name"));
// 	printf("length of Betizazu is %d", ft_strlen("Betizazu"));
// }
