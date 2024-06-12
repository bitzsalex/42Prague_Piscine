#include <stdio.h>
#include <unistd.h>

void print_hex(char ch);
int is_printable(char ch);
void ft_putstr_non_printable(char *str);

void print_hex(char ch)
{
	char hex[3];
	int counter;
	int remainder;
	int ch_ascii;

	ch_ascii = ch;
	counter = 2; // to reverse
	hex[0] = '\\';
	hex[1] = '0';
	while (ch_ascii)
	{
		remainder = ch_ascii % 16;
		if (remainder < 10)
			hex[counter] = remainder + '0';
		else
			hex[counter] = 'a' + (remainder - 10);
		ch_ascii /= 16;
		counter--;
	}

	write(1, hex, 3);
}

int is_printable(char ch)
{
	if (ch < ' ' || ch > '~')
		return (0);
	return (1);
}

void ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (is_printable(*str))
			write(1, str, 1);
		else
			print_hex(*str);
		str++;
	}
}

int main()
{
	char str[] = "\aCoucou\btu \tvas \nbien \v? \f \r";
	printf("\\aCoucou\\btu \\tvas \\nbien \\v? \\f \\r become\n");
	ft_putstr_non_printable(str);
	return (0);
}
