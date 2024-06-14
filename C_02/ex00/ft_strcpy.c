/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 03:30:01 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 03:30:06 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	if (*src == '\0')
	{
		*dest = '\0';
		return (dest);
	}
	*dest = *src;
	ft_strcpy(dest + 1, src + 1);
	return (dest);
}
