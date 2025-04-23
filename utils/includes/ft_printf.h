/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:35:19 by angellop          #+#    #+#             */
/*   Updated: 2025/04/09 17:39:55 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_write_integer(va_list args);
int	ft_write_uinteger(va_list args);
int	ft_write_str(va_list args);
int	ft_write_char(va_list args);
int	ft_write_hex(char rule, va_list args);
int	ft_write_ptr(va_list args);
int	ft_write_percent(void);

#endif