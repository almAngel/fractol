/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:00:33 by angellop          #+#    #+#             */
/*   Updated: 2025/01/08 18:12:09 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_integer(va_list args)
{
	int	n;
	int	n2;
	int	count;

	n = va_arg(args, int);
	n2 = n;
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	ft_putnbr_fd(n2, 1);
	return (count);
}

static void	ft_perform_uint(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_perform_uint(n / 10);
		ft_perform_uint(n % 10);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

int	ft_write_uinteger(va_list args)
{
	unsigned int	n;
	unsigned int	n2;
	int				count;

	n = va_arg(args, unsigned int);
	n2 = n;
	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	ft_perform_uint(n2);
	return (count);
}
