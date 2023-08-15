/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/15 14:01:44 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../srcs/myLib/header/library.h"
# include "../MLX42/include/MLX42/MLX42.h"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# define MAX_ITERATIONS 10000
# define X_MIN			-2.5
# define X_MAX			1.5
# define Y_MIN			-2
# define Y_MAX			2

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

typedef struct s_color
{
	char	a;
	char	b;
	char	g;
	char	r;
}	t_color;

union u_color
{
	int		i;
	t_color	c;
};

typedef struct	s_fractal
{
	t_img	img;
	double	c_re;
	double	c_im;
	double	zx;
	double	zy;
	double	product;
	int		iteration;
}	t_fractal;

#endif
