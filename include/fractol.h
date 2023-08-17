/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/17 11:00:17 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../srcs/myLib/header/library.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# define PI				3.14159

# define X_MIN			-2.5
# define X_MAX			1.0
# define Y_MIN			-1.5
# define Y_MAX			1.5

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

typedef struct	s_fractol
{
	t_img	img;
	char	*name;
	int		x;
	int		y;
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;
	double	c_re;
	double	c_im;
	double	zx;
	double	zy;
	double	tmp;
	int		iter;
	int		max_iter;
}	t_fractol;

// Function declatrations for printing manuals
void			manual_and_exit(void);

//Function definition for inits
void			init(t_fractol *fractol);
int				init_mlx(t_fractol *fractol);

union u_color	color_pix(int iterations);
void			_put_pixel(mlx_image_t *img, int x, int y);

#endif
