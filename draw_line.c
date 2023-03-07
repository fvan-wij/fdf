/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:41:17 by flip              #+#    #+#             */
/*   Updated: 2023/03/05 19:13:40 by flip             ###   ########.fr       */
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

void draw_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
		mlx_put_pixel(image, x, y, color);
}

void	draw_line(mlx_image_t *image, uint32_t color, t_line point, t_point p)
{
	int	error[2];

	point.dx = abs(p.x2 - p.x1);
	point.dy = abs(p.y2 - p.y1);
	point.sx = sign_x(p.x1, p.x2);
	point.sy = sign_y(p.y1, p.y2);
	error[0] = point.dx - point.dy;
	point.cx = p.x1;
	point.cy = p.y1;
	while (point.cx != p.x2 || point.cy != p.y2)
	{
		draw_pixel(image, point.cx, point.cy, color);
		if ((error[1] = error[0] * 2) > -point.dy)
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
