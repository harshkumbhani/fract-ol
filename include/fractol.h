/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/27 14:50:05 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../srcs/myLib/header/library.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdint.h>
# include <time.h>

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# define MAX_ITERATIONS 100

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

typedef enum e_fractal_type
{
	INVALID = -1,
	MANDELBROT,
	JULIA,
	FERN
}	t_fractal_type;

typedef struct s_fractol
{
	t_img			img;
	int				x;
	int				y;
	double			xmax;
	double			xmin;
	double			ymax;
	double			ymin;
	double			c_re;
	double			c_im;
	double			zx;
	double			zy;
	double			tmp;
	double			pan_factor;
	int				iter;
	int				max_iter;
	char			*name;
	double			zoom;
	t_fractal_type	type;
}	t_fractol;

// Function declatrations for printing manuals
void		manual_and_exit(void);

//Function definition for inits
void		init(t_fractol *init, t_fractal_type fractal_type);
int			init_mlx(t_fractol *fractol);

uint32_t	function(int iter, double max_iter, uint32_t color);
uint32_t	color_mandelbrot(int iterations, int max_iter);
uint32_t	color_fall(int iterations, int max_iter);
uint32_t	color_fern(int iterations, int max_iter);
uint32_t	color_julia(int iterations, int max_iter);

// Function declaration for hooks
void		handle_mouse(double xdelta, double ydelta, void *param);
void		handle_key(mlx_key_data_t key, void	*param);

// Function defs for utils

double		atod(char *str);
void		clean_exit(t_fractol *fractol);
char		*str_to_lower(char *str);

void		draw_mandelbrot(t_fractol *mb);
void		draw_julia(t_fractol *jla);
void		draw_fern(t_fractol *fern);
void		select_fractol(t_fractol *fractol, t_fractal_type fractal_type);

#endif
