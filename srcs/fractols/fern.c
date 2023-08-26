/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:57:03 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/26 18:55:19 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_delete_pixel(t_fractol *image)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(image->img.img, x, y, 0x00000000);
	}
}

void	fern_calculations(t_fractol *fern, int f)
{
	if (f == 1)
	{
		fern->zx = 0;
		fern->zy = 0.16 * fern->zy;
	}
	if (f == 2)
	{
		fern->zx = 0.85 * fern->zx + 0.04 * fern->zy;
		fern->zy = -0.04 * fern->zx + 0.85 * fern->zy + 1.6;
	}
	if (f == 3)
	{
		fern->zx = 0.20 * fern->zx - 0.26 * fern->zy;
		fern->zy = 0.23 * fern->zx + 0.22 * fern->zy + 1.6;
	}
	if (f == 4)
	{
		fern->zx = -0.15 * fern->zx + 0.28 * fern->zy;
		fern->zy = 0.26 * fern->zx + 0.24 * fern->zy + 0.44;
	}
}

void	draw_fern(t_fractol *fern)
{
	int		n;
	double	r;

	n = 0;
	srand(time(NULL));
	mlx_delete_pixel(fern);
	while (n < fern->max_iter)
	{
		r = (double)rand() / RAND_MAX;
		if (r < 0.01)
			fern_calculations(fern, 1);
		else if (r < 0.86)
			fern_calculations(fern, 2);
		else if (r < 0.93)
			fern_calculations(fern, 3);
		else
			fern_calculations(fern, 4);
		fern->x = (fern->zx - fern->xmin) / (fern->xmax - fern->xmin) * WIDTH;
		fern->y = HEIGHT - (fern->zy - fern->ymin)
			/ (fern->ymax - fern->ymin) * HEIGHT;
		if (fern->x >= 0 && fern->x < WIDTH && fern->y >= 0 && fern->y < HEIGHT)
			mlx_put_pixel(fern->img.img, fern->x, fern->y,
				color_fern(n, fern->max_iter));
		n++;
	}
}
