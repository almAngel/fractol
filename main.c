/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:27 by angellop          #+#    #+#             */
/*   Updated: 2025/05/06 12:29:24 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static complex_t	pixel_to_complex(int x, int y, camera_t *view)
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

static int	mandelbrot(complex_t c)
{
	complex_t	z;
	int			i;
	double		tmp_re;

	i = 0;
	z = (complex_t) {0, 0};
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp_re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp_re;
		i++;
	}
	return (i);
}

// static int julia(complex_t c)
// {
// 	complex_t	z = {0, 0};
// 	int			i;
// 	float		temp_re;

// 	i = 0;
// 	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
// 	{
// 		temp_re = z.re * z.re - z.im * z.im + c.re;
// 		z.im = 2 * z.re * z.im + c.im;
// 		z.re = temp_re;
// 		i++;
// 	}
// 	return (i);
// }

static int	get_color(int iters) {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

    if (iters == 100)
        return 0x000000FF;
    r = iters * 2;
    g = iters * 3;
    b = 255 - iters * 2;

	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	draw_fractal(mlx_image_t *img, camera_t *view)
{
	complex_t	c;
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
		c = pixel_to_complex(x, y, view);
		iters = mandelbrot(c);
		color = get_color(iters);
		mlx_put_pixel(img, x, y, color);
		index++;
	}
}

static void	scroll_handler(double xdelta, double ydelta, void *param) {
	camera_t*	view;
	complex_t	before;
	complex_t	after;
	int32_t		mouse_x;
	int32_t		mouse_y;
	
	mouse_x = 0;
	mouse_y = 0;
	(void)	xdelta;
	view = (camera_t*) param;
	mlx_get_mouse_pos(view->context, &mouse_x, &mouse_y);
	before = pixel_to_complex(mouse_x, mouse_y, view);
	if (ydelta > 0)
		view->zoom *= 1.1;
	else if (ydelta < 0)
		view->zoom /= 1.1;
	after = pixel_to_complex(mouse_x, mouse_y, view);
	view->x_offset += before.re - after.re;
	view->y_offset += before.im - after.im;
	draw_fractal(view->context_img, view);
}

int	main(void)
{
	camera_t view;
	view.x_offset = 0;
	view.y_offset = 0;
	view.context = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	view.context_img = mlx_new_image(view.context, WIDTH, HEIGHT);
	view.zoom = 500;

	if (!view.context)
		ft_error();
	if (!view.context_img || (mlx_image_to_window(view.context, view.context_img, 0, 0) < 0))
		ft_error();
	draw_fractal(view.context_img, &view);
	mlx_scroll_hook(view.context, scroll_handler, (void *) &view);
	if (mlx_is_key_down(view.context, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(view.context, view.context_img);
		mlx_terminate(view.context);
		exit (EXIT_SUCCESS);
	}
	mlx_loop(view.context);
	mlx_terminate(view.context);
	return (EXIT_SUCCESS);
}