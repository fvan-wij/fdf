/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:43:33 by flip              #+#    #+#             */
/*   Updated: 2023/03/07 19:57:20 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"

int	mix_rgba(int r, int g, int b, int a)
{
	int color;
	t_rgba rgba;

	rgba.r = r;
	rgba.g = g;
	rgba.b = b;
	rgba.a = a;
	return (color = rgba.color);
}

uint32_t	convert_rgba(unsigned int color)
{
	return (color = ((color << 8)) | 0xFF);
}
