/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:06:18 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/20 02:06:21 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
int		ft_getsize(char **strs, char *sep, int size);

int	ft_getsize(char **strs, char *sep, int size)
{
	int	itr;
	int	total_size;
	int	sep_len;

	itr = 0;
	sep_len = ft_strlen(sep);
	total_size = sep_len * (size - 1);
	while (itr < size)
	{
		total_size += ft_strlen(strs[itr]);
		itr++;
	}
	return (++total_size);
}

int	ft_strlen(char *str)
{
	int	itr;

	itr = 0;
	while (*str != '\0')
	{
		itr++;
		str++;
	}
	return (itr);
}

int	ft_append_str(char *dest, char *src, int start_pos)
{
	while (*src != '\0')
	{
		dest[start_pos] = *src;
		src++;
		start_pos++;
	}
	return (start_pos);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		itr;
	int		index;
	char	*str;

	index = 0;
	if (size > 0)
	{
		itr = 0;
		str = (char *)malloc(sizeof(char) * ft_getsize(strs, sep, size));
		while (itr < size)
		{
			index = ft_append_str(str, strs[itr], index);
			if (itr != (size - 1))
				index = ft_append_str(str, sep, index);
			itr++;
		}
	}
	else
		str = (char *)malloc(sizeof(char));
	str[index] = '\0';
	return (str);
}
