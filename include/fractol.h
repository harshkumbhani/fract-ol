/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/22 11:25:20 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../srcs/myLib/header/library.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <execinfo.h>
# include <signal.h>

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# define PI				3.14159

# define X_MIN			-2.0
# define X_MAX			2.0
# define Y_MIN			-2.0
# define Y_MAX			2.0

# define LEFT			1
# define RIGHT			2
# define UP				3
# define DOWN			4

#define MAX_ITERATIONS 100

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
	t_img		img;
	int			x;
	int			y;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		c_re;
	double		c_im;
	double		zx;
	double		zy;
	double		tmp;
	double		pan_factor;
	int			iter;
	int			max_iter;
	char		*name;
	double		zoom;
}	t_fractol;

// Function declatrations for printing manuals
void		manual_and_exit(void);

//Function definition for inits
void		init(t_fractol *init, char *fractol_name);
int			init_mlx(t_fractol *fractol, char *argv[]);

// Function definition for colors 
uint32_t	color_pix(int iterations, int max_iter);
u_int32_t	function(int iter, double max_iter, uint32_t color);
void		_put_pixel(t_fractol *fractol);

// Function declaration for hooks
void		handle_mouse(double xdelta, double ydelta, void *param);
void		handle_key(mlx_key_data_t key, void *param);

// Function defs for utils

double		_atod(char *str);
void		clean_exit(t_fractol *fractol);




#endif
