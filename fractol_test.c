/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:31 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/17 08:23:45 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define PALETTE_SIZE 256

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
//union u_color	color_pix(int x, int y, int iteration);
// union u_color	color_pix(int x, int  y, int iteration);
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
	t_fractal		mandelbrot;
	union u_color	color_pixel;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mandelbrot.zx = 0;
			mandelbrot.zy = 0;
			mandelbrot.c_re = X_MIN + (X_MAX - X_MIN) * x / (WIDTH - 1);
			mandelbrot.c_im = Y_MAX - (Y_MAX - Y_MIN) * y / (HEIGHT - 1);
			mandelbrot.iteration = 0;
			while (mandelbrot.zx * mandelbrot.zx + mandelbrot.zy * mandelbrot.zy < 4
					&& mandelbrot.iteration < MAX_ITERATIONS)
			{
				mandelbrot.product = 2.0 * mandelbrot.zx * mandelbrot.zy;
				mandelbrot.zx = mandelbrot.zx * mandelbrot.zx - mandelbrot.zy * mandelbrot.zy + mandelbrot.c_re;
				mandelbrot.zy = mandelbrot.product + mandelbrot.c_im;
				mandelbrot.iteration++;
			}
			color_pixel = color_pix(mandelbrot.iteration);
			mlx_put_pixel(img, x, y, color_pixel.i);
			y++;
		}
		x++;
	}
}


//union u_color	color_pix(int x, int  y, int iteration)
//{
//	union u_color color;
//	(void)y;
//	(void)x;

//	color.i = 0;
//	color.c.a = 0xff;
//	if (iteration < MAX_ITERATIONS && iteration >= MAX_ITERATIONS / 2)
//		color.c.b = (char)((double)(y) * 0.255);
//	else if (iteration == MAX_ITERATIONS)
//		color.i = 0;
//	else if (iteration < MAX_ITERATIONS / 2)
//	{
//		color.c.b = (char)((double)(x) * 0.255);
//		color.c.r = (char)((double)(y) * 0.255);
//		//color.i = 255;
//	}
//	return color;
//}

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

//union u_color color_pix(int iterations)
//{
//	union u_color color;

//	if (iterations == MAX_ITERATIONS)
//		color.i = 0xE40303FF;
//	else if (iterations <= (double)MAX_ITERATIONS * 0.02)
//		color.i = 0x732982FF;
//	else if (iterations <= (double)MAX_ITERATIONS * 0.05)
//		color.i = 0x24408EFF;
//	else if (iterations <= (double)MAX_ITERATIONS * 0.15)
//		color.i = 0x008026FF;
//	else if (iterations <= (double)MAX_ITERATIONS * 0.4)
//		color.i = 0xFFED00FF;
//	else if (iterations <= (double)MAX_ITERATIONS * 0.8)
//		color.i = 0xFF8C00FF;
//	else
//		color.i = 0xE40303FF;
//	return color;
//}

// void	_put_pixel(mlx_image_t *img, int x, int y)
// {
// 	// union u_color	color;
// 	t_fractal		julia;

// 	julia.c_re = -0.4;
// 	julia.c_im = 0.6;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			julia.zx = -2.0 + 4.0 * x / (WIDTH - 1);
// 			julia.zy = 2.0 - 4.0 * y / (HEIGHT - 1);
// 			julia.iteration = 0;
// 			// color.i = 0;
// 			// color.c.a = 0xff;
// 			while (julia.zx * julia.zx + julia.zy * julia.zy < 4
// 					&& julia.iteration < MAX_ITERATIONS)
// 			{
// 				julia.product = 2.0 * julia.zx * julia.zy;
// 				julia.zx = julia.zx * julia.zx - julia.zy * julia.zy + julia.c_re;
// 				julia.zy = julia.product + julia.c_im;
// 				julia.iteration++;
// 			}
// 			union u_color color_pixel = color_pix(julia.iteration);
// 			mlx_put_pixel(img, x, y, color_pixel.i);
// 			y++;
// 		}
// 		x++;
// 	}
// }

union u_color	color_pix(int iterations)
{
	//union u_color color;
	//double frequency = 2 * PI / MAX_ITERATIONS * 10; // Increase to get more color cycles

	//color.c.r = (char)(sin(frequency * iterations + 0) * 127.5 + 127.5);
	//color.c.g = (char)(sin(frequency * iterations + 2 * PI / 3) * 127.5 + 127.5);
	//color.c.b = (char)(sin(frequency * iterations + 4 * PI / 3) * 127.5 + 127.5);
	//color.c.a = 0xff;
	//return color;
	union u_color	color;

	// Define 4 different colors
	//t_color color1 = {0xff, 0, 0, 0xff};     // Red
	t_color color2 = {0xff, 0xff, 0, 0xff}; // Yellow
	t_color color3 = {0, 0xff, 0, 0xff};    // Green
	t_color color4 = {0, 0, 0xff, 0xff};    // Blue

	if (iterations < MAX_ITERATIONS / 4)
	{
		char intensity = (char) ((255.0 * iterations) / (MAX_ITERATIONS / 4));
		color.c.r = intensity;
		color.c.g = 0;
		color.c.b = 0;
		color.c.a = 0xff;
	}
	else if (iterations < MAX_ITERATIONS / 2)
		color.c = color2;
	else if (iterations < 3 * MAX_ITERATIONS / 4)
		color.c = color3;
	else
		color.c = color4;

	return color;
}
