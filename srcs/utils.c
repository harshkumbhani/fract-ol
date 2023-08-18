/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:06:43 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/18 15:23:20 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
#include "myLib/header/library.h"
#include <math.h>

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

double	_atod(char *str)
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


//int	main(void)
//{
//	char *str = "-9756.646";
//	double	res;

//	res = _atod(str);
//	printf("Number : %f\n", res);
//	return (0);
//}

//double	_atod(char *str)
//{
//	int			res;
//	int			sign;
//	double		fraction;

//	fraction = 1.0;
//	res = 0.0;
//	sign = 1;
//	while (ft_isspace(*str) == TRUE)
//		str++;
//	if (*str == '-' || *str == '+')
//	{
//		if (*str == '-')
//			sign = -1;
//		str++;
//	}
//	while (ft_isdigit(*str) == TRUE || (*str == '.' && fraction == 1.0))
//	{
//		if (*str == '.')
//			fraction = 0.1;
//		else if (fraction == 1.0)
//			res = res * 10 + (*str - '0');
//		else
//		{
//			res += (*str - '0') * fraction;
//			fraction *= 0.1;
//		}
//		str++;
//	}
//	return ((res * sign));
//}
