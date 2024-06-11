#include <stdio.h>

int ft_str_is_lowercase(char *str);

int ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}

int main()
{
	printf("is empty lowercase %d\n", ft_str_is_lowercase(""));
	printf("is cdAB lowercase %d\n", ft_str_is_lowercase("cdAB"));
	printf("is abcdefghijklmnopqrstuvwxyz lowercase %d\n", ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz"));
	printf("is kljfslkd lowercase %d\n", ft_str_is_lowercase("kljfslkd"));
	printf("is 0123st lowercase %d\n", ft_str_is_lowercase("0123st"));
	printf("is []\\] lowercase %d\n", ft_str_is_lowercase("[]\\]"));
}
