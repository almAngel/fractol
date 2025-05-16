/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:50 by angellop          #+#    #+#             */
/*   Updated: 2025/05/16 12:09:41 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_for_julia(t_program *program, int ac, char **av, int i)
{
	int			arg_count;
	char		*args;

	args = join_args(i++, ac, av);
	arg_count = count_args(args);
	if (arg_count < 2)
	{
		free(args);
		ft_abort(program, \
			"Error: Not enough arguments to create a complex. Reverting...");
	}
	else if (arg_count > 2)
	{
		free(args);
		ft_abort(program, \
			"Error: Too many arguments. Reverting...");
	}
	program->algorithm = julia;
	program->main_camera->draw = draw_julia;
	free(program->c);
	program->c = args_to_complex(args);
	free(args);
}

int	julia(t_complex z, t_complex c)
{
	int			i;
	float		tmp_re;

	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp_re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp_re;
		i++;
	}
	return (i);
}

void	draw_julia(t_program *program)
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
		iters = program->algorithm(pixel_to_complex(x, \
			y, program->main_camera), *program->c);
		color = get_color(iters, 1);
		mlx_put_pixel(program->main_camera->viewport, x, y, color);
		index++;
	}
}
