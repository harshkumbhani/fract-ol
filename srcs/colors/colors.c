/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:12:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/18 16:43:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	color_pix(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000FF);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x732982FF));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0x24408EFF));
	else if (iterations <= (double)max_iter * 0.15)
		return  (function(iterations, max_iter * 0.15, 0x008026FF));
	else if (iterations <= (double)max_iter * 0.4)
		return function(iterations, max_iter * 0.4, 0xFFED00FF);
	else if (iterations <= (double)max_iter * 0.8)
		return function(iterations, max_iter * 0.8, 0xFF8C00FF);
	else
		return(function(iterations, max_iter, 0xE40303));
}

u_int32_t function(int iter, double max_iter, uint32_t color)
{
	uint32_t	start_color = 0x000000;
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	double		iter_norm = iter / max_iter;

	b = (uint8_t)((1 - iter_norm) * ((start_color >> 16) & 0xFF) +
			iter_norm * ((color >> 16) & 0xFF));
	g = (uint8_t)((1 - iter_norm) * ((start_color >> 8) & 0xFF) +
			iter_norm * ((color >> 8) & 0xFF));
	r = (uint8_t)((1 - iter_norm) * ((start_color) & 0xFF) +
			iter_norm * ((color) & 0xFF));
	return (b << 24 | g << 16 | r << 8 | 0xFF);
}
