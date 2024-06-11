#include <stdio.h>

int ft_str_is_printable(char *str);

int ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str == '\x7F') // \x7F is value for DEL
			return (0);
		str++;
	}
	return (1);
}

int main()
{
	printf("is empty printable %d\n", ft_str_is_printable(""));
	printf("is abABzZ@# printable %d\n", ft_str_is_printable("abABzZ@#"));
	printf("is ABbbb\r printable %d\n", ft_str_is_printable("ABbbb\r"));
	printf("is 0123st printable %d\n", ft_str_is_printable("0123st"));
	printf("is []\n] printable %d\n", ft_str_is_printable("[]\n]"));
	printf("is []\x7F] printable %d\n", ft_str_is_printable("[]\x7F]"));
	printf("is []] printable %d\n", ft_str_is_printable("[]]"));
}
