/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:31 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/09 14:14:26 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	mlx_t	*mlx;
	mlx_image_t *img;
	int			x;
	int			y;

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
			// Apply the fractol function
			mlx_put_pixel(img, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
