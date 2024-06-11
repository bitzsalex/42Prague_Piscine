#include <stdio.h>

int ft_str_is_uppercase(char *str);

int ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
			return (0);
		str++;
	}
	return (1);
}

int main()
{
	printf("is empty uppercase %d\n", ft_str_is_uppercase(""));
	printf("is ABCDEFGHIJKLMNOPQRSTUVWXYZ uppercase %d\n", ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("is ABbbb uppercase %d\n", ft_str_is_uppercase("ABbbb"));
	printf("is 0123st uppercase %d\n", ft_str_is_uppercase("0123st"));
	printf("is []\\] uppercase %d\n", ft_str_is_uppercase("[]\\]"));
}
