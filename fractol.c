/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/25 16:09:11 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_type	get_fractal_type(t_fractol *fractol, char *str[])
{
	if (ft_strncmp(str[1], "Mandelbrot", 10) == 0)
	{
		fractol->name = "Mandelbrot";
		return (MANDELBROT);
	}
	else if (ft_strncmp(str[1], "Julia", 5) == 0)
	{
		fractol->name = "Julia";
		fractol->c_re = atod(str[2]);
		fractol->c_im = atod(str[3]);
		return (JULIA);
	}
	else
		return (INVALID);
}

int	main(int argc, char *argv[])
{
	t_fractol		fractol;
	t_fractal_type	fractal_type;
	(void)argv;

	fractol = (t_fractol){};
	if (argc < 2)
		manual_and_exit();
	init(&fractol);
	fractal_type = get_fractal_type(&fractol, argv);
	if (fractal_type == INVALID)
		manual_and_exit();
	fractol.type = fractal_type;
	if (init_mlx(&fractol) == 1)
		return (1);
	mlx_key_hook(fractol.img.mlx, &handle_key, &fractol);
	mlx_scroll_hook(fractol.img.mlx, &handle_mouse, &fractol);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img, fractol.x, fractol.y);
	select_fractol(&fractol, fractal_type);
	mlx_loop(fractol.img.mlx);
	clean_exit(&fractol);
	return (EXIT_SUCCESS);
}

// void	_put_pixel(t_fractol *mb)
// {
// 	mb->x = 0;
// 	while (++mb->x < WIDTH)
// 	{
// 		mb->y = -1;
// 		while (++mb->y < HEIGHT)
// 		{
// 			mb->zx = 0;
// 			mb->zy = 0;
// 			mb->max_iter = MAX_ITERATIONS * (mb->zoom * mb->zoom);
// 			mb->c_re = mb->xmin + (mb->xmax - mb->xmin) * mb->x / (WIDTH);
// 			mb->c_im = mb->ymax - (mb->ymax - mb->ymin) * mb->y / (HEIGHT);
// 			mb->iter = 0;
// 			while (mb->zx * mb->zx + mb->zy * mb->zy < 4 && mb->iter < mb->max_iter)
// 			{
// 				mb->tmp = 2.0 * mb->zx * mb->zy;
// 				mb->zx = mb->zx * mb->zx - mb->zy * mb->zy + mb->c_re;
// 				mb->zy = mb->tmp + mb->c_im;
// 				mb->iter++;
// 			}
// 			mlx_put_pixel(mb->img.img, mb->x, mb->y, color_pix(mb->iter, mb->max_iter));
// 		}
// 	}
// }

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