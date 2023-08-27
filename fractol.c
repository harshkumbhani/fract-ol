/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/27 16:11:34 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_type	get_fractal_type(t_fractol *fractol, int argc, char *str[])
{
	if (ft_strncmp(str_to_lower(str[1]), "mandelbrot", 10) == 0 && argc == 2)
	{
		fractol->name = "Mandelbrot";
		fractol->color_fun = &color_mandelbrot;
		return (MANDELBROT);
	}
	else if (ft_strncmp(str_to_lower(str[1]), "julia", 5) == 0 && argc == 4)
	{
		fractol->name = "Julia";
		fractol->c_re = atod(str[2]);
		fractol->c_im = atod(str[3]);
		fractol->color_fun = &color_fall;
		return (JULIA);
	}
	else if (ft_strncmp(str_to_lower(str[1]), "fern", 5) == 0 && argc == 2)
	{
		fractol->name = "Fern";
		fractol->color_fun = &color_fern;
		return (FERN);
	}
	return (INVALID);
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
	mlx_key_hook(fractol.img.mlx, &handle_key, &fractol);
	//mlx_key_hook(fractol.img.mlx, &handle_color, &fractol);
	mlx_scroll_hook(fractol.img.mlx, &handle_mouse, &fractol);
	mlx_image_to_window(fractol.img.mlx, fractol.img.img,
		fractol.x, fractol.y);
	select_fractol(&fractol, fractal_type);
	mlx_loop(fractol.img.mlx);
	clean_exit(&fractol);
	return (EXIT_SUCCESS);
}
