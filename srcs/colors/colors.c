/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:12:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/12 23:01:05 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	cosine_interpolation(double t)
{
	return ((1 - cos(t * M_PI)) / 2);
}

uint32_t	color_fern(int iterations, int max_iter)
{
	double	iter_norm;

	iter_norm = (double)iterations / max_iter;
	if (iterations == max_iter)
		return (0xFFFFFFFF);
	if (iter_norm <= 0.2)
		return (grad(iter_norm / 0.2, 0xFFFFFFFF, 0xADFF2FFF));
	if (iter_norm <= 0.6)
		return (grad((iter_norm - 0.2) / 0.4, 0xADFF2FFF, 0x00FF00FF));
	return (grad((iter_norm - 0.6) / 0.4, 0x00FF00FF, 0x006400FF));
}

uint32_t	color_julia(int iterations, int max_iter)
{
	double	iter_norm;

	iter_norm = (double)iterations / max_iter;
	if (iter_norm <= 0.02)
		return (grad(iter_norm / 0.02, 0x00001aFF, 0x00071aFF));
	if (iter_norm <= 0.05)
		return (grad((iter_norm - 0.02) / 0.03, 0x00071aFF, 0x00004dFF));
	if (iter_norm <= 0.1)
		return (grad((iter_norm - 0.05) / 0.05, 0x00004dFF, 0x027e97FF));
	if (iter_norm <= 0.18)
		return (grad((iter_norm - 0.1) / 0.08, 0x027e97FF, 0xFFFFFFFF));
	if (iter_norm <= 0.23)
		return (grad((iter_norm - 0.18) / 0.05, 0xFFFFFFFF, 0xFFE5CCFF));
	if (iter_norm <= 0.245)
		return (grad((iter_norm - 0.23) / 0.015, 0xFFE5CCFF, 0xFFAA55FF));
	if (iter_norm <= 0.28)
		return (grad((iter_norm - 0.245) / 0.035, 0xFFAA55FF, 0x00001EFF));
	if (iter_norm <= 0.34)
		return (grad((iter_norm - 0.28) / 0.06, 0x00001EFF, 0x00071aFF));
	if (iter_norm <= 0.4)
		return (grad((iter_norm - 0.34) / 0.06, 0x00071aFF, 0xbd640bFF));
	if (iter_norm <= 0.8)
		return (grad((iter_norm - 0.4) / 0.4, 0xbd640bFF, 0x027e97FF));
	return (grad((iter_norm - 0.8) / 0.2, 0x027e97FF, 0x000000FF));
}

uint32_t	color_mandelbrot(int iterations, int max_iter)
{
	double	iter_norm;

	iter_norm = (double)iterations / max_iter;
	if (iterations == max_iter)
		return (0x000000FF);
	else if (iter_norm <= 0.25)
		return (grad(iter_norm / 0.25, 0x00001aFF, 0x000099FF));
	else if (iter_norm <= 0.5)
		return (grad((iter_norm - 0.25) / 0.25,
				0x000099FF, 0x00b3b3FF));
	else if (iter_norm <= 0.75)
		return (grad((iter_norm - 0.5) / 0.25,
				0x00b3b3FF, 0x009900FF));
	else
		return (grad((iter_norm - 0.75) / 0.25,
				0x009900FF, 0x000000FF));
}

uint32_t	function(int iter, double max_iter, uint32_t color)
{
	uint32_t	start_color;
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	double		iter_norm;

	iter_norm = cosine_interpolation(iter / max_iter);
	(void)cosine_interpolation;
	start_color = 0x000000;
	iter_norm = iter / max_iter;
	b = (uint8_t)((1 - iter_norm) * ((start_color >> 16) & 0xFF)
			+ iter_norm * ((color >> 16) & 0xFF));
	g = (uint8_t)((1 - iter_norm) * ((start_color >> 8) & 0xFF)
			+ iter_norm * ((color >> 8) & 0xFF));
	r = (uint8_t)((1 - iter_norm) * ((start_color) & 0xFF)
			+ iter_norm * ((color) & 0xFF));
	return (b << 24 | g << 16 | r << 8 | 0xFF);
}

// uint32_t	color_julia(int iterations, int max_iter)
// {
// 	if (iterations == max_iter)
// 		return (0x000000FF);
// 	else if (iterations <= (double)max_iter * 0.02)
// 		return (function(iterations, max_iter * 0.02, 0x00001E));
// 	else if (iterations <= (double)max_iter * 0.05)
// 		return (function(iterations, max_iter * 0.05, 0x00144D));
// 	else if (iterations <= (double)max_iter * 0.1)
// 		return (function(iterations, max_iter * 0.1, 0x000080));
// 	else if (iterations <= (double)max_iter * 0.18)
// 		return (function(iterations, max_iter * 0.18, 0x1ed6fb));
// 	else if (iterations <= (double)max_iter * 0.23)
// 		return (function(iterations, max_iter * 0.23, 0xFFFFFFFF));
// 	else if (iterations <= (double)max_iter * 0.245)
// 		return (function(iterations, max_iter * 0.245, 0xFFE5CC));
// 	else if (iterations <= (double)max_iter * 0.28)
// 		return (function(iterations, max_iter * 0.28, 0xFFAA55));
// 	else if (iterations <= (double)max_iter * 0.34)
// 		return (function(iterations, max_iter * 0.34, 0x00001E));
// 	else if (iterations <= (double)max_iter * 0.4)
// 		return (function(iterations, max_iter * 0.4, 0x00144D));
// 	else if (iterations <= (double)max_iter * 0.8)
// 		return (function(iterations, max_iter * 0.8, 0xbd640b));
// 	else
// 		return (function(iterations, max_iter, 0x1ed6fb));
// }