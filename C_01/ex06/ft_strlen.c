#include <stdio.h>

int ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str += 1;
	}

	return length;
}

int main()
{
	printf("length of Betizazu is %d", ft_strlen("Betizazu"));
}
