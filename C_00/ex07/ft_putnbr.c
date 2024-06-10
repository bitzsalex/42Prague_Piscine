#include <unistd.h>

void ft_putnbr(int num);

void	ft_putnbr(int num)
{
	char	number_digits[12];
	int		counter;

	counter = 0;
	if (num != 0)
	{
		if (num < 0)
		{
			num *= -1;
			write(1, "-", 1);
		}
		while (num > 0)
		{
			number_digits[counter] = (num % 10) + '0';
			num = num / 10;
			counter++;
		}
		while (--counter >= 0)
			write(1, (number_digits + counter), 1);
	}
	else
		write(1, "0", 1);
}

int main()
{
    ft_putnbr(42);
    ft_putnbr(4563);
    ft_putnbr(-4563);
    return 0;
}