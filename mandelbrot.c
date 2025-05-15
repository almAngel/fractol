/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:54 by angellop          #+#    #+#             */
/*   Updated: 2025/05/15 11:48:12 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_for_mandelbrot(t_program *program)
{
	program->algorithm = mandelbrot;
	program->main_camera->draw = draw_mandelbrot;
	program->z = initialize_complex(0, 0);
	program->c = initialize_complex(0, 0);
}

int	mandelbrot(t_complex c, t_complex z)
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
		iters = program->algorithm(pixel_to_complex(x, y, \
			program->main_camera), *program->c);
		color = get_color(iters);
		mlx_put_pixel(program->main_camera->viewport, x, y, color);
		index++;
	}
	ft_putendl_fd("> Mandelbrot fractal drawn", 1);
}
