/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:42:53 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/02/22 16:46:05 by flip          ########   odam.nl         */
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

static	void draw_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
		mlx_put_pixel(image, x, y, color);
}

void translate_to_isometric(int x, int y, t_meta *meta)
{
	meta->map[y][x].iso_z = meta->map[y][x].z * (meta->z_offset * 0.5);
    meta->map[y][x].iso_x = (x - y) * meta->tileSize + (WIDTH * 0.5);
    meta->map[y][x].iso_y = (x + y - meta->map[y][x].iso_z) * (meta->tileSize * 0.5) + 450;
}

int	sign_x(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

int	sign_y(int y1, int y2)
{
	if (y1 < y2)
		return (1);
	return (-1);
}

static void	draw_line(mlx_image_t *image, uint32_t color, s_line point, int x1, int y1, int x2, int y2)
{
	int	error[2];
	
	point.dx = abs(x2 - x1);
	point.dy = abs(y2 - y1);
	point.sx = sign_x(x1, x2);
	point.sy = sign_y(y1, y2);
	error[0] = point.dx - point.dy;
	point.cx = x1;
	point.cy = y1;
	while (point.cx != x2 || point.cy != y2)
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

void	render_map(t_meta *meta, mlx_image_t* image)
{
	int x;
	int	y;
	// s_point point;

	x = 0;
	y = 0;
	while(y < meta->rows)
	{
		while (x < meta->columns)
		{
			translate_to_isometric(x, y, meta);
			// point.x1 = meta->map[y][x - 1].iso_x + meta->x_offset;
			// point.y1 = 
			if (x >= 1)
				draw_line(image, meta->map[y][x].color, meta->point, meta->map[y][x - 1].iso_x + meta->x_offset, meta->map[y][x - 1].iso_y + meta->y_offset, meta->map[y][x].iso_x + meta->x_offset, meta->map[y][x].iso_y + meta->y_offset);
			if (y >= 1)
				draw_line(image, meta->map[y][x].color, meta->point, meta->map[y - 1][x].iso_x + meta->x_offset, meta->map[y - 1][x].iso_y + meta->y_offset, meta->map[y][x].iso_x + meta->x_offset, meta->map[y][x].iso_y + meta->y_offset);
			x++;
		}
		x = 0;
		y++;
	}
}

void	hook(void *param)
{
	t_meta *meta;
	
	meta = param;
	if (mlx_is_key_down(meta->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(meta->mlx);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL) || mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))	
		zoom(meta);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT) || mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT) 
		|| mlx_is_key_down(meta->mlx, MLX_KEY_UP) || mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
		move_with_arrow_keys(meta);	
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP) || mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
		raise_lower(meta);
}

int32_t	init_window(t_meta *meta)
{
	meta->tileSize = WIDTH / (meta->columns + meta->rows);
	meta->x_limit = meta->columns;
	meta->y_limit = meta->rows;
	meta->z_offset = 2.0f;
	meta->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!meta->mlx)
		exit(EXIT_FAILURE);
	meta->g_img = mlx_new_image(meta->mlx, WIDTH, HEIGHT);
	render_map(meta, meta->g_img);
	mlx_image_to_window(meta->mlx, meta->g_img, 0, 0);
	mlx_loop_hook(meta->mlx, &hook, meta);
	mlx_loop(meta->mlx);
	mlx_terminate(meta->mlx);
	return (EXIT_SUCCESS);
}
