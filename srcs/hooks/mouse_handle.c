/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:58:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 15:26:44 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double x_range;
	double y_range;
	double x_math;
	double y_math;
	double new_x_range;
	double new_y_range;

	x_range = fractol->xmax - fractol->xmin;
	y_range = fractol->ymax - fractol->ymin;
	x_math = fractol->xmin + ((double)x / WIDTH) * x_range;
	y_math = fractol->ymin + (1 - (double)y / HEIGHT) * y_range;
	new_x_range = x_range / zoom_factor;
	new_y_range = y_range / zoom_factor;
	fractol->xmin = x_math - ((double)x / WIDTH) * new_x_range;
	fractol->xmax = fractol->xmin + new_x_range;
	fractol->ymin = y_math - (1 - (double)y / HEIGHT) * new_y_range;
	fractol->ymax = fractol->ymin + new_y_range;
}

void	handle_mouse(double xdelta, double ydelta, void *param)
{
	double		zoom_level;
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	fractol = (t_fractol *)param;
	zoom_level = 1.42;
	mlx_get_mouse_pos(fractol->img.mlx, &mouse_x, &mouse_y);
	if (ydelta < 0)
		zoom(fractol, mouse_x, mouse_y, zoom_level);
	else if (ydelta > 0)
		zoom(fractol, mouse_x, mouse_y, 1/zoom_level);
	draw_mandelbrot(fractol);
}
