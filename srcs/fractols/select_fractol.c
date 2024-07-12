/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:53:18 by harsh             #+#    #+#             */
/*   Updated: 2024/07/12 15:48:54 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_type	get_fractal_type(t_fractol *fractol, int argc, char *str[])
{
	if (ft_strncmp(str_to_lower(str[1]), "mandelbrot", 10) == 0 && argc == 2)
	{
		fractol->name = "Mandelbrot";
		fractol->color_fun = &color_space;
		return (MANDELBROT);
	}
	else if (ft_strncmp(str_to_lower(str[1]), "julia", 5) == 0 && argc == 4)
	{
		fractol->name = "Julia";
		if (check_argv(str) == FALSE || !str[2][0] || !str[3][0])
			manual_and_exit();
		fractol->c_re = atod(str[2]);
		fractol->c_im = atod(str[3]);
		fractol->color_fun = &color_neon;
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

void	select_fractol(t_fractol *fractol, t_fractal_type fractal_type)
{
	if (fractal_type == MANDELBROT)
		draw_mandelbrot(fractol);
	if (fractal_type == JULIA)
		draw_julia(fractol);
	if (fractal_type == FERN)
		draw_fern(fractol);
}
