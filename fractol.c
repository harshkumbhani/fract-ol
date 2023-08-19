/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/19 16:11:54 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	check_leaks(void)
//{
//	system("leaks fractol");
//}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;
	(void)argv;

	fractol = (t_fractol){};
	//atexit(check_leaks);
	if (argc < 2)
		manual_and_exit();
	//if (_check_argv(argv) = EXIT_FAILURE)
	//{
	//	ft_printf("INVALID ARGUMENT\n");
	//	manual_and_exit();
	//}
	init(&fractol);
	if (init_mlx(&fractol) == 1)
		return (1);
	mlx_key_hook(fractol.img.mlx, &handle_key, &fractol);
	mlx_scroll_hook(fractol.img.mlx, &scroll_hook, &fractol);
	mlx_close_hook(fractol.img.mlx, NULL, NULL);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img, fractol.x, fractol.y);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		_put_pixel(&fractol);
		mlx_loop(fractol.img.mlx);
		mlx_terminate(fractol.img.mlx);
	}
	return (0);
}

void	handle_key(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;
	double		shift;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
		exit(0);
	if (key.key == 'R')
		init(fractol);
	shift = fractol->zoom * 0.05;
	if (key.key == MLX_KEY_LEFT)
	{
		fractol->xmin -= shift;
		fractol->xmax -= shift;
	}
	if (key.key == MLX_KEY_RIGHT)
	{
		fractol->xmin += shift;
		fractol->xmax += shift;
	}
	if (key.key == MLX_KEY_UP)
	{
		fractol->ymin -= shift;
		fractol->ymax -= shift;
	}
	if (key.key == MLX_KEY_DOWN)
	{
		fractol->ymin += shift;
		fractol->ymax += shift;
	}
	_put_pixel(fractol);
}

//void scroll_hook(double xdelta, double ydelta, void *param)
//{
//    t_fractol *fractol;
//    double zoom_factor = 1.05;  // Adjust this value as necessary for desired zoom rate

//    fractol = (t_fractol *)param;
//    (void)xdelta;

//    double width = fractol->xmax - fractol->xmin;
//    double height = fractol->ymax - fractol->ymin;
//    double width_diff, height_diff;

//    if (ydelta > 0) // Zooming in
//    {
//        width_diff = width * (1.0 - 1.0/zoom_factor) * 0.5;
//        height_diff = height * (1.0 - 1.0/zoom_factor) * 0.5;
//    }
//    else  // Zooming out
//    {
//        width_diff = width * (zoom_factor - 1.0) * 0.5;
//        height_diff = height * (zoom_factor - 1.0) * 0.5;
//    }

//    // Adjust boundaries
//    fractol->xmin += width_diff;
//    fractol->xmax -= width_diff;
//    fractol->ymin += height_diff;
//    fractol->ymax -= height_diff;

//    _put_pixel(fractol);
//}


void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	(void)xdelta;
	if (ydelta > 0)
	{
		fractol->xmin += 0.05;
		fractol->xmax += -0.05;
		fractol->ymin += 0.05;
		fractol->ymax += -0.05;
		fractol->zoom += +0.05;
		printf("xmin = %f xmax = %f\n", fractol->xmin, fractol->xmax);
		printf("ymin = %f ymax = %f\n", fractol->ymin, fractol->ymax);
		printf("zoom value = %f\n", fractol->zoom);
		_put_pixel(fractol);
	}
	else if (ydelta < 0)
	{
		fractol->xmin += -0.05;
		fractol->xmax += 0.05;
		fractol->ymin += -0.05;
		fractol->ymax += 0.05;
		fractol->zoom += -0.05;
		_put_pixel(fractol);
	}
}

void	_put_pixel(t_fractol *mb)
{
	mb->x = 0;
	while (++mb->x < WIDTH)
	{
		mb->y = -1;
		while (++mb->y < HEIGHT)
		{
			mb->zx = 0;
			mb->zy = 0;
			mb->max_iter = MAX_ITERATIONS * (mb->zoom * mb->zoom);
			mb->c_re = mb->xmin + (mb->xmax - mb->xmin) * mb->x / (WIDTH);
			mb->c_im = mb->ymax - (mb->ymax - mb->ymin) * mb->y / (HEIGHT);
			mb->iter = 0;
			while (mb->zx * mb->zx + mb->zy * mb->zy < 4 && mb->iter < mb->max_iter)
			{
				mb->tmp = 2.0 * mb->zx * mb->zy;
				mb->zx = mb->zx * mb->zx - mb->zy * mb->zy + mb->c_re;
				mb->zy = mb->tmp + mb->c_im;
				mb->iter++;
			}
			mlx_put_pixel(mb->img.img, mb->x, mb->y, color_pix(mb->iter, mb->max_iter));
		}
	}
}

//void	_put_pixel(mlx_image_t *img, int x, int y)
//{
//	t_fractol		mb;

//	while (++x < WIDTH)
//	{
//		y = -1;
//		while (++y < HEIGHT)
//		{
//			mb.zx = 0;
//			mb.zy = 0;
//			printf("Values of xmin : %d\nxmax : %d\n ymin : %d\n ymax : %d\n", mb.xmin, mb.xmax, mb.ymin, mb.ymax);
//			mb.c_re = X_MIN + (X_MAX - X_MIN) * x / (WIDTH);
//			mb.c_im = Y_MAX - (Y_MAX - Y_MIN) * y / (HEIGHT);
//			//mb.c_re = mb.xmin + (mb.xmax - mb.xmin) * x / (WIDTH);
//			//mb.c_im = mb.ymax - (mb.ymax - mb.ymin) * y / (HEIGHT);
//			mb.iter = 0;
//			while (mb.zx * mb.zx + mb.zy * mb.zy < 4 && mb.iter < MAX_ITERATIONS)
//			{
//				mb.tmp = 2.0 * mb.zx * mb.zy;
//				mb.zx = mb.zx * mb.zx - mb.zy * mb.zy + mb.c_re;
//				mb.zy = mb.tmp + mb.c_im;
//				mb.iter++;
//			}
//			mlx_put_pixel(img, x, y, color_pix(mb.iter));
//		}
//	}
//}

//int	_check_argv(char **argv)
//{
//	int	i;
//}