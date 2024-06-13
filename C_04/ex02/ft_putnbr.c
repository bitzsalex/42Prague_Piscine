#include <unistd.h>
#include <limits.h>

void ft_putnbr(int num);
void print_digits(int num);

void print_digits(int num)
{
	char ch;

	if (num == 0)
		return;
	print_digits(num / 10);
	ch = (num % 10) + '0';
	write(1, &ch, 1);
}

void ft_putnbr(int num)
{
	if (num >= INT_MIN && num <= INT_MAX)
	{
		if (num == 0)
		{
			write(1, "0", 1);
			return;
		}
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		print_digits(num);
	}
}

int main()
{
	ft_putnbr(4563);
	ft_putnbr(-4563);
	return 0;
}
