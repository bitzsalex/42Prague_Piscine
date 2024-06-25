/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:30:01 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/26 00:30:03 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *src);
char				*ft_str_cpy(char *dest, char *src);
int					ft_length(char *str);

char	*ft_str_cpy(char *dest, char *src)
{
	if (*src == '\0')
	{
		*dest = '\0';
		return (dest);
	}
	*dest = *src;
	ft_str_cpy(dest + 1, src + 1);
	return (dest);
}

int	ft_length(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

// size multiplication might be required for different compilors
char	*ft_strdup(char *src)
{
	int		length;
	char	*dest;

	length = ft_length(src);
	dest = (char *)malloc(++length * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_str_cpy(dest, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					itr;
	struct s_stock_str	*result;

	result = NULL;
	if (ac > 0)
	{
		result = malloc(sizeof(struct s_stock_str) * (ac + 1));
		if (result != NULL)
		{
			itr = 0;
			while (itr < ac)
			{
				result[itr].str = av[itr];
				result[itr].copy = ft_strdup(av[itr]);
				result[itr].size = ft_length(av[itr]);
				itr++;
			}
			result[itr].str = "0";
			result[itr].copy = "0";
			result[itr].size = 1;
		}
	}
	return (result);
}
