/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:21:56 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/12 23:02:03 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	adjust_view(t_fractol *fractol, double x_range, double y_range)
{
	fractol->xmin += x_range;
	fractol->xmax += x_range;
	fractol->ymin += y_range;
	fractol->ymax += y_range;
}

static void	reset_colors(t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		fractol->color_fun = &color_mandelbrot;
	else if (fractol->type == JULIA)
		fractol->color_fun = &color_julia;
	else if (fractol->type == FERN)
		fractol->color_fun = &color_fern;
}

void	handle_color(t_fractol *fractol)
{
	static int	count = 0;

	if (mlx_is_key_down(fractol->img.mlx, MLX_KEY_C))
	{
		count++;
		if (count % 6 == 1)
			fractol->color_fun = &color_fall;
		else if (count % 6 == 2)
			fractol->color_fun = &color_space;
		else if (count % 6 == 3)
			fractol->color_fun = &color_milkyway;
		else if (count % 6 == 4)
			fractol->color_fun = &color_neon;
		else if (count % 6 == 5)
			fractol->color_fun = &color_flamingo;
		else
			reset_colors(fractol);
	}
}

void	check_translation(t_fractol *fractol)
{
	double		x_range;
	double		y_range;

	x_range = 0.0;
	y_range = 0.0;
	if (mlx_is_key_down(fractol->img.mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fractol->img.mlx, MLX_KEY_RIGHT))
		x_range = (fractol->xmax - fractol->xmin) * fractol->pan_factor
			* (mlx_is_key_down(fractol->img.mlx, MLX_KEY_LEFT)
				- mlx_is_key_down(fractol->img.mlx, MLX_KEY_RIGHT));
	if (mlx_is_key_down(fractol->img.mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fractol->img.mlx, MLX_KEY_DOWN))
		y_range = (fractol->ymax - fractol->ymin) * fractol->pan_factor
			* (mlx_is_key_down(fractol->img.mlx, MLX_KEY_DOWN)
				- mlx_is_key_down(fractol->img.mlx, MLX_KEY_UP));
	adjust_view(fractol, x_range, y_range);
}

void	handle_key(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(fractol);
	if (key.key == 'H' && key.action == MLX_PRESS)
		fractol->help_img->enabled = !fractol->help_img->enabled;
	if (fractol->help_img->enabled)
		return ;
	if (key.key == 'R')
	{
		init(fractol, fractol->type);
		reset_colors(fractol);
	}
}
