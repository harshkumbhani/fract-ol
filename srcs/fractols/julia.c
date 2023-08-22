/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:00:30 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 15:21:47 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *jla, double c_re, double c_im)
{
	jla->name = "Julia";
	jla->c_re = c_re;
	jla->c_im = c_im;
	while (++jla->x < WIDTH)
	{
		jla->y = -1;
		while (++jla->y < HEIGHT)
		{
			jla->zx = jla->xmin + (jla->xmax - jla->xmin) * jla->x / (WIDTH);
			jla->zy = jla->ymax - (jla->ymax - jla->ymin) * jla->y / (HEIGHT);
			jla->max_iter = MAX_ITERATIONS * (jla->zoom * jla->zoom);
			jla->iter = 0;
			while (jla->zx * jla->zx + jla->zy * jla->zy < 4
				&& jla->iter < jla->max_iter)
			{
				jla->tmp = 2.0 * jla->zx * jla->zy;
				jla->zx = jla->zx * jla->zx - jla->zy * jla->zy + jla->c_re;
				jla->zy = jla->tmp + jla->c_im;
				jla->iter++;
			}
			mlx_put_pixel(jla->img.img, jla->x, jla->y,
				color_pix(jla->iter, jla->max_iter));
		}
	}
}
