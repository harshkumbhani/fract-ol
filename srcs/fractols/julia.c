/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:58:50 by harsh             #+#    #+#             */
/*   Updated: 2024/07/11 11:37:03 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *jla)
{
	jla->x = -1;
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
				jla->color_fun(jla->iter, jla->max_iter));
		}
	}
}
