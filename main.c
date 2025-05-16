/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:27 by angellop          #+#    #+#             */
/*   Updated: 2025/05/16 12:14:23 by angellop         ###   ########.fr       */
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
		mlx_delete_image(program->context, program->main_camera->viewport);
		if (program->main_camera)
			free(program->main_camera);
		mlx_terminate(program->context);
		free(program);
	}
	if (msg)
		ft_putendl_fd(msg, 2);
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_SUCCESS);
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
		ft_abort(NULL, "");
	program->context = mlx_init(WIDTH, HEIGHT, TITLE, false);
	program->main_camera = create_main_camera(program, 0, 0, 500);
	program->c = initialize_complex(0, 0);
	program->z = initialize_complex(0, 0);
	if (!program->context)
		ft_abort(program, "");
	if (!program->main_camera->viewport
		|| (mlx_image_to_window(program->context, \
			program->main_camera->viewport, 0, 0) < 0))
		ft_abort(program, "");
	return (program);
}

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
		else if (ft_strncmp(av[i], "burning_ship", 12) == 0)
			initialize_for_burning_ship(program);
		else
			ft_abort(program, "This is not serious... Returning control.");
	}
	else
	{
		ft_putendl_fd("Error: Not enough arguments. Returning control...", 2);
		ft_putendl_fd("Commands:", 2);
		ft_putendl_fd("	./fractol julia [?n] [?i]", 2);
		ft_putendl_fd("	./fractol mandelbrot", 2);
		ft_putendl_fd("	./fractol burning_ship", 2);
		ft_abort(program, "");
	}
}

int	main(int ac, char **av)
{
	t_program	*program;

	program = init();
	bootstrap_algorithm(ac, av, program);
	program->main_camera->draw(program);
	attach_controls(program);
	mlx_loop(program->context);
	mlx_terminate(program->context);
	return (EXIT_SUCCESS);
}
