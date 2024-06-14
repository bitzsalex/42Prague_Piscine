/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 02:26:22 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 02:26:31 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	if (*dest == '\0')
	{
		ptr = dest;
		while (*src != '\0')
		{
			*ptr = *src;
			src++;
			ptr++;
		}
		*ptr = '\0';
		return (dest);
	}
	ft_strcat(dest + 1, src);
	return (dest);
}
