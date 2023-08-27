/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:01:28 by harsh             #+#    #+#             */
/*   Updated: 2023/08/27 16:10:43 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	adjust_view(t_fractol *fractol, double x_range, double y_range)
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

	x_range = 0.0;
	y_range = 0.0;
	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT
		|| key.key == 'A' || key.key == 'D')
		x_range = (fractol->xmax - fractol->xmin) * fractol->pan_factor
			* ((key.key == MLX_KEY_LEFT || key.key == 'A')
				- (key.key == MLX_KEY_RIGHT || key.key == 'D'));
	if (key.key == MLX_KEY_UP || key.key == MLX_KEY_DOWN
		|| key.key == 'W' || key.key == 'S')
		y_range = (fractol->ymax - fractol->ymin) * fractol->pan_factor
			* ((key.key == MLX_KEY_UP || key.key == 'W')
				- (key.key == MLX_KEY_DOWN || key.key == 'S'));
	adjust_view(fractol, x_range, y_range);
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(fractol);
	if (key.key == 'R')
		init(fractol, fractol->type);
	handle_color(key, fractol);
	select_fractol(fractol, fractol->type);
}

void	handle_color(mlx_key_data_t key, t_fractol *fractol)
{
	static int	count = 0;

	if (key.key == MLX_KEY_C && key.action == MLX_PRESS)
	{
		count++;
		if (count % 4 == 1)
			fractol->color_fun = &color_fall;
		else if (count % 4 == 2)
			fractol->color_fun = &color_mandelbrot;
		else if (count % 4 == 3)
			fractol->color_fun = &color_julia;
		else
		{
			fractol->color_fun = &color_fern;
			count = 0;
		}
	}
}

static void	zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	x_math;
	double	y_math;
	double	new_x_range;
	double	new_y_range;

	x_math = fractol->xmin + ((double)x / WIDTH)
		* (fractol->xmax - fractol->xmin);
	y_math = fractol->ymin + (1 - (double)y / HEIGHT)
		* (fractol->ymax - fractol->ymin);
	new_x_range = (fractol->xmax - fractol->xmin) / zoom_factor;
	new_y_range = (fractol->ymax - fractol->ymin) / zoom_factor;
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
		zoom(fractol, mouse_x, mouse_y, 1 / zoom_level);
	select_fractol(fractol, fractol->type);
}
