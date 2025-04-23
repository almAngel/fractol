/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:40:55 by angellop          #+#    #+#             */
/*   Updated: 2025/01/08 18:11:34 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	decision_tree(char rule, va_list args)
{
	int	count;

	count = 0;
	if (rule == '%')
		count += ft_write_percent();
	else if (rule == 'd' || rule == 'i')
		count += ft_write_integer(args);
	else if (rule == 'u')
		count += ft_write_uinteger(args);
	else if (rule == 'x' || rule == 'X')
		count += ft_write_hex(rule, args);
	else if (rule == 'p')
		count += ft_write_ptr(args);
	else if (rule == 's')
		count += ft_write_str(args);
	else if (rule == 'c')
		count += ft_write_char(args);
	else
		count += write(1, &rule, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += decision_tree(format[i + 1], args);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	char *format;
// 	// unsigned int u = 341945;

// 	format = " %X ";
// 	// printf("String: '%s' \n", s, "A");
// 	// printf("Nº tokens: %zu\n", ft_count_tokens(s));
// 	// printf("%s\n", itoh(0));
// 	// printf("%lu\n", sizeof(unsigned int));
// 	// printf("%lu\n", sizeof(int));
// 	int count = ft_printf(format, 0);

// 	printf("\nTotal written: %d\n", count);
// }
