/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/28 17:16:12 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	check_leaks(void)
//{
//	system("leaks fractol");
//}
//atexit(check_leaks);

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
	mlx_key_hook(fractol.img.mlx, &handle_key, &fractol);
	mlx_scroll_hook(fractol.img.mlx, &handle_mouse, &fractol);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img,
		fractol.x, fractol.y);
	init_help_manual(&fractol);
	select_fractol(&fractol, fractal_type);
	mlx_loop(fractol.img.mlx);
	clean_exit(&fractol);
	return (EXIT_SUCCESS);
}
