/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:00:22 by angellop          #+#    #+#             */
/*   Updated: 2025/05/18 09:07:21 by angellop         ###   ########.fr       */
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
# define WIDTH 700
# define HEIGHT 700
# define MAX_ITER 100
# define N_PALETTES 3

typedef struct s_program	t_program;
typedef struct s_camera		t_camera;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_camera
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

typedef struct s_program
{
	mlx_t		*context;
	int			(*algorithm)(t_complex z, t_complex c);
	t_complex	*z;
	t_complex	*c;
	t_camera	*main_camera;
	int			palette_id;
}	t_program;

t_complex	pixel_to_complex(int x, int y, t_camera *view);
double		ft_atof(const char *str);
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
t_complex	*initialize_complex(double re, double im);
void		ft_abort(t_program *program, char *msg);
void		attach_controls(t_program *program);
void		initialize_for_burning_ship(t_program *program);
uint32_t	get_color(int iters, int palette_id);

#endif
