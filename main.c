/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:27 by angellop          #+#    #+#             */
/*   Updated: 2025/05/15 11:47:00 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_abort(t_program *program, char *msg)
{
	if (program)
	{
		if (program->c)
			free(program->c);
		if (program->z)
			free(program->z);
		free(program->context);
		free(program);
	}
	if (msg)
		ft_putendl_fd(msg, 2);
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static t_camera	*create_main_camera(t_program *program, float x_offset, \
	float y_offset, float zoom)
{
	t_camera	*main_camera;

	main_camera = malloc(sizeof(t_camera));
	if (!main_camera)
		exit(EXIT_FAILURE);
	main_camera->viewport = mlx_new_image(program->context, WIDTH, HEIGHT);
	main_camera->x_offset = x_offset;
	main_camera->y_offset = y_offset;
	main_camera->center_x = WIDTH / 2;
	main_camera->center_y = HEIGHT / 2;
	main_camera->zoom = zoom;
	return (main_camera);
}

static t_program	*init(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		exit(EXIT_FAILURE);
	program->context = mlx_init(WIDTH, HEIGHT, TITLE, false);
	program->main_camera = create_main_camera(program, 0, 0, 500);
	if (!program->context)
		ft_abort(program, "");
	if (!program->main_camera->viewport
		|| (mlx_image_to_window(program->context, \
			program->main_camera->viewport, 0, 0) < 0))
		ft_abort(program, "");
	return (program);
}

// static int	mandelbrot(t_complex c, t_complex z)
// {
// 	int			i;
// 	double		tmp_re;

// 	i = 0;
// 	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
// 	{
// 		tmp_re = z.re * z.re - z.im * z.im + c.re;
// 		z.im = 2 * z.re * z.im + c.im;
// 		z.re = tmp_re;
// 		i++;
// 	}
// 	return (i);
// }

// static int	choose_fractal_algorithm_ret_iters(char *algorithm, t_complex c)
// {
// 	if (ft_strncmp(algorithm, "mandelbrot", 10) == 0)
// 		return mandelbrot(c);
// 	else if (ft_strcmp(algorithm, "julia"))
// 		return julia(c);
// }

// static void	draw_fractal(mlx_image_t *img, int (*algorithm)(t_complex), t_complex c)
// {
// 	int32_t		iters;
// 	int32_t		color;
// 	int32_t		index;
// 	int32_t		area;
// 	int			x;
// 	int			y;

// 	index = 0;
// 	area = WIDTH * HEIGHT;
// 	while (index < area)
// 	{
// 		x = index % WIDTH;
// 		y = index / WIDTH;
// 		iters = algorithm(c);
// 		color = get_color(iters);
// 		mlx_put_pixel(img, x, y, color);
// 		index++;
// 	}
// }

// static void	draw_fractal(t_camera *view, int (*algorithm)(t_complex, t_complex))
// {
// 	int32_t		iters;
// 	int32_t		color;
// 	int32_t		index;
// 	int32_t		area;
// 	int			x;
// 	int			y;

// 	index = 0;
// 	area = WIDTH * HEIGHT;
// 	while (index < area)NULL
// 	{
// 		iters = algorithm(*view->sequence_start);
// 		color = get_color(iters);
// 		mlx_put_pixel(view->context_img, x, y, color);
// 		index++;
// 	}
// }

// static void	scroll_handler(double xdelta, double ydelta, void *param)
// {
// 	t_program	*program;
// 	t_complex	before;
// 	t_complex	after;
// 	int32_t		mouse_x;
// 	int32_t		mouse_y;

// 	mouse_x = 0;
// 	mouse_y = 0;
// 	(void)	xdelta;
// 	program = (t_program*) param;
// 	mlx_get_mouse_pos(program->context, &mouse_x, &mouse_y);
// 	before = pixel_to_complex(mouse_x, mouse_y, view);
// 	if (ydelta > 0)
// 		view->zoom *= 1.1;
// 	else if (ydelta < 0)
// 		view->zoom /= 1.1;
// 	after = pixel_to_complex(mouse_x, mouse_y, view);
// 	view->x_offset += before.re - after.re;
// 	view->y_offset += before.im - after.im;
// 	view->draw(view);
// }

// static void	key_handler(mlx_key_data_t keydata, void *param)
// {
// 	t_camera	*view;

// 	view = (t_camera *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
// 	{
// 		mlx_delete_image(view->context, view->context_img);
// 		mlx_terminate(view->context);
// 		exit(EXIT_SUCCESS);
// 	}
// }

// int	main(int ac, char **av)
// {
// 	char		*args;
// 	t_camera	view;
// 	view.x_offset = 0;
// 	view.y_offset = 0;
// 	view.context = mlx_init(WIDTH, HEIGHT, "Fractol", false);
// 	view.context_img = mlx_new_image(view.context, WIDTH, HEIGHT);
// 	view.zoom = 500;

// 	if (ac > 1)
// 	{
// 		if (ft_strncmp(av[1], "julia", 5) == 0)
// 		{
// 			args = join_args();
// 		}
// 		if (!view.context)
// 			ft_error();
// 		if (!view.context_img || (mlx_image_to_window(view.context, view.context_img, 0, 0) < 0))
// 			ft_error();
// 		draw_fractal(view.context_img, &view);
// 		mlx_scroll_hook(view.context, scroll_handler, (void *) &view);
// 		mlx_key_hook(view.context, key_haprogramndler, (void *)&view);
// 		mlx_loop(view.context);
// 		mlx_terminate(view.context);
// 	}
// 	else
// 		ft_error();
// 	return (EXIT_SUCCESS);
// }

// static void	calculate_position_in_viewport(int *x, int *y)
// {
// 	int32_t		index;
// 	int32_t		area;

// 	index = 0;
// 	area = WIDTH * HEIGHT;
// 	while (index < area)
// 	{
// 		*x = index % WIDTH;
// 		*y = index / WIDTH;
// 		index++;
// 	}
// }

static void	bootstrap_algorithm(int ac, char **av, t_program *program)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		if (ft_strncmp(av[i], "julia", 5) == 0)
			initialize_for_julia(program, ac, av, i);
		else if (ft_strncmp(av[i], "mandelbrot", 10) == 0)
			initialize_for_mandelbrot(program);
	}
	else
		ft_abort(program, "Error: Not enough arguments. \
			Returning control... \nCommand: ./fractol [algorithm] [?n] [?i]");
}

int main(int ac, char **av)
{
	t_program	*program;

	program = init();
	bootstrap_algorithm(ac, av, program);
	program->main_camera->draw(program);
	// mlx_scroll_hook(program->context, scroll_handler, (void *) program);
	// mlx_key_hook(view.context, key_handler, (void *)&view);
	mlx_loop(program->context);
	mlx_terminate(program->context);

	return (EXIT_SUCCESS);
}
