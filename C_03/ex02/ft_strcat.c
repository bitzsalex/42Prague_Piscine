#include <string.h>
#include <stdio.h>

char *ft_strcat(char *dest, char *src);

char *ft_strcat(char *dest, char *src)
{
	char *ptr;

	if (*dest == '\0')
	{
		ptr = dest;
		while (*src != '\0')
		{
			*ptr = *src;
			src++;
			ptr++;
		}
		*ptr = '\0';
		return (dest);
	}

	ft_strcat(dest + 1, src);
	return (dest);
}

int main()
{
	char dest1[16] = "Hello ",
		 src1[] = "World!";
	char dest2[9] = "Hello ",
		 src2[] = "World!";
	char dest3[9] = "Hello ",
		 src3[] = "";
	char dest4[9] = "",
		 src4[] = "World!";
	// printf("concat %s\n", strcat(dest1, src1));
	// printf("concat %s\n", strcat(dest2, src2));
	// printf("concat %s\n", strcat(dest3, src3));
	// printf("concat %s\n", strcat(dest4, src4));

	printf("concat %s\n", ft_strcat(dest1, src1));
	printf("concat %s\n", ft_strcat(dest2, src2));
	printf("concat %s\n", ft_strcat(dest3, src3));
	printf("concat %s\n", ft_strcat(dest4, src4));
}
