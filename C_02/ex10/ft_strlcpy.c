/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 03:32:41 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 03:32:45 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	copy_str(char *dest, char *src,
					unsigned int size, unsigned int counter);

unsigned int	copy_str(char *dest, char *src,
					unsigned int size, unsigned int counter)
{
	if (*src == '\0' || size <= 0)
	{
		while (*src++ != '\0')
			counter++;
		*dest = '\0';
		return (counter);
	}
	*dest = *src;
	counter = copy_str(dest + 1, src + 1, size - 1, counter + 1);
	return (counter);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	return (copy_str(dest, src, size - 1, 0));
}
