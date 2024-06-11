#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	if ((*src == '\0' && n != 0) || n == 0)
	{
		while (n != 0)
		{
			*dest = '\0';
			dest++;
			n--;
		}
		return dest;
	}
	*dest = *src;
	ft_strncpy(dest + 1, src + 1, n - 1);
	return (dest);
}

int main()
{
	char dest[15];
	char src[] = "Hello Sir!";

	ft_strncpy(dest, src, 8);
	printf("After copy %s\n", dest);
	return (0);
}
