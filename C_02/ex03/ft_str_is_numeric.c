#include <stdio.h>

int ft_str_is_numeric(char *str);

int ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int main()
{
	printf("is empty numeric %d\n", ft_str_is_numeric(""));
	printf("is 0123456789 numeric %d\n", ft_str_is_numeric("0123456789"));
	printf("is abcAbc numeric %d\n", ft_str_is_numeric("abcAbc"));
	printf("is []@] numeric %d\n", ft_str_is_numeric("[]@]"));
	printf("is . numeric %d\n", ft_str_is_numeric("."));
}
