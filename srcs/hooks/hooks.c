/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:01:28 by harsh             #+#    #+#             */
/*   Updated: 2023/08/25 15:55:40 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void adjust_view(t_fractol *fractol, double x_range, double y_range)
{
	fractol->xmin += x_range;
	fractol->xmax += x_range;
	fractol->ymin += y_range;
	fractol->ymax += y_range;
}

void	handle_key(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;
	double		x_range;
	double		y_range;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
		x_range = (fractol->xmax - fractol->xmin) * fractol->pan_factor
			* ((key.key == MLX_KEY_LEFT) - (key.key == MLX_KEY_RIGHT));
	if (key.key == MLX_KEY_UP || key.key == MLX_KEY_DOWN)
		y_range = (fractol->ymax - fractol->ymin) * fractol->pan_factor
			* ((key.key == MLX_KEY_UP) - (key.key == MLX_KEY_DOWN));
	adjust_view(fractol, x_range, y_range);
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(fractol);
	if (key.key == 'R')
		init(fractol);
	// _put_pixel(fractol);
	select_fractol(fractol, fractol->type);
}

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
	// _put_pixel(fractol);
	select_fractol(fractol, fractol->type);
}