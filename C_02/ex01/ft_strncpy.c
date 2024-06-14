/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 03:30:17 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 03:30:23 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	if ((*src == '\0' && n != 0) || n == 0)
	{
		while (n != 0)
		{
			*dest = '\0';
			dest++;
			n--;
		}
		return (dest);
	}
	*dest = *src;
	ft_strncpy(dest + 1, src + 1, n - 1);
	return (dest);
}
