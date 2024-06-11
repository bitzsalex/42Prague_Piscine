#include <string.h>
#include <stdio.h>

char *ft_strcpy(char *dest, char *src);

char *ft_strcpy(char *dest, char *src)
{
	if (*src == '\0')
	{
		*dest = '\0';
		return NULL;
	}
	*dest = *src;
	ft_strcpy(++dest, ++src);

	return (dest);
}

int main()
{
	char dest[15];
	char src[] = "Hello Sir!";

	ft_strcpy(dest, src);
	printf("After copy %s\n", dest);
	return (0);
}
