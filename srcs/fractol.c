/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/10 19:10:29 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	check_leaks(void)
//{
//	system("leaks fractol");
//}
//atexit(check_leaks);

void	loop_fractol(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	check_translation(fractol);
	handle_color(fractol);
	select_fractol(fractol, fractol->type);
}

void	setup_and_launch_fractal(t_fractol *fractol,
			t_fractal_type fractol_type)
{
	mlx_key_hook(fractol->img.mlx, &handle_key, fractol);
	mlx_scroll_hook(fractol->img.mlx, &handle_mouse, fractol);
	mlx_image_to_window(fractol->img.mlx, fractol->img.img,
		fractol->x, fractol->y);
	init_help_manual(fractol);
	select_fractol(fractol, fractol_type);
	mlx_loop_hook(fractol->img.mlx, &loop_fractol, fractol);
	mlx_loop(fractol->img.mlx);
}

int	main(int argc, char *argv[])
{
	t_fractol		fractol;
	t_fractal_type	fractal_type;

	fractol = (t_fractol){};
	if (argc < 2)
		manual_and_exit();
	fractal_type = get_fractal_type(&fractol, argc, argv);
	if (fractal_type == INVALID)
		manual_and_exit();
	fractol.type = fractal_type;
	init(&fractol, fractal_type);
	if (init_mlx(&fractol) == 1)
		return (1);
	setup_and_launch_fractal(&fractol, fractal_type);
	clean_exit(&fractol);
	return (EXIT_SUCCESS);
}
