/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 02:26:44 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 02:26:47 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	if (*dest == '\0')
	{
		ptr = dest;
		while (nb > 0 && *src != '\0')
		{
			*ptr = *src;
			src++;
			ptr++;
			nb--;
		}
		*ptr = '\0';
		return (dest);
	}
	ft_strncat(dest + 1, src, nb);
	return (dest);
}
