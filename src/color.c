/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:43:33 by flip              #+#    #+#             */
/*   Updated: 2023/03/14 17:49:43 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	gradient_color(t_meta *meta, int x, int y)
{
	int	color;

	color = (2.5f * meta->map[y][x].iso_z) + 50;
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	if (color < 0)
		color = color * -1;
	return (color);
}

int	mix_rgba(int r, int g, int b, int a)
{
	t_rgba	rgba;

	rgba.r = r;
	rgba.g = g;
	rgba.b = b;
	rgba.a = a;
	return (rgba.color);
}

unsigned int	union_rgba(unsigned int color)
{
	t_rgba	rgba;

	rgba.color = color << 8;
	rgba.a = (int8_t)255;
	return (rgba.color);
}

unsigned int	convert_rgba(unsigned int color)
{
	return (color = ((color << 8)) | 0xFF);
}
