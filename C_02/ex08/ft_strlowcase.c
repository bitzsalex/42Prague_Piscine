#include <stdio.h>

char *ft_strlowcase(char *str);
char to_lower(char ch);

char to_lower(char ch)
{
	int ch_ascii;
	int space_between;

	space_between = 'a' - 'A';
	ch_ascii = ch;
	return ch_ascii + space_between;
}

char *ft_strlowcase(char *str)
{
	char *ptr;
	int ch;

	ptr = str;
	while (*ptr != '\0')
	{
		ch = *ptr;
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr = to_lower(*ptr);
		ptr++;
	}
	return (str);
}

int main()
{
	char str[] = "ABSO124a";
	// char str[] = "ALJLKDJFS454ldjfsEOTU";
	printf("%s\n", ft_strlowcase(str));
	return (0);
}
