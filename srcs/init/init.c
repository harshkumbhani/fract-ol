/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:33:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/28 17:38:02 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	init_fern(t_fractol *init)
{
	init->c_im = 0;
	init->c_re = 0;
	init->xmin = -2.5;
	init->xmax = 2.5;
	init->ymin = 0;
	init->ymax = 10;
	init->x = -1;
	init->y = 0;
	init->zx = 0;
	init->zy = 0;
	init->max_iter = 10000000;
	init->iter = 0;
	init->tmp = 0;
	init->zoom = 1.0;
	init->pan_factor = 0.01;
}

static	void	init_rest(t_fractol *init, int fractal_type)
{
	if (fractal_type == MANDELBROT)
	{
		init->c_im = 0;
		init->c_re = 0;
	}
	init->xmin = -2;
	init->xmax = 2;
	init->ymin = -2;
	init->ymax = 2;
	init->x = -1;
	init->y = 0;
	init->zx = 0;
	init->zy = 0;
	init->max_iter = 42;
	init->iter = 0;
	init->tmp = 0;
	init->zoom = 1.0;
	init->pan_factor = 0.05;
}

void	init(t_fractol *init, t_fractal_type fractal_type)
{
	if (fractal_type == FERN)
		init_fern(init);
	else
		init_rest(init, fractal_type);
}

void	init_help_manual(t_fractol *fractol)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("srcs/hooks/help_manual.png");
	fractol->help_img = mlx_texture_to_image(fractol->img.mlx, texture);
	mlx_image_to_window(fractol->img.mlx, fractol->help_img, 0, 0);
	mlx_resize_image(fractol->help_img, WIDTH, HEIGHT);
	fractol->help_img->enabled = false;
	mlx_delete_texture(texture);
}

int	init_mlx(t_fractol *fractol)
{
	fractol->img.mlx = mlx_init(WIDTH, HEIGHT, fractol->name, true);
	if (!(fractol->img.mlx))
		return (perror("Error in mlx init"), 1);
	fractol->img.img = mlx_new_image(fractol->img.mlx, WIDTH, HEIGHT);
	return (0);
}
