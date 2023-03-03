/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isometric_translation.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 16:45:56 by flip          #+#    #+#                 */
/*   Updated: 2023/03/03 16:46:25 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

static void translate_to_isometric(int x, int y, t_meta *meta)
{
	meta->map[y][x].iso_z = meta->map[y][x].z * meta->z_offset;
    meta->map[y][x].iso_x = (x - y) * meta->tileSize + (WIDTH * 0.5) + meta->x_offset;
    meta->map[y][x].iso_y = (x + y - meta->map[y][x].iso_z) * (meta->tileSize * 0.5) + meta->y_offset;
}

void	draw_isometric_landscape(t_meta *meta, mlx_image_t *image, int x, int y)
{
	s_point px;
	s_point	py;
	
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
