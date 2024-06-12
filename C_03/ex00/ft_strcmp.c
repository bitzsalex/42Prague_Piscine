#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return ((int)*s1 - (int)*s2);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (-1 * (int)*s2);
	return (0);
}

int main()
{
	printf("compare ustv with abdc is %d\n", strcmp("ustv", "abdc"));
	printf("compare ustv with ust is %d\n", strcmp("ustv", "ust"));
	printf("compare ust with ustb is %d\n", strcmp("ust", "ustb"));
	printf("compare ust with ust is %d\n", strcmp("ust", "ust"));
	printf("\n");
	printf("compare ustv with abdc is %d\n", ft_strcmp("ustv", "abdc"));
	printf("compare ustv with ust is %d\n", ft_strcmp("ustv", "ust"));
	printf("compare ust with ustb is %d\n", ft_strcmp("ust", "ustb"));
	printf("compare ust with ust is %d\n", ft_strcmp("ust", "ust"));
	return (0);
}
