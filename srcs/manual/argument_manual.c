/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manual.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:45:45 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/17 10:23:32 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	manual_and_exit(void)
{
	int		fd;
	char	*line;

	fd = open("./srcs/manual/arg_man.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		ft_printf("%s", line);
		free(line);
	}
	exit(0);
}
