#include <stdio.h>
#include <string.h>

char *is_not_found(char *str, char *to_find);
char *ft_strstr(char *str, char *to_find);

char *is_not_found(char *ptr_str, char *ptr_to_find)
{
	while (*ptr_str != '\0' && *ptr_str == *ptr_to_find)
	{
		*ptr_str++;
		*ptr_to_find++;
	}
	if (*ptr_to_find == '\0')
		return (NULL);
	return ptr_str;
}

char *ft_strstr(char *str, char *to_find)
{
	char *ptr;

	if (*to_find == '\0')
		return str;

	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			ptr = is_not_found(str, to_find);
			if (ptr)
				str = ptr;
			else
				return (str);
		}

		str++;
	}

	return (NULL);
}

int main()
{
	printf("%s\n", strstr("the there on top", "there"));
	printf(
		"%s\n", strstr("the there on top", "them") ? strstr("the there on top", "them") : "NULL");
	printf(
		"%s\n", strstr("", "there") ? strstr("", "there") : "NULL");
	printf("%s\n", strstr("the there on top", ""));
	printf("\n");

	printf("%s\n", ft_strstr("the there on top", "there"));
	printf(
		"%s\n", ft_strstr("the there on top", "them") ? ft_strstr("the there on top", "them") : "NULL");
	printf(
		"%s\n", ft_strstr("", "there") ? ft_strstr("", "there") : "NULL");
	printf("%s\n", ft_strstr("the there on top", ""));
}
