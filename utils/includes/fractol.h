/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:00:22 by angellop          #+#    #+#             */
/*   Updated: 2025/05/06 13:12:12 by angellop         ###   ########.fr       */
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
# define HEIGHT 1280
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
	float	re;
	float	im;
}	complex_t;

typedef struct camera_s {
	mlx_t		*context;
	mlx_image_t	*context_img;
	float		zoom;
	float		x_offset;
	float		y_offset;
} camera_t;

#endif