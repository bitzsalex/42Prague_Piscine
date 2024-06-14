/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 02:27:28 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 02:27:32 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	itr;

	dest_len = 0;
	while (*dest++ != '\0')
		dest_len++;
	dest--;
	if (dest_len >= size || size == 0)
		return (size);
	itr = 0;
	while (src[itr] != '\0' && (itr + dest_len) < size - 1)
	{
		*dest = src[itr];
		itr++;
		dest++;
	}
	while (src[itr] != '\0')
		itr++;
	*dest = '\0';
	return (dest_len + itr);
}
