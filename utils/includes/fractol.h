/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:00:22 by angellop          #+#    #+#             */
/*   Updated: 2025/05/15 11:47:36 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include <math.h>
# include "libft.h"

# define TITLE "Fract-ol"
# define WIDTH 1280
# define HEIGHT 720
# define MAX_ITER 100

typedef struct program_s	t_program;
typedef struct camera_s		t_camera;

typedef struct color_s
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct complex_s
{
	double	re;
	double	im;
}	t_complex;

typedef struct camera_s
{
	t_program	*parent;
	mlx_image_t	*viewport;
	void		(*draw)(t_program*);
	double		x_offset;
	double		y_offset;
	double		center_x;
	double		center_y;
	double		zoom;
}	t_camera;

typedef struct program_s
{
	mlx_t		*context;
	int			(*algorithm)(t_complex z, t_complex c);
	t_complex	*z;
	t_complex	*c;
	t_camera	*main_camera;
}	t_program;

t_complex	pixel_to_complex(int x, int y, t_camera *view);
double		ft_atof(const char *str);
int			get_color(int iters);
void		t_complexo_pixel(t_camera *view, t_complex c, int *x, int *y);
int			julia(t_complex c, t_complex z);
int			mandelbrot(t_complex c, t_complex z);
void		draw_julia(t_program *program);
void		draw_mandelbrot(t_program *program);
int			get_rgba(int r, int g, int b, int a);
void		initialize_for_julia(t_program *program, int ac, char **av, int i);
void		initialize_for_mandelbrot(t_program *program);
char		*join_args(int i, int ac, char **av);
int			count_args(char *args);
t_complex	*args_to_complex(char *args_unified);
t_complex	*initialize_complex(float re, float im);
void		ft_abort(t_program *program, char *msg);




#endif
