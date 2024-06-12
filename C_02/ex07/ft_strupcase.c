#include <stdio.h>

char *ft_strupcase(char *str);
char to_upper(char ch);

char to_upper(char ch)
{
	int ch_ascii;
	int space_between;

	space_between = 'a' - 'A';
	ch_ascii = ch;
	return ch_ascii - space_between;
}

char *ft_strupcase(char *str)
{
	char *ptr;
	int ch;

	ptr = str;
	while (*ptr != '\0')
	{
		ch = *ptr;
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr = to_upper(*ptr);
		ptr++;
	}
	return (str);
}

int main()
{
	// char str[] = "abcAb1";
	char str[] = "alkdklsjgfsAAArtu1213";
	printf("convert %s to %s\n", str, ft_strupcase(str));
	return (0);
}
