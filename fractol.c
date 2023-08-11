/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:31 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/11 09:18:13 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	_put_pixel(mlx_image_t *img, int x, int y)
//{
//	union u_color	color;
//	color.i = 0;
//	color.c.a = 0xff;
//	double	c_re = -0.7;
//	double	c_im = 0.27015;
//	while (x < WIDTH)
//	{
//		y = 0;
//		while (y < HEIGHT)
//		{
//			color.c.r = (char)((double)(x) * .25);
//			color.c.g = (char)((double)(y) * .25);
//			// Apply the fractol function
//			mlx_put_pixel(img, x, y, color.i);
//			y++;
//		}
//		x++;
//	}
//}


void			_put_pixel(mlx_image_t *img, int x, int y);
union u_color	color_pix(int iteration);

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	mlx_t		*mlx;
	mlx_image_t *img;
	int			x;
	int			y;

	x = 0;
	y = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "Eugen's Socks", 1);
	if (!mlx)
		return(perror("mlx init"), 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	_put_pixel(img, x, y);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

void	_put_pixel(mlx_image_t *img, int x, int y)
{
	union u_color	color;
	t_fractal		julia;

	julia.c_re = -0.4;
	julia.c_im = 0.6;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			julia.zx = -2.0 + 4.0 * x / (WIDTH - 1);
			julia.zy = 2.0 - 4.0 * y / (HEIGHT - 1);
			julia.iteration = 0;
			color.i = 0;
			color.c.a = 0xff;
			while (julia.zx * julia.zx + julia.zy * julia.zy < 4
					&& julia.iteration < MAX_ITERATIONS)
			{
				julia.product = 2.0 * julia.zx * julia.zy;
				julia.zx = julia.zx * julia.zx - julia.zy * julia.zy + julia.c_re;
				julia.zy = julia.product + julia.c_im;
				julia.iteration++;
			}
			union u_color color_pixel = color_pix(julia.iteration);
			mlx_put_pixel(img, x, y, color_pixel.i);
			y++;
		}
		x++;
	}
}

union u_color	color_pix(int iteration)
{
	union u_color color;

	//if (iteration == MAX_ITERATIONS)
	//{
	//	color.c.r = 0;
	//	color.c.g = 0;
	//	color.c.b = 0;
	//	color.c.a = 0xff;
	//	return color;
	//}
	double t = (double)iteration / (double)MAX_ITERATIONS;

	// Gradient color 1: Red

	// Gradient color 1: Black
	double r1 = 0, g1 = 0, b1 = 0;

	// Gradient color 2: Blue (or another color of your choice)
	double r2 = 0, g2 = 0, b2 = 255;

	// Interpolate between the gradient colors based on t
	double r = (1 - t) * r1 + t * r2;
	double g = (1 - t) * g1 + t * g2;
	double b = (1 - t) * b1 + t * b2;

	color.c.r = (char)r;
	color.c.g = (char)g;
	color.c.b = (char)b;
	color.c.a = 0xff;

	return color;

	return color;
}

