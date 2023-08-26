/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:06:43 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/25 16:04:47 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	_count_digits_after_dot(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '.')
		i++;
	while (str[++i] != '\0' && ft_isdigit(str[i]) == TRUE)
		count++;
	return (count);
}

double	atod(char *str)
{
	int		res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(*str) == TRUE)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]) == TRUE || str[i] == '.')
	{
		if (str[i] != '.')
			res = 10 * res + (str[i] - 48);
		i++;
	}
	return ((res * sign) / pow(10, _count_digits_after_dot(str)));
}

void	clean_exit(t_fractol *fractol)
{
	mlx_delete_image(fractol->img.mlx, fractol->img.img);
	mlx_close_window(fractol->img.mlx);
	mlx_terminate(fractol->img.mlx);
	exit(EXIT_SUCCESS);
}
