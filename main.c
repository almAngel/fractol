/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:27 by angellop          #+#    #+#             */
/*   Updated: 2025/05/04 11:30:22 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static complex_t pixel_to_complex(int x, int y, camera_t *view)
{
	complex_t	c;
	float		center_x;
	float		center_y;

	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	c.re = (x - center_x) / view->zoom + view->x_offset;
	c.im = (y - center_y) / view->zoom + view->y_offset;

	return (c);
}

static int mandelbrot(complex_t c)
{
	complex_t	z = {0, 0};
	int			i;
	double		temp_re;

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

static int julia(complex_t c)
{
	complex_t	z = {0, 0};
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

static void draw_fractal(mlx_image_t *img, camera_t *view)
{
	complex_t c;
	int iters;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			c = pixel_to_complex(x, y, view);
			iters = mandelbrot(c);
			// TODO int color = get_color(iters);
			//mlx_put_pixel(img, x, y, color);
		}
	}
}

int	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	// draw_fractal(img);
	mlx_loop(mlx);
	mlx_is_key_down(mlx, MLX_KEY_ESCAPE);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}