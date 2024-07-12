/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:03:14 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/12 23:00:59 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	color_fall(int iterations, int max_iter)
{
	double	iter_norm;

	iter_norm = (double)iterations / max_iter;
	if (iterations == max_iter)
		return (0x000000FF);
	else if (iter_norm <= 0.25)
		return (grad(iter_norm / 0.25, 0x150e04FF, 0x553811FF));
	else if (iter_norm <= 0.5)
		return (grad((iter_norm - 0.25) / 0.25,
				0x553811FF, 0xb37b32FF));
	else if (iter_norm <= 0.75)
		return (grad((iter_norm - 0.5) / 0.25,
				0xb37b32FF, 0xc89d1eFF));
	else
		return (grad((iter_norm - 0.75) / 0.25,
				0xc89d1eFF, 0x000000FF));
}

uint32_t	color_space(int iterations, int max_iter)
{
	double	iter_norm;

	iter_norm = (double)iterations / max_iter;
	if (iterations == max_iter)
		return (0x000000FF);
	if (iter_norm <= 0.02)
		return (grad(iter_norm / 0.02, 0x000000FF, 0x0d001aFF));
	if (iter_norm <= 0.05)
		return (grad((iter_norm - 0.02) / 0.03, 0x0d001aFF, 0x1a0033FF));
	if (iter_norm <= 0.1)
		return (grad((iter_norm - 0.05) / 0.05, 0x26004dFF, 0x490066FF));
	if (iter_norm <= 0.18)
		return (grad((iter_norm - 0.1) / 0.08, 0x490066FF, 0x8000b3FF));
	if (iter_norm <= 0.245)
		return (grad((iter_norm - 0.18) / 0.065, 0x8000b3FF, 0x1E002AFF));
	if (iter_norm <= 0.28)
		return (grad((iter_norm - 0.245) / 0.035, 0x1E002AFF, 0x37004dFF));
	if (iter_norm <= 0.34)
		return (grad((iter_norm - 0.28) / 0.06, 0x37004dFF, 0xFF66B2FF));
	if (iter_norm <= 0.4)
		return (grad((iter_norm - 0.34) / 0.06, 0xFF66B2FF, 0x7300e6FF));
	if (iter_norm <= 0.8)
		return (grad((iter_norm - 0.4) / 0.4, 0x7300e6FF, 0xDDA0DDFF));
	return (grad((iter_norm - 0.8) / 0.2, 0xDDA0DDFF, 0x000000FF));
}

uint32_t	color_milkyway(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x000000);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x1E1E3F));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0x2E2E6E));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0x4B4B9A));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0x6E6ECF));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0x9A9AFF));
	else
		return (function(iterations, max_iter, 0xCFCFFF));
}

uint32_t	color_neon(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0x0b3d91);
	else if (iterations <= (double)max_iter * 0.02)
		return (function(iterations, max_iter * 0.02, 0x1c0033));
	else if (iterations <= (double)max_iter * 0.05)
		return (function(iterations, max_iter * 0.05, 0x4d0022));
	else if (iterations <= (double)max_iter * 0.15)
		return (function(iterations, max_iter * 0.15, 0x00ffea));
	else if (iterations <= (double)max_iter * 0.4)
		return (function(iterations, max_iter * 0.4, 0xffb400));
	else if (iterations <= (double)max_iter * 0.8)
		return (function(iterations, max_iter * 0.8, 0xff4800));
	else
		return (function(iterations, max_iter, 0x0b3d91));
}

uint32_t	color_flamingo(int iterations, int max_iter)
{
	double	iter_norm;

	iter_norm = (double)iterations / max_iter;
	if (iterations == max_iter)
		return (0x000000FF);
	else if (iter_norm <= 0.25)
		return (grad(iter_norm / 0.25, 0x18010bFF, 0x62042dFF));
	else if (iter_norm <= 0.5)
		return (grad((iter_norm - 0.25) / 0.25,
				0x62042dFF, 0xdc0965FF));
	else if (iter_norm <= 0.75)
		return (grad((iter_norm - 0.5) / 0.25,
				0xdc0965FF, 0xac3986FF));
	else
		return (grad((iter_norm - 0.75) / 0.25,
				0xac3986FF, 0x000000FF));
}
