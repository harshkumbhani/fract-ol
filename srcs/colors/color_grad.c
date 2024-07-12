/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_grad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:14:27 by harsh             #+#    #+#             */
/*   Updated: 2024/07/12 13:41:08 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	cosine_interpolation(double t)
{
	return ((1 - cos(t * M_PI)) / 2);
}

uint32_t	grad(double iter_norm,
			uint32_t start_color, uint32_t end_color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	iter_norm = cosine_interpolation(iter_norm);
	r = (uint8_t)((1 - iter_norm) * ((start_color >> 24) & 0xFF)
			+ iter_norm * ((end_color >> 24) & 0xFF));
	g = (uint8_t)((1 - iter_norm) * ((start_color >> 16) & 0xFF)
			+ iter_norm * ((end_color >> 16) & 0xFF));
	b = (uint8_t)((1 - iter_norm) * ((start_color >> 8) & 0xFF)
			+ iter_norm * ((end_color >> 8) & 0xFF));
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

// uint32_t	color_grad(int iterations, int max_iter)
// {
// 	double	iter_norm;

// 	iter_norm = (double)iterations / max_iter;
// 	if (iterations == max_iter)
// 		return (0x000000FF);
// 	else if (iter_norm <= 0.25)
// 		return (function_grad(iter_norm / 0.25, 0x000033FF, 0x0000FFFF));
// 	else if (iter_norm <= 0.5)
// 		return (function_grad((iter_norm - 0.25) / 0.25,
// 				0x0000FFFF, 0x00FFFFFF));
// 	else if (iter_norm <= 0.75)
// 		return (function_grad((iter_norm - 0.5) / 0.25,
// 				0x00FFFFFF, 0x00FF00FF));
// 	else
// 		return (function_grad((iter_norm - 0.75) / 0.25,
// 				0x00FF00FF, 0x000000FF));
// }

// Extra Color combination
// uint32_t color_grad(int iterations, int max_iter, t_gradient_state *state) {
//     double iter_norm = (double)iterations / max_iter;
// 	(void)state;
//     if (iterations == max_iter)
//         return (0x000000FF);
//     else if (iter_norm <= 0.02)
//         return (function_grad(iter_norm / 0.02, 0x000000FF, 0x732982FF));
//     else if (iter_norm <= 0.05)
//         return (function_grad((iter_norm - 0.02) / 0.03,
//					0x732982FF, 0x24408EFF));
//     else if (iter_norm <= 0.15)
//         return (function_grad((iter_norm - 0.05) / 0.10,
//					0x24408EFF, 0x008026FF));
//     else if (iter_norm <= 0.4)
//         return (function_grad((iter_norm - 0.15) / 0.25,
//					0x008026FF, 0xFFED00FF));
//     else if (iter_norm <= 0.8)
//         return (function_grad((iter_norm - 0.4) / 0.4,
//					0xFFED00FF, 0xFF8C00FF));
//     else
//         return (function_grad((iter_norm - 0.8) / 0.2,
//					0xFF8C00FF, 0xE40303FF));
// }