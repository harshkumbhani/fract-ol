/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:31 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/15 14:07:34 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	_put_pixel(mlx_image_t *img, int x, int y)
//{
//	union u_color	color;
//	color.i = 0;
//	color.c.a = 0xff;
//	//double	c_re = -0.7;
//	//double	c_im = 0.27015;
//	while (x < WIDTH)
//	{
//		y = 0;
//		while (y < HEIGHT)
//		{
//			color.c.b = (char)((double)(x) * 0.255);
//			color.c.r = (char)((double)(y) * 0.255);
//			// Apply the fractol function
//			mlx_put_pixel(img, x, y, color.i);
//			y++;
//		}
//		x++;
//	}
//}


void			_put_pixel(mlx_image_t *img, int x, int y);
union u_color	color_pix(int x, int y, int iteration);

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
	t_fractal		mandelbrot;

	//mandelbrot.zx = 0;
	//mandelbrot.zy = 0;
	while (x < WIDTH)
	{
		y = 0;
		mandelbrot.zx = 0;
		mandelbrot.zy = 0;
		while (y < HEIGHT)
		{
			mandelbrot.c_re = X_MIN + (X_MAX - X_MIN) * x / (WIDTH - 1);
			mandelbrot.c_im = Y_MIN + (Y_MAX - Y_MIN) * y / (HEIGHT - 1);
			mandelbrot.iteration = 0;
			color.i = 0;
			color.c.a = 0xff;
			while (mandelbrot.zx * mandelbrot.zx + mandelbrot.zy * mandelbrot.zy < 4
					&& mandelbrot.iteration < MAX_ITERATIONS)
			{
				mandelbrot.product = 2.0 * mandelbrot.zx * mandelbrot.zy;
				mandelbrot.zx = mandelbrot.zx * mandelbrot.zx - mandelbrot.zy *
						mandelbrot.zy + mandelbrot.c_re;
				mandelbrot.zy = mandelbrot.product + mandelbrot.c_im;
				mandelbrot.iteration++;
			}
			union u_color color_pixel = color_pix(x, y, mandelbrot.iteration);
			printf("Iterations %d: %d\n", y, mandelbrot.iteration);
			mlx_put_pixel(img, x, y, color_pixel.i);
			y++;
		}
		x++;
	}
}

union u_color	color_pix(int x, int  y, int iteration)
{
	union u_color color;
	(void)y;
	(void)x;

	color.i = 0;
	color.c.a = 0xff;
	if (iteration < MAX_ITERATIONS && iteration >= MAX_ITERATIONS / 2)
		color.c.b = (char)((double)(y) * 0.255);
	else if (iteration == MAX_ITERATIONS)
		color.i = 0;
	else if (iteration < MAX_ITERATIONS / 2)
	{
		color.c.b = (char)((double)(x) * 0.255);
		color.c.r = (char)((double)(y) * 0.255);
		//color.i = 255;
	}
	return color;
}

//void	_put_pixel(mlx_image_t *img, int x, int y)
//{
//	union u_color	color;
//	t_fractal		julia;

//	julia.c_re = 0.4;
//	julia.c_im = 0.233;
//	while (x < WIDTH)
//	{
//		y = 0;
//		while (y < HEIGHT)
//		{
//			julia.zx = -2.0 + 4.0 * x / (WIDTH - 1);
//			julia.zy = -2.0 + 4.0 * y / (HEIGHT - 1);
//			julia.iteration = 0;
//			color.i = 0;
//			color.c.a = 0xff;
//			while (julia.zx * julia.zx + julia.zy * julia.zy < 4
//					&& julia.iteration < MAX_ITERATIONS)
//			{
//				julia.product = 2.0 * julia.zx * julia.zy;
//				julia.zx = julia.zx * julia.zx - julia.zy * julia.zy + julia.c_re;
//				julia.zy = julia.product + julia.c_im;
//				julia.iteration++;
//			}
//			union u_color color_pixel = color_pix(x, y, julia.iteration);
//			mlx_put_pixel(img, x, y, color_pixel.i);
//			y++;
//		}
//		x++;
//	}
//}
