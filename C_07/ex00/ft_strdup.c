/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:15:08 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/15 11:15:11 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);
char	*str_cpy(char *dest, char *src);

char	*str_cpy(char *dest, char *src)
{
	if (*src == '\0')
	{
		*dest = '\0';
		return (dest);
	}
	*dest = *src;
	str_cpy(dest + 1, src + 1);
	return (dest);
}

char	*ft_strdup(char *src)
{
	int	length;

	length = 0;
	while (src[length] != '\0')
		length++;
	return (str_cpy(malloc(length), src));
}
