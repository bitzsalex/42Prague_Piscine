#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int dest_len;
	int itr;

	dest_len = 0;
	while (*dest++ != '\0')
		dest_len++;
	dest--; // to fix the last offset
	if (dest_len >= size || size == 0)
		return size;
	itr = 0;
	while (src[itr] != '\0' && (itr + dest_len) < size - 1)
	{
		*dest = src[itr];
		itr++;
		*dest++;
	}
	while (src[itr] != '\0')
		itr++;
	*dest = '\0'; // always null terminate
	return (dest_len + itr);
}

int main()
{
	char dest1[16] = "Hello ", src1[] = "World!";

	printf("concat %s %d\n", dest1, ft_strlcat(dest1, src1, 16));
	return (0);
}
