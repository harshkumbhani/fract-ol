/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:31 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/10 09:04:36 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


typedef struct s_color
{
	char a;
	char b;
	char g;
	char r;
}	t_color;

union u_color
{
	int i;
	t_color c;
};

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	mlx_t		*mlx;
	mlx_image_t *img;
	int			x;
	int			y;

	union u_color color;
	color.i = 0;
	color.c.a = 0xff;
	color.c.r = 0xff;
	

	x = 0;
	y = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "Eugen's Socks", 1);
	if (!mlx)
		return(perror("mlx init"), 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color.c.b = (char)((double)(x) * .25);
			color.c.g = (char)((double)(y) * .25);
			// Apply the fractol function
			mlx_put_pixel(img, x, y, color.i);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
