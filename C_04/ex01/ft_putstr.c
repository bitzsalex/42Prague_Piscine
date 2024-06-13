#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str);

void ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str += 1;
	}
}

int main()
{
	ft_putstr("name");
	printf("\n");
	ft_putstr("something");
	return 0;
}
