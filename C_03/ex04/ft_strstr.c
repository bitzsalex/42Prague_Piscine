/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 02:27:00 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 02:27:03 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*is_not_found(char *str, char *to_find);
char	*ft_strstr(char *str, char *to_find);

char	*is_not_found(char *ptr_str, char *ptr_to_find)
{
	while (*ptr_str != '\0' && *ptr_str == *ptr_to_find)
	{
		ptr_str++;
		ptr_to_find++;
	}
	if (*ptr_to_find == '\0')
		return (NULL);
	return (ptr_str);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			ptr = is_not_found(str, to_find);
			if (ptr)
				str = ptr;
			else
				return (str);
		}
		str++;
	}
	return (NULL);
}
