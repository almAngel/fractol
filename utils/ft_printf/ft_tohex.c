/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:40:04 by angellop          #+#    #+#             */
/*   Updated: 2025/01/08 18:14:32 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoh(unsigned int n)
{
	char			*hex;
	unsigned int	n_cpy;
	int				len;
	char			c;

	len = 0;
	n_cpy = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n_cpy != 0)
	{
		len++;
		n_cpy /= 16;
	}
	hex = ft_calloc(len + 1, 1);
	while (len--)
	{
		if ((n % 16) > 9)
			c = 'a' + ((n % 16) % 10);
		else
			c = '0' + ((n % 16) % 10);
		hex[len] = c;
		n /= 16;
	}
	return (hex);
}

static char	*ft_ptrtoh(uintptr_t n)
{
	char		*hex;
	uintptr_t	n_cpy;
	int			len;
	char		c;

	len = 0;
	n_cpy = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n_cpy != 0)
	{
		len++;
		n_cpy /= 16;
	}
	hex = ft_calloc(len + 1, 1);
	while (len--)
	{
		if ((n % 16) > 9)
			c = 'a' + ((n % 16) % 10);
		else
			c = '0' + ((n % 16) % 10);
		hex[len] = c;
		n /= 16;
	}
	return (hex);
}

int	ft_write_hex(char rule, va_list args)
{
	char	*hex;
	int		len;
	int		count;
	int		i;

	i = 0;
	count = 0;
	hex = ft_itoh(va_arg(args, unsigned int));
	len = ft_strlen(hex);
	if (rule == 'X')
	{
		while (hex[i])
		{
			hex[i] = ft_toupper(hex[i]);
			i++;
		}
	}
	count += write(1, hex, len);
	free(hex);
	return (count);
}

int	ft_write_ptr(va_list args)
{
	uintptr_t	addr;
	char		*hex;
	int			len;
	int			count;

	len = 0;
	hex = 0;
	count = 0;
	addr = va_arg(args, uintptr_t);
	if (addr != 0)
	{
		hex = ft_ptrtoh(addr);
		len = ft_strlen(hex);
		count += write(1, "0x", 2);
		count += write(1, hex, len);
	}
	else
		count += write(1, "(nil)", 5);
	free(hex);
	return (count);
}
