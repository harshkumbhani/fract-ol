/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:06:43 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/28 17:40:07 by hkumbhan         ###   ########.fr       */
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

char	*str_to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	clean_exit(t_fractol *fractol)
{
	mlx_delete_image(fractol->img.mlx, fractol->img.img);
	mlx_delete_image(fractol->img.mlx, fractol->help_img);
	mlx_close_window(fractol->img.mlx);
	mlx_terminate(fractol->img.mlx);
	exit(EXIT_SUCCESS);
}

int	check_argv(char *argv[])
{
	int	i;
	int	j;
	int	dot_count;

	i = 1;
	while (++i < 4)
	{
		dot_count = 0;
		j = 0;
		while (ft_isspace(argv[i][j]) == TRUE)
			j++;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '.')
				dot_count++;
			else if (ft_isdigit(argv[i][j]) == FALSE)
				return (FALSE);
			if (dot_count > 1)
				return (FALSE);
			j++;
		}
	}
	return (TRUE);
}
