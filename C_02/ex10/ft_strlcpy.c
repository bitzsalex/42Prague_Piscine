#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int copy_str(char *dest, char *src, unsigned int size, unsigned int counter);

unsigned int copy_str(char *dest, char *src, unsigned int size, unsigned int counter)
{
	if (*src == '\0' || size <= 0)
	{
		while (*src++ != '\0')
			counter++;
		*dest = '\0';
		return counter;
	}

	*dest = *src;
	counter = copy_str(dest + 1, src + 1, size - 1, counter + 1);
	return (counter);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	return (copy_str(dest, src, size - 1, 0));
}

int main()
{
	char src[] = "Hello Sir!";
	char dest[15];
	int num = ft_strlcpy(dest, src, 12);

	printf("copied size %d\n", num);
}
