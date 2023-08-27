/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:14 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/27 16:09:18 by hkumbhan         ###   ########.fr       */
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
		return (0x272829);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x0000FFFF));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0x61677A));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0x008026FF));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0xD8D9DA));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0xFFFF00FF));
	else
		return (function(iterations, max_iter, 0xFFF6E0));
}
