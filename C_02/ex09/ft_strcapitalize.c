#include <stdio.h>

char *ft_strcapitalize(char *str);
int is_lower(char ch);
int is_alphanum(char ch);
char to_upper(char ch);

char to_upper(char ch)
{
	int ch_ascii;
	int space_between;

	space_between = 'a' - 'A';
	ch_ascii = ch;
	return ch_ascii - space_between;
}

int is_alphanum(char ch)
{
	if (is_lower(ch) || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}

int is_lower(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

char *ft_strcapitalize(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (
			((ptr == str) && is_lower(*ptr)) ||
			((ptr != str) && is_lower(*ptr) && !is_alphanum(*(ptr - 1))))
			*ptr = to_upper(*ptr);
		ptr++;
	}
	return (str);
}

int main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("converted to %s\n", ft_strcapitalize(str));
	return 0;
}
