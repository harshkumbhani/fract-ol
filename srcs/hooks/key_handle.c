/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:08:24 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 15:26:56 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	co_ordinates(t_fractol **fractol, double x_r, double y_r)
{
	(*fractol)->xmin += x_r;
	(*fractol)->xmax += x_r;
	(*fractol)->ymin += y_r;
	(*fractol)->ymax += y_r;
}

void	handle_key(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;
	double		x_range;
	double		y_range;

	fractol = (t_fractol *)param;
	x_range = (fractol->xmax - fractol->xmin) * fractol->pan_factor
		* ((key.key == MLX_KEY_LEFT) + (-1 * (key.key == MLX_KEY_RIGHT)));
	y_range = (fractol->ymax - fractol->ymin) * fractol->pan_factor
		* ((key.key == MLX_KEY_UP) + (-1 * (key.key == MLX_KEY_DOWN)));
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(fractol);
	if (key.key == 'R')
		init(fractol, fractol->name);
	co_ordinates(&fractol, x_range, y_range);
	draw_mandelbrot(fractol);
	//draw_fractol(&fractol->name, fractol);
}
