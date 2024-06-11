#include <stdio.h>

int ft_str_is_alpha(char *str);

int ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}

int main()
{
	printf("is ABCDEFGHIJKLMNOPQRSTUVWXYZ alpha %d\n", ft_str_is_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("is abcdefghijklmnopqrstuvwxyz alpha %d\n", ft_str_is_alpha("abcdefghijklmnopqrstuvwxyz"));
	printf("is 0123st alpha %d\n", ft_str_is_alpha("0123st"));
	printf("is []\\] alpha %d\n", ft_str_is_alpha("[]\\]"));
}
