/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:43:34 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/25 19:43:52 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);
int		ft_get_pointers_len(char *str, char *seps);
char	*ft_extract_string(char **str, char *seps);
int		ft_is_separator(char ch, char *seps);

int	ft_is_separator(char ch, char *seps)
{
	while (*seps != '\0')
	{
		if (*seps == ch)
			return (1);
		seps++;
	}
	return (0);
}

int	ft_get_pointers_len(char *str, char *seps)
{
	int		is_ptr_sep;
	int		is_prev_sep;
	int		count;
	char	*ptr;

	count = 1;
	ptr = str;
	while (*ptr != '\0')
	{
		is_ptr_sep = ft_is_separator(*ptr, seps);
		is_prev_sep = (ptr != str && is_ptr_sep
				&& ft_is_separator(*(ptr - 1), seps));
		ptr++;
		if (is_prev_sep)
			continue ;
		else if (is_ptr_sep)
			count ++;
	}
	return (count);
}

char	*ft_extract_string(char **str, char *seps)
{
	char	*ptr;
	char	*result;
	int		length;
	int		itr;

	itr = 0;
	length = 0;
	ptr = *str;
	while (ptr[length] != '\0' && !ft_is_separator(ptr[length], seps))
		length++;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result != NULL)
	{
		while (itr < length)
		{
			result[itr] = ptr[itr];
			itr++;
		}
		*str = *str + itr;
		result[itr] = '\0';
	}
	return (result);
}

void	ft_fill(char **result, char *str, char *seps)
{
	int		itr;
	int		is_ptr_sep;
	char	*ptr;

	ptr = str;
	itr = 0;
	while (*ptr != '\0')
	{
		is_ptr_sep = ft_is_separator(*ptr, seps);
		if ((ptr != str && is_ptr_sep
				&& ft_is_separator(*(ptr - 1), seps)) || is_ptr_sep)
			ptr++;
		else if (!is_ptr_sep)
		{
			result[itr] = ft_extract_string(&ptr, seps);
			itr++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		num_of_pointers;

	num_of_pointers = ft_get_pointers_len(str, charset);
	strs = (char **)malloc(sizeof(char *) * num_of_pointers);
	if (*str != '\0')
	{
		if (strs != NULL)
		{
			if (*str == '\0')
				*strs = str;
			else
				ft_fill(strs, str, charset);
		}
	}
	else
		*strs = NULL;
	return (strs);
}
