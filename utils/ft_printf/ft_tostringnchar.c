/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostringnchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:02:25 by angellop          #+#    #+#             */
/*   Updated: 2025/01/08 18:15:03 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(va_list args)
{
	char	*s;
	int		len;
	int		count;

	count = 0;
	s = va_arg(args, char *);
	if (s)
	{
		len = ft_strlen(s);
		count += write(1, s, len);
	}
	else
		count += write(1, "(null)", 6);
	return (count);
}

int	ft_write_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_write_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
