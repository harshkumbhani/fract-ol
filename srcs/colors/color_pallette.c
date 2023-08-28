/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:14 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/28 17:40:29 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	color_fall(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000FF);
	else if (iterations <= (double)max_iter * 0.2)
		return (function(iterations, max_iter * 0.2, 0xEAC696));
	else if (iterations <= (double)max_iter * 0.6)
		return (function(iterations, max_iter * 0.6, 0xC8AE7D));
	else
		return (function(iterations, max_iter, 0x765827));
}

uint32_t	color_space(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x1E002A));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0x4D148C));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0x800080));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0xFF66B2));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0xFFFFFF));
	else
		return (function(iterations, max_iter, 0xDDA0DD));
}

uint32_t	color_milkyway(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x1E1E3F));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0x2E2E6E));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0x4B4B9A));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0x6E6ECF));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0x9A9AFF));
	else
		return (function(iterations, max_iter, 0xCFCFFF));
}

uint32_t	color_neon(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x0b3d91);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x8c00ff));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0xff0072));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0x00ffea));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0xffb400));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0xff4800));
	else
		return (function(iterations, max_iter, 0x0b3d91));
}

uint32_t	color_flamingo(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000FF);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0xFC8F9B));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0xF765A3));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0xE5317A));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0x9D347A));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0x5B345E));
	else
		return (function(iterations, max_iter, 0xFFFFFF));
}
