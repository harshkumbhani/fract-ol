/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:33:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/18 16:40:05 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *init)
{
	//t_fractol	*init;

	//init = fractol;
	init->name = "Mandelbrot";
	init->c_im = 0;
	init->c_re = 0;
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
}

int	init_mlx(t_fractol *fractol)
{
	fractol->img.mlx = mlx_init(WIDTH, HEIGHT, fractol->name, 1);
	if (!(fractol->img.mlx))
		return (perror("Error in mlx init"), 1);
	fractol->img.img = mlx_new_image(fractol->img.mlx, WIDTH, HEIGHT);
	return (0);
}
