#include <string.h>
#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *ptr;

	if (*dest == '\0')
	{
		ptr = dest;
		while (nb > 0 && *src != '\0')
		{
			*ptr = *src;
			src++;
			ptr++;
			nb--;
		}
		*ptr = '\0';
		return (dest);
	}

	ft_strncat(dest + 1, src, nb);
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
	// printf("concat %s\n", strncat(dest1, src1, 5));
	// printf("concat %s\n", strncat(dest2, src2, 8));
	// printf("concat %s\n", strncat(dest3, src3, 10));
	// printf("concat %s\n", strncat(dest4, src4, 16));

	printf("concat %s\n", ft_strncat(dest1, src1, 5));
	printf("concat %s\n", ft_strncat(dest2, src2, 8));
	printf("concat %s\n", ft_strncat(dest3, src3, 10));
	printf("concat %s\n", ft_strncat(dest4, src4, 16));
}
