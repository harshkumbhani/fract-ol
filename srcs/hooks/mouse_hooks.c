/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:23:42 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/12 14:25:12 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (fractol->help_img->enabled)
		return ;
	if (ydelta < 0)
		zoom(fractol, mouse_x, mouse_y, zoom_level);
	else if (ydelta > 0)
		zoom(fractol, mouse_x, mouse_y, 1 / zoom_level);
	select_fractol(fractol, fractol->type);
}
