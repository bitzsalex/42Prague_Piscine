/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 03:32:22 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 03:32:25 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		check_case(char ch, int type);
int		is_alphanum(char ch);

int	check_case(char ch, int type)
{
	if ((type == 0 && ch >= 'a' && ch <= 'z')
		|| (type == 1 && ch >= 'A' && ch <= 'Z'))
		return (1);
	return (0);
}

int	is_alphanum(char ch)
{
	if (check_case(ch, 0) || check_case(ch, 1) || (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		code_diff;

	code_diff = 'a' - 'A';
	ptr = str;
	while (*ptr != '\0')
	{
		if (((ptr == str) && check_case(*ptr, 0))
			|| ((ptr != str) && check_case(*ptr, 0)
				&& !is_alphanum(*(ptr - 1))))
			*ptr = *ptr - code_diff;
		else if ((ptr != str)
			&& is_alphanum(*(ptr - 1)) && check_case(*ptr, 1))
			*ptr = *ptr + code_diff;
		ptr++;
	}
	return (str);
}
