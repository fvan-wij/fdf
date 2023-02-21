/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:43:33 by flip              #+#    #+#             */
/*   Updated: 2023/02/13 16:04:24 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"

int	rgb_combine(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8);
}

uint32_t	convert_rgb(unsigned int color)
{
    int		red;
	int		green;
	int		blue;

	red = ((color >> 16) & 0xFF);
	green = ((color >> 8) & 0xFF);
	blue = (color & 0xFF);
	color = rgb_combine(red, green, blue) | 0xFF;
	return (color);
}
