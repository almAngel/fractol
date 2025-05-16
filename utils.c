/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:55:16 by angellop          #+#    #+#             */
/*   Updated: 2025/05/16 12:16:08 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *) str;
	res = (double) ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double) ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res > 0)
		return (res + res2);
	return (res - res2);
}

t_complex	pixel_to_complex(int x, int y, t_camera *view)
{
	t_complex	ni;

	ni.re = (x - view->center_x) / view->zoom + view->x_offset;
	ni.im = (y - view->center_y) / view->zoom + view->y_offset;
	return (ni);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
