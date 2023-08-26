/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:53:18 by harsh             #+#    #+#             */
/*   Updated: 2023/08/26 19:14:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractol(t_fractol *fractol, t_fractal_type fractal_type)
{
	if (fractal_type == MANDELBROT)
		draw_mandelbrot(fractol);
	if (fractal_type == JULIA)
		draw_julia(fractol);
	if (fractal_type == FERN)
		draw_fern(fractol);
}
