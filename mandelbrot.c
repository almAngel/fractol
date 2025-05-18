/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:54 by angellop          #+#    #+#             */
/*   Updated: 2025/05/18 08:02:50 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_for_mandelbrot(t_program *program)
{
	program->algorithm = mandelbrot;
	program->main_camera->draw = draw_mandelbrot;
	program->z = initialize_complex(0, 0);
	program->c = initialize_complex(0, 0);
	program->palette_id = 0;
}

int	mandelbrot(t_complex z, t_complex c)
{
	int			i;
	float		temp_re;

	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		temp_re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp_re;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_program *program)
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
		iters = program->algorithm(*program->c, pixel_to_complex(x, y, \
			program->main_camera));
		color = get_color(iters, program->palette_id);
		mlx_put_pixel(program->main_camera->viewport, x, y, color);
		index++;
	}
}
