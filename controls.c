/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:18:41 by angellop          #+#    #+#             */
/*   Updated: 2025/05/18 08:59:02 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	free_resources(void *param)
{
	t_program	*program;

	program = (t_program *) param;
	free(program->c);
	free(program->z);
	ft_abort(program, "");
}

static void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_program	*program;
	t_complex	before;
	t_complex	after;
	int32_t		mouse_x;
	int32_t		mouse_y;

	mouse_x = 0;
	mouse_y = 0;
	(void) xdelta;
	program = (t_program *) param;
	mlx_get_mouse_pos(program->context, &mouse_x, &mouse_y);
	before = pixel_to_complex(mouse_x, mouse_y, program->main_camera);
	if (ydelta > 0)
		program->main_camera->zoom *= 1.1;
	else if (ydelta < 0)
		program->main_camera->zoom /= 1.1;
	after = pixel_to_complex(mouse_x, mouse_y, program->main_camera);
	program->main_camera->x_offset += before.re - after.re;
	program->main_camera->y_offset += before.im - after.im;
	program->main_camera->draw(program);
}

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_program	*program;
	t_camera	*cam;
	double		move_step;

	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	program = (t_program *) param;
	cam = program->main_camera;
	move_step = 20.0 / cam->zoom;
	if (keydata.key == MLX_KEY_UP)
		cam->y_offset -= move_step;
	else if (keydata.key == MLX_KEY_DOWN)
		cam->y_offset += move_step;
	else if (keydata.key == MLX_KEY_LEFT)
		cam->x_offset -= move_step;
	else if (keydata.key == MLX_KEY_RIGHT)
		cam->x_offset += move_step;
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		program->palette_id = (program->palette_id + 1) % N_PALETTES;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_resources(program);
	else
		return ;
	cam->draw(program);
}

void	attach_controls(t_program *program)
{
	mlx_scroll_hook(program->context, scroll_handler, (void *) program);
	mlx_key_hook(program->context, key_handler, (void *) program);
	mlx_close_hook(program->context, free_resources, program);
}
