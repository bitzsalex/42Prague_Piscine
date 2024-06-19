/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesaleg <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 03:33:15 by bdesaleg          #+#    #+#             */
/*   Updated: 2024/06/14 03:33:18 by bdesaleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*get_hex_representation(unsigned long num, char *dest, int size);
void	print_address_hex(void *ptr);
void	print_content_hex(char *addr, int size);
void	print_content_char(char *addr, int size);
void	*ft_print_memory(void *addr, unsigned int size);

char	*get_hex_representation(unsigned long num, char *dest, int size)
{
	int	counter;
	int	remainder;

	counter = size - 1;
	while (num)
	{
		remainder = num % 16;
		if (remainder < 10)
			dest[counter] = remainder + '0';
		else
			dest[counter] = 'a' + (remainder - 10);
		num /= 16;
		counter--;
	}
	while (counter >= 0)
		dest[counter--] = '0';
	return (dest);
}

void	print_address_hex(void *ptr)
{
	char			hex[16];
	unsigned long	addr;

	addr = (unsigned long)ptr;
	write(1, get_hex_representation(addr, hex, 16), 16);
	write(1, ":", 1);
}

// 32 is because 16 characters each represented by 2 hex
void	print_content_hex(char *addr, int size)
{
	int		itr;
	int		counter;
	char	hex[2];

	itr = 0;
	counter = 32;
	while (itr < size)
	{
		if (counter % 4 == 0)
			write(1, " ", 1);
		write(1, get_hex_representation((int)*addr, hex, 2), 2);
		counter -= 2;
		if (*addr == '\0' && *(addr + 1) == '\0')
			break ;
		addr++;
		itr++;
	}
	while (counter > 0)
	{
		if (counter % 4 == 0)
			write(1, " ", 1);
		write(1, " ", 1);
		counter--;
	}
}

void	print_content_char(char *addr, int size)
{
	int	itr;

	itr = 0;
	write(1, " ", 1);
	while (itr < size)
	{
		if (*addr < ' ' || *addr > '~')
			write(1, ".", 1);
		else
			write(1, addr, 1);
		if (*addr == '\0' && *(addr + 1) == '\0')
			break ;
		addr++;
		itr++;
	}
}

// we like to print 16 characters perline
void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*ptr;

	if (size > 0)
	{
		ptr = (char *)addr;
		while (*ptr != '\0')
		{
			print_address_hex(ptr);
			print_content_hex(ptr, 16);
			print_content_char(ptr, 16);
			write(1, "\n", 1);
			ptr += size;
		}
	}
	return (addr);
}

#include <stdio.h>
int main(void)
{
	char str[] = "Print \tstring with more than 16\n "\
					"bytes output \rThis is a long \bstring. "\
					"It has more \0 than 16 bytes. as expecte."\
					"Print \t\tempty string output \"\" as expected";
	ft_print_memory(str, 16);
	return (0);
}
