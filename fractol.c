/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/18 16:44:29 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;
	(void)argv;

	fractol = (t_fractol){};
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
	mlx_close_hook(fractol.img.mlx, NULL, NULL);
	mlx_key_hook(fractol.img.mlx, &handle_key, NULL);
	mlx_scroll_hook(fractol.img.mlx, &scroll_hook, &fractol);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img, fractol.x, fractol.y);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		//_put_pixel(fractol.img.img, fractol.x, fractol.y);
		_put_pixel(&fractol);
		mlx_loop(fractol.img.mlx);
		mlx_terminate(fractol.img.mlx);
	}
	return (0);
}

void	handle_key(mlx_key_data_t key, void *param)
{
	(void)param;
	if (key.key == MLX_KEY_ESCAPE)
		exit(0);
}

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
		printf("Values of xmin : %f\nxmax : %f\n ymin : %f\n ymax : %f\n", fractol->xmin, fractol->xmax, fractol->ymin, fractol->ymax);
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
		printf("Values of xmin : %f\nxmax : %f\n ymin : %f\n ymax : %f\n", mb->xmin, mb->xmax, mb->ymin, mb->ymax);
	mb->x = 0;
	//printf("Values of xmin : %d\nxmax : %d\n ymin : %d\n ymax : %d\n", X_MIN, X_MAX, Y_MIN, Y_MAX);
	while (++mb->x < WIDTH)
	{
		mb->y = -1;
		while (++mb->y < HEIGHT)
		{
			mb->zx = 0;
			mb->zy = 0;
			//mb->c_re = X_MIN + (X_MAX - X_MIN) * mb->x / (WIDTH);
			//mb->c_im = Y_MAX - (Y_MAX - Y_MIN) * mb->y / (HEIGHT);
			mb->c_re = mb->xmin + (mb->xmax - mb->xmin) * mb->x / (WIDTH);
			mb->c_im = mb->ymax - (mb->ymax - mb->ymin) * mb->y / (HEIGHT);
			mb->iter = 0;
			while (mb->zx * mb->zx + mb->zy * mb->zy < 4 && mb->iter < (mb->max_iter * (mb->zoom * mb->zoom)))
			{
				mb->tmp = 2.0 * mb->zx * mb->zy;
				mb->zx = mb->zx * mb->zx - mb->zy * mb->zy + mb->c_re;
				mb->zy = mb->tmp + mb->c_im;
				mb->iter++;
			}
			mlx_put_pixel(mb->img.img, mb->x, mb->y, color_pix(mb->iter, (mb->max_iter * (mb->zoom * mb->zoom))));
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