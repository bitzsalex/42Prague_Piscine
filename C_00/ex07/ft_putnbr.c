#include <unistd.h>

void ft_putnbr(int num);

void ft_putnbr(int num)
{
    char printedChar = '\0', numberDigits[12];
    int counter = 0;

    // check if it is negative
    if (num < 0)
    {
        printedChar = '-';
        num *= -1;
        write(1, &printedChar, 1);
    }

    // get individual char in reverse order
    while (num > 0)
    {
        numberDigits[counter] = (num % 10) + '0';
        num = num / 10;
        counter++;
    }

    // print backwards
    while (--counter >= 0)
        write(1, (numberDigits + counter), 1);
}

int main()
{
    ft_putnbr(42);
    ft_putnbr(4563);
    ft_putnbr(-4563);
    return 0;
}