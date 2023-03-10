/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:24:11 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/10 18:25:16 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

static int	sign_x(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

static int	sign_y(int y1, int y2)
{
	if (y1 < y2)
		return (1);
	return (-1);
}

static void	draw_line(mlx_image_t *image, uint32_t color, t_line point, t_point p, int error[])
{
	while (point.cx != p.x2 || point.cy != p.y2)
	{
		draw_pixel(image, point.cx, point.cy, color);
		if ((error[1] = error[0] * 2) > (-point.dy))
		{
			error[0] -= point.dy;
			point.cx += point.sx;
		}
		if (error[1] < point.dx)
		{
			error[0] += point.dx;
			point.cy += point.sy;
		}
	}
}

void	bresenham_line(mlx_image_t *image, uint32_t color, t_line point, t_point p)
{
	int	error[2];

	point.dx = abs(p.x2 - p.x1);
	point.dy = abs(p.y2 - p.y1);
	point.sx = sign_x(p.x1, p.x2);
	point.sy = sign_y(p.y1, p.y2);
	error[0] = point.dx - point.dy;
	point.cx = p.x1;
	point.cy = p.y1;
	draw_line(image, color, point, p, error);
}