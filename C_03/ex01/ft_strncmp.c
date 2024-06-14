/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 02:25:58 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 02:26:02 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	itr;

	itr = 0;
	while (itr < n)
	{
		if (*(s1 + itr) != *(s2 + itr)
			|| *(s1 + itr) == '\0' || *(s2 + itr) == '\0')
			return ((int)*(s1 + itr) - (int)*(s2 + itr));
		itr++;
	}
	return (0);
}
