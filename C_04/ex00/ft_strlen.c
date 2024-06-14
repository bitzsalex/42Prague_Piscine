/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 05:20:24 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 05:20:31 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);
int	count_chars(char *str, int count);

int	count_chars(char *str, int count)
{
	if (*str == '\0')
		return (count);
	return (count_chars(str + 1, count + 1));
}

int	ft_strlen(char *str)
{
	return (count_chars(str, 0));
}
