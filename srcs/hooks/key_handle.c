/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:08:24 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 13:37:14 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//static void	calculate_translation(t_fractol **fractol, int key, int x_range, int y_range)
//{
//	if (key == LEFT)
//	{
//		(*fractol)->xmin += x_range * (*fractol)->pan_factor;
//		(*fractol)->xmax += x_range * (*fractol)->pan_factor;
//	}
//	if (key == RIGHT)
//	{
//		(*fractol)->xmin -= x_range * (*fractol)->pan_factor;
//		(*fractol)->xmax -= x_range * (*fractol)->pan_factor;
//	}
//	if (key == UP)
//	{
//		(*fractol)->ymin -= y_range * (*fractol)->pan_factor;
//		(*fractol)->ymax -= y_range * (*fractol)->pan_factor;
//	}
//	if (key == DOWN)
//	{
//		(*fractol)->ymin += y_range * (*fractol)->pan_factor;
//		(*fractol)->ymax += y_range * (*fractol)->pan_factor;
//	}
//	printf("xmin : %f, xmax : %f\nymin : %f, ymax : %f\n",
//			(*fractol)->xmin, (*fractol)->xmax, (*fractol)->ymin, (*fractol)->ymax);
//}

void	handle_key(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;
	double		x_range;
	double		y_range;

	fractol = (t_fractol *)param;
	x_range = fractol->xmax - fractol->xmin;
	y_range = fractol->ymax - fractol->ymin;
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(fractol);
	if (key.key == 'R')
		init(fractol, fractol->name);
	fractol->xmin += x_range * fractol->pan_factor *
			((key.key == MLX_KEY_LEFT) + ( -1 * (key.key == MLX_KEY_RIGHT)));
	fractol->xmax += x_range * fractol->pan_factor *
			((key.key == MLX_KEY_LEFT) + ( -1 * (key.key == MLX_KEY_RIGHT)));
	fractol->ymin += y_range * fractol->pan_factor *
			((key.key == MLX_KEY_UP) + ( -1 * (key.key == MLX_KEY_DOWN)));
	fractol->ymax += y_range * fractol->pan_factor *
			((key.key == MLX_KEY_UP) + ( -1 * (key.key == MLX_KEY_DOWN)));
	_put_pixel(fractol);
}

	//if (key.key == MLX_KEY_LEFT)
	//{
	//	//calculate_translation(&fractol, 1, x_range, y_range);
	//	fractol->xmin += x_range * fractol->pan_factor * ((key.key == MLX_KEY_LEFT) + ( -1 * key.key == MLX_KEY_RIGHT));
	//	fractol->xmax += x_range * fractol->pan_factor * ((key.key == MLX_KEY_LEFT) + ( -1 * key.key == MLX_KEY_RIGHT));
	//}
	//if (key.key == MLX_KEY_RIGHT)
	//{
	//	//calculate_translation(&fractol, 2, x_range, y_range);
	//	fractol->xmin -= x_range * fractol->pan_factor;
	//	fractol->xmax -= x_range * fractol->pan_factor;
	//}
	//if (key.key == MLX_KEY_UP)
	//{
	//	//calculate_translation(&fractol, 3, x_range, y_range);
	//	fractol->ymin -= y_range * fractol->pan_factor * ((key.key == MLX_KEY_UP) + ( -1 * key.key == MLX_KEY_DOWN));
	//	fractol->ymax -= y_range * fractol->pan_factor * ((key.key == MLX_KEY_UP) + ( -1 * key.key == MLX_KEY_DOWN));
	//}
	//if (key.key == MLX_KEY_DOWN)
	//{
	//	//calculate_translation(&fractol, 4, x_range, y_range);
	//	fractol->ymin += y_range * fractol->pan_factor;
	//	fractol->ymax += y_range * fractol->pan_factor;
	//}
	//printf("xmin : %f, xmax : %f\nymin : %f, ymax : %f\n",
	//		(fractol)->xmin, (fractol)->xmax, (fractol)->ymin, (fractol)->ymax);