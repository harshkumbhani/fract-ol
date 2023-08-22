/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:25 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 15:33:05 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	parse(int argc, char *argv[], t_fractol *fractol)
//{
//	if (!ft_strncmp("Mandelbrot", to_lower(argv[1]), 11) && argc != 2)
//		manual_and_exit();
//	else
//		draw_mandelbrot(fractol);
//	mlx_loop(fractol->img.mlx);
//}

void	draw_fractol(t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "Mandelbrot", 11) == 0)
		draw_mandelbrot(fractol);
	//if (ft_strncmp(fractol->name, "Julia", 6) == 0)
	//	draw_julia(fractol, atod(argv[2]), atod(argv[3]));
}
