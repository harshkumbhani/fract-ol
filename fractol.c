/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/21 18:53:08 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//#include <execinfo.h>
//#include <signal.h>
//void	check_leaks(void)
//{
//	system("leaks fractol");
//}

//void segfault_sigaction(int signal, siginfo_t *si, void *arg) {
//    void *error_addr = si->si_addr;
//    void *array[10];
//    size_t size;

//	(void)signal;
//	(void)arg;
//    // get void*'s for all entries on the stack
//    size = backtrace(array, 10);

//    fprintf(stderr, "Error at address: 0x%lx\n", (long)error_addr);

//    // print out all the frames to stderr
//    backtrace_symbols_fd(array, size, STDERR_FILENO);

//    exit(1);
//}
void	clean_exit(t_fractol *fractol)
{
	mlx_delete_image(fractol->img.mlx, fractol->img.img);
	mlx_close_window(fractol->img.mlx);
	mlx_terminate(fractol->img.mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;
	(void)argv;

	//struct sigaction sa;

    //sa.sa_flags = SA_SIGINFO;
    //sa.sa_sigaction = segfault_sigaction;
    //sigemptyset(&sa.sa_mask);
    //sigaction(SIGSEGV, &sa, NULL);
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
	mlx_key_hook(fractol.img.mlx, &handle_key, &fractol);
	mlx_scroll_hook(fractol.img.mlx, &scroll_hook, &fractol);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img, fractol.x, fractol.y);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		_put_pixel(&fractol);
		mlx_loop(fractol.img.mlx);
	}
	//mlx_delete_image(fractol.img.mlx, fractol.img.img);
	//mlx_close_window(fractol.img.mlx);
	//mlx_terminate(fractol.img.mlx);
	clean_exit(&fractol);
	return (EXIT_SUCCESS);
}
void	handle_key(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;
	double		x_range;
	double		y_range;
	double		pan_factor;

	fractol = (t_fractol *)param;
	x_range = fractol->xmax - fractol->xmin;
	y_range = fractol->ymax - fractol->ymin;
	pan_factor = 0.05;
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(fractol); // write function to clean exit in utils.
	if (key.key == 'R')
		init(fractol);
	if (key.key == MLX_KEY_LEFT)
	{
		fractol->xmin += x_range * pan_factor;
		fractol->xmax += x_range * pan_factor;
	}
	if (key.key == MLX_KEY_RIGHT)
	{
		fractol->xmin -= x_range * pan_factor;
		fractol->xmax -= x_range * pan_factor;
	}
	if (key.key == MLX_KEY_UP)
	{
		fractol->ymin -= y_range * pan_factor;
		fractol->ymax -= y_range * pan_factor;
	}
	if (key.key == MLX_KEY_DOWN)
	{
		fractol->ymin += y_range * pan_factor;
		fractol->ymax += y_range * pan_factor;
	}
	_put_pixel(fractol);
}

void zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double x_range;
	double y_range;
	double x_math;
	double y_math;
	double new_x_range;
	double new_y_range;

	x_range = fractol->xmax - fractol->xmin;
	y_range = fractol->ymax - fractol->ymin;
	x_math = fractol->xmin + ((double)x / WIDTH) * x_range;
	y_math = fractol->ymin + (1 - (double)y / HEIGHT) * y_range;
	new_x_range = x_range / zoom_factor;
	new_y_range = y_range / zoom_factor;
	fractol->xmin = x_math - ((double)x / WIDTH) * new_x_range;
	fractol->xmax = fractol->xmin + new_x_range;
	fractol->ymin = y_math - (1 - (double)y / HEIGHT) * new_y_range;
	fractol->ymax = fractol->ymin + new_y_range;
}

void scroll_hook(double xdelta, double ydelta, void *param)
{
	double		zoom_level;
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	fractol = (t_fractol *)param;
	zoom_level = 1.42;
	mlx_get_mouse_pos(fractol->img.mlx, &mouse_x, &mouse_y);
	if (ydelta < 0)
		zoom(fractol, mouse_x, mouse_y, zoom_level);
	else if (ydelta > 0)
		zoom(fractol, mouse_x, mouse_y, 1/zoom_level);
	_put_pixel(fractol);
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