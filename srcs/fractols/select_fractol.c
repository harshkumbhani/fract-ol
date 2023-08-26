/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:53:18 by harsh             #+#    #+#             */
/*   Updated: 2023/08/25 16:05:33 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractol(t_fractol *fractol, t_fractal_type fractal_type)
{
	if (fractal_type == MANDELBROT)
		draw_mandelbrot(fractol);
	if (fractal_type == JULIA)
		draw_julia(fractol);
}
