/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:55:16 by angellop          #+#    #+#             */
/*   Updated: 2025/05/15 11:37:58 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_fractional(const char *str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (*(++str) == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			fraction += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;

	result = 0.0;
	sign = 1.0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1.0;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*(str++) - '0');
	return (sign * (result + ft_fractional(str)));
}

int	get_color(int iters)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (iters == MAX_ITER)
		return (get_rgba(0, 0, 0, 0));
	r = iters * 2;
	g = iters * 3;
	b = 255 - iters * 2;
	return (r << 24 | g << 16 | b << 8 | 255);
}

t_complex	pixel_to_complex(int x, int y, t_camera *view)
{
	t_complex	ni;

	ni.re = (x - view->center_x) / view->zoom + view->x_offset;
	ni.im = (y - view->center_y) / view->zoom + view->y_offset;
	return (ni);
}

// void	t_complexo_pixel(t_camera *view, t_complex c, int *x, int *y)
// {
// 	*x = (c.re - view->x_offset) * view->zoom + view->center_x;
// 	*y = (c.im - view->y_offset) * view->zoom + view->center_y;
// }

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
