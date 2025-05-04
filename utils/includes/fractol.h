/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:00:22 by angellop          #+#    #+#             */
/*   Updated: 2025/05/04 10:47:33 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define MAX_ITER 100

typedef struct color_s
{
	int	r;
	int	g;
	int	b;
	int	a;
}	color_t;

typedef struct complex_s
{
	double	re;
	double	im;
}	complex_t;

typedef struct divalue
{

}	pixel_t;

typedef struct camera_s {
	double	zoom;
	double	x_offset;
	double	y_offset;
} camera_t;

#endif