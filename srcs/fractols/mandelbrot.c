/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:15:52 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 15:21:22 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractol *mb)
{
	//mb->x = 0;
	mb->name = "Mandelbrot";
	while (++mb->x < WIDTH)
	{
		mb->y = -1;
		while (++mb->y < HEIGHT)
		{
			mb->zx = 0;
			mb->zy = 0;
			mb->max_iter = MAX_ITERATIONS * (mb->zoom * mb->zoom);
			mb->c_re = mb->xmin + (mb->xmax - mb->xmin) * mb->x / (WIDTH);
			mb->c_im = mb->ymax - (mb->ymax - mb->ymin) * mb->y / (HEIGHT);
			mb->iter = 0;
			while (mb->zx * mb->zx + mb->zy * mb->zy < 4
				&& mb->iter < mb->max_iter)
			{
				mb->tmp = 2.0 * mb->zx * mb->zy;
				mb->zx = mb->zx * mb->zx - mb->zy * mb->zy + mb->c_re;
				mb->zy = mb->tmp + mb->c_im;
				mb->iter++;
			}
			mlx_put_pixel(mb->img.img, mb->x, mb->y,
				color_pix(mb->iter, mb->max_iter));
		}
	}
}
