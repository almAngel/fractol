/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:37:36 by angellop          #+#    #+#             */
/*   Updated: 2025/05/16 12:13:07 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	*initialize_color(double r, double g, double b, double a)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (0);
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
	return (color);
}

static void	palette_0(double t, t_color *color)
{
	color->r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
	color->g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
	color->b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

static void	palette_1(double t, t_color *color)
{
	color->r = (uint8_t)(sin(3.0 * t) * 127 + 128);
	color->g = (uint8_t)(sin(3.0 * t + 2.0) * 127 + 128);
	color->b = (uint8_t)(sin(3.0 * t + 4.0) * 127 + 128);
}

static void	palette_2(double t, t_color *color)
{
	color->r = (uint8_t)(255 * pow(t, 0.3));
	color->g = (uint8_t)(85 * pow(t, 0.5));
	color->b = (uint8_t)(20 * pow(t, 0.7));
}

uint32_t	get_color(int iters, int palette_id)
{
	t_color	*color;
	double	t;

	color = initialize_color(0, 0, 0, 255);
	if (iters == MAX_ITER)
		return (0x000000FF);
	t = (double)iters / MAX_ITER;
	if (palette_id == 0)
		palette_0(t, color);
	else if (palette_id == 1)
		palette_1(t, color);
	else
		palette_2(t, color);
	return (color->r << 24 | color->g << 16 | color->b << 8 | 255);
}
