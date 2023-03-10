/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:45:56 by flip              #+#    #+#             */
/*   Updated: 2023/03/09 20:36:10 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

static void translate_to_isometric(int x, int y, t_meta *meta)
{
	meta->map[y][x].iso_z = meta->map[y][x].z * meta->z_offset;
    meta->map[y][x].iso_x = (x - y) * meta->tileSize + meta->x_offset;
    meta->map[y][x].iso_y = (x + y - meta->map[y][x].iso_z) * (meta->tileSize * 0.5) + meta->y_offset;
}

static void translate_to_topdown(int x, int y, t_meta *meta)
{
	meta->map[y][x].x = (x * meta->tileSize) + meta->x_offset;
	meta->map[y][x].y = (y * meta->tileSize) + meta->y_offset;
}

void	draw_topdown_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	t_point px;
	t_point py;

	translate_to_topdown(x, y, meta);
	if (x >= 1)
	{
		px.x1 = meta->map[y][x - 1].x;
		px.y1 = meta->map[y][x - 1].y;
		px.x2 = meta->map[y][x].x;
		px.y2 = meta->map[y][x].y;
		draw_line(image, meta->map[y][x].color, meta->point, px);
	}
	if (y >= 1)
	{
		py.x1 = meta->map[y - 1][x].x;
		py.y1 = meta->map[y - 1][x].y;
		py.x2 = meta->map[y][x].x;
		py.y2 = meta->map[y][x].y;
		draw_line(image, meta->map[y][x].color, meta->point, py);
	}
}

void	draw_isometric_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	t_point px;
	t_point py;

	translate_to_isometric(x, y, meta);
	if (x >= 1)
	{
		px.x1 = meta->map[y][x - 1].iso_x;
		px.y1 = meta->map[y][x - 1].iso_y;
		px.x2 = meta->map[y][x].iso_x;
		px.y2 = meta->map[y][x].iso_y;	
		draw_line(image, meta->map[y][x].color, meta->point, px);
	}
	if (y >= 1)
	{
		py.x1 = meta->map[y - 1][x].iso_x;
		py.y1 = meta->map[y - 1][x].iso_y;
		py.x2 = meta->map[y][x].iso_x;
		py.y2 = meta->map[y][x].iso_y;
		draw_line(image, meta->map[y][x].color, meta->point, py);
	}
}

static int gradient_color(t_meta *meta, int x, int y)
{
	int color = (2.5f * meta->map[y][x].iso_z) + 50;
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	if (color < 0)
		color = color * -1;
	return (color);
}

void	draw_gradient_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	t_point px;
	t_point	py;

	translate_to_isometric(x, y, meta);
	if (x >= 1)
	{
		px.x1 = meta->map[y][x - 1].iso_x;
		px.y1 = meta->map[y][x - 1].iso_y;
		px.x2 = meta->map[y][x].iso_x;
		px.y2 = meta->map[y][x].iso_y;
		draw_line(image, mix_rgba(255, 255, 255, gradient_color(meta, x, y)), meta->point, px);
	}
	if (y >= 1)
	{
		py.x1 = meta->map[y - 1][x].iso_x;
		py.y1 = meta->map[y - 1][x].iso_y;
		py.x2 = meta->map[y][x].iso_x;
		py.y2 = meta->map[y][x].iso_y;
		draw_line(image, mix_rgba(255, 255, 255, gradient_color(meta, x, y)), meta->point, py);
	}
}
