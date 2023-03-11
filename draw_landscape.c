/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:45:56 by flip              #+#    #+#             */
/*   Updated: 2023/03/11 16:21:34 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	draw_topdown_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	t_point	px;
	t_point	py;

	translate_to_topdown(x, y, meta);
	if (x >= 1)
	{
		px.x1 = meta->map[y][x - 1].x;
		px.y1 = meta->map[y][x - 1].y;
		px.x2 = meta->map[y][x].x;
		px.y2 = meta->map[y][x].y;
		bresenham_line(image, meta->map[y][x].color, meta->point, px);
	}
	if (y >= 1)
	{
		py.x1 = meta->map[y - 1][x].x;
		py.y1 = meta->map[y - 1][x].y;
		py.x2 = meta->map[y][x].x;
		py.y2 = meta->map[y][x].y;
		bresenham_line(image, meta->map[y][x].color, meta->point, py);
	}
}

void	draw_particle_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	translate_to_isometric(x, y, meta);
	draw_pixel(image, meta->map[y][x].iso_x, meta->map[y][x].iso_y, meta->map[y][x].color);
}

void	draw_isometric_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	t_point	px;
	t_point	py;

	translate_to_isometric(x, y, meta);
	if (x >= 1)
	{
		px.x1 = meta->map[y][x - 1].iso_x;
		px.y1 = meta->map[y][x - 1].iso_y;
		px.x2 = meta->map[y][x].iso_x;
		px.y2 = meta->map[y][x].iso_y;
		bresenham_line(image, meta->map[y][x].color, meta->point, px);
	}
	if (y >= 1)
	{
		py.x1 = meta->map[y - 1][x].iso_x;
		py.y1 = meta->map[y - 1][x].iso_y;
		py.x2 = meta->map[y][x].iso_x;
		py.y2 = meta->map[y][x].iso_y;
		bresenham_line(image, meta->map[y][x].color, meta->point, py);
	}
}

void	draw_gradient_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	t_point	px;
	t_point	py;
	int		color;

	color = mix_rgba(255, 0, 0, 255);
	translate_to_isometric(x, y, meta);
	if (x >= 1)
	{
		px.x1 = meta->map[y][x - 1].iso_x;
		px.y1 = meta->map[y][x - 1].iso_y;
		px.x2 = meta->map[y][x].iso_x;
		px.y2 = meta->map[y][x].iso_y;
		bresenham_line(image, color, meta->point, px);
	}
	if (y >= 1)
	{
		py.x1 = meta->map[y - 1][x].iso_x;
		py.y1 = meta->map[y - 1][x].iso_y;
		py.x2 = meta->map[y][x].iso_x;
		py.y2 = meta->map[y][x].iso_y;
		bresenham_line(image, color, meta->point, py);
	}
}
