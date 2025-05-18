/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:55:10 by angellop          #+#    #+#             */
/*   Updated: 2025/05/18 08:03:05 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_abs(double n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

static int	burning_ship(t_complex c, t_complex z)
{
	int			i;
	float		temp_re;

	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		z.re = ft_abs(z.re);
		z.im = ft_abs(z.im);
		temp_re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp_re;
		i++;
	}
	return (i);
}

static void	draw_burning_ship(t_program *program)
{
	int32_t		iters;
	int32_t		color;
	int32_t		index;
	int			x;
	int			y;

	index = 0;
	while (index < WIDTH * HEIGHT)
	{
		x = index % WIDTH;
		y = index / WIDTH;
		iters = program->algorithm(pixel_to_complex(x, y, \
			program->main_camera), *program->c);
		color = get_color(iters, program->palette_id);
		mlx_put_pixel(program->main_camera->viewport, x, y, color);
		index++;
	}
}

void	initialize_for_burning_ship(t_program *program)
{
	program->algorithm = burning_ship;
	program->main_camera->draw = draw_burning_ship;
	program->z = initialize_complex(0, 0);
	program->c = initialize_complex(0, 0);
	program->palette_id = 2;
}
