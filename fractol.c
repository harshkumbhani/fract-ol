/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 11:09:40 by hkumbhan         ###   ########.fr       */
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
	if (argc < 2)
		manual_and_exit();
	init(&fractol, argv[1]);
	if (init_mlx(&fractol, &argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_key_hook(fractol.img.mlx, &handle_key, &fractol);
	mlx_scroll_hook(fractol.img.mlx, &handle_mouse, &fractol);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img,
					fractol.x, fractol.y);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		_put_pixel(&fractol);
		mlx_loop(fractol.img.mlx);
	}
	clean_exit(&fractol);
	return (EXIT_SUCCESS);
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

//int	_check_argv(char **argv)
//{
//	int	i;
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

//	struct sigaction sa;

//    sa.sa_flags = SA_SIGINFO;
//    sa.sa_sigaction = segfault_sigaction;
//    sigemptyset(&sa.sa_mask);
//    sigaction(SIGSEGV, &sa, NULL);