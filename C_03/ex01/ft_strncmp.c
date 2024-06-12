#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int itr;

	itr = 0;
	while (itr < n)
	{
		if (
			*(s1 + itr) != *(s2 + itr) ||
			*(s1 + itr) == '\0' || *(s2 + itr) == '\0')
			return ((int)*(s1 + itr) - (int)*(s2 + itr));
		itr++;
	}

	return (0);
}

int main()
{
	printf("compare bitzsspace with bitzsspace is %d\n", strncmp("bitzsspace", "bitzsspace", 10));
	printf("compare bitzsSpace with bitzsspace is %d\n", strncmp("bitzsSpace", "bitzsspace", 10));
	printf("compare bitzs with bitzsspace is %d\n", strncmp("bitzs", "bitzsspace", 10));
	printf("compare bitzsspace with bitzs is %d\n", strncmp("bitzsspace", "bitzs", 10));
	printf("\n");
	printf("compare bitzsspace with bitzsspace is %d\n", ft_strncmp("bitzsspace", "bitzsspace", 10));
	printf("compare bitzsSpace with bitzsspace is %d\n", ft_strncmp("bitzsSpace", "bitzsspace", 10));
	printf("compare bitzs with bitzsspace is %d\n", ft_strncmp("bitzs", "bitzsspace", 10));
	printf("compare bitzsspace with bitzs is %d\n", ft_strncmp("bitzsspace", "bitzs", 10));
	return (0);
}
