/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/17 11:03:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define MAX_ITERATIONS 42

int	main(int argc, char *argv[])
{
	t_fractol	fractol;
	(void)argv;

	if (argc < 2)
		manual_and_exit();
	init(&fractol);
	if (init_mlx(&fractol) == 1)
		return (1);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img, fractol.x, fractol.y);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		_put_pixel(fractol.img.img, fractol.x, fractol.y);
		mlx_loop(fractol.img.mlx);
		mlx_terminate(fractol.img.mlx);
	}
	return (0);
}

void	_put_pixel(mlx_image_t *img, int x, int y)
{
	t_fractol		mb;
	union u_color	color_pixel;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mb.zx = 0;
			mb.zy = 0;
			mb.c_re = X_MIN + (X_MAX - X_MIN) * x / (WIDTH - 1);
			mb.c_im = Y_MAX - (Y_MAX - Y_MIN) * y / (HEIGHT - 1);
			mb.iter = 0;
			while (mb.zx * mb.zx + mb.zy * mb.zy < 4 && mb.iter < 42)
			{
				mb.tmp = 2.0 * mb.zx * mb.zy;
				mb.zx = mb.zx * mb.zx - mb.zy * mb.zy + mb.c_re;
				mb.zy = mb.tmp + mb.c_im;
				mb.iter++;
			}
			color_pixel = color_pix(mb.iter);
			mlx_put_pixel(img, x, y, color_pixel.i);
			y++;
		}
		x++;
	}
}

union u_color color_pix(int iterations)
{
	union u_color color;

	if (iterations == MAX_ITERATIONS)
		color.i = 0xE40303FF;
	else if (iterations <= (double)MAX_ITERATIONS * 0.02)
		color.i = 0x732982FF;
	else if (iterations <= (double)MAX_ITERATIONS * 0.05)
		color.i = 0x24408EFF;
	else if (iterations <= (double)MAX_ITERATIONS * 0.15)
		color.i = 0x008026FF;
	else if (iterations <= (double)MAX_ITERATIONS * 0.4)
		color.i = 0xFFED00FF;
	else if (iterations <= (double)MAX_ITERATIONS * 0.8)
		color.i = 0xFF8C00FF;
	else
		color.i = 0xE40303FF;
	return color;
}