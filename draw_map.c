/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:42:53 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/01/19 15:29:09 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include<math.h>

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

void iso(mlx_image_t* image, int x, int y, Map **map)
{
	int	tileWidth;

	tileWidth = 30;
    map[y][x].iso_x = (x - y) * tileWidth + (WIDTH/2);
    map[y][x].iso_y = (x + y - map[y][x].z) * (tileWidth / 2) + 450;
}

void	draw_omnidirectional_lineX(mlx_image_t *image, int x1, int y1, int x2, int y2)
{
	// Figure out the slope, negative, positive, horizontal or vertical? 
	int	parametric_value;
	int m_slope;
	int	delta_x;
	int	delta_y;
	int	x;
	int	y;
	int	t;

	if ((x2 - x1 == 0)) // -> Vertical line
		m_slope = (y2 - y1);
	else
		m_slope = (y2 - y1)/(x2 - x1); //Delta Y over Delta X
	
	if (abs(m_slope) < 1)
	{
		if (x1 > x2) 
		{
		t = x1;
		x1 = x2;
		x2 = t;
		t = y1;
		y1 = y2;
		y2 = t;
		}
		delta_x = abs(x2 - x1);
		delta_y = abs(y2 - y1);
		parametric_value = 2 * delta_y - delta_x; // -> This decides whether to increment or stay equal relative to the constant incrementation of either X or Y.
		x = x1;
		y = y1;
		while (x <= x2) // -> Draws points from x1 to x2
		{
		
			if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
				mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			x++;
			if (parametric_value >= 0)
			{
				if (m_slope < 1)
					y++;
				else
					y--;
				parametric_value = parametric_value + 2 * delta_y - 2 * delta_x;
			}
			else
			{
				y = y;
				parametric_value = parametric_value + 2  * delta_y;
			}
		}
	}

	if (abs(m_slope) >= 1)
	{
		if (y1 > y2) 
		{
			t = x1;
			x1 = x2;
			x2 = t;
			t = y1;
			y1 = y2;
			y2 = t;
		}
		delta_x = abs(x2 - x1);
		delta_y = abs(y2 - y1);
		parametric_value = 2 * delta_x - delta_y; // -> This decides whether to increment or stay equal relative to the constant incrementation of either X or Y.
		x = x1;
		y = y1;
		while (y <= y2) // -> Draws points from x1 to x2
		{
		
			if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
				mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			y++;
			if (parametric_value >= 0)
			{
				if (m_slope >=1)
					x++;
				else
					x--;
				parametric_value = parametric_value + 2 * delta_x - 2 * delta_y;
			}
			else
			{
				x = x;
				parametric_value = parametric_value + 2  * delta_x;
			}
		}
	}
}


void	draw_omnidirectional_lineY(mlx_image_t *image, int x1, int y1, int x2, int y2)
{
	// Figure out the slope, negative, positive, horizontal or vertical? 
	int	parametric_value;
	int m_slope;
	int	delta_x;
	int	delta_y;
	int	x;
	int	y;
	int	t;

	if ((x2 - x1 == 0)) // -> Vertical line
		m_slope = (y2 - y1);
	else
		m_slope = (y2 - y1)/(x2 - x1); //Delta Y over Delta X
	
	if (abs(m_slope) < 1)
	{
		if (x1 > x2) 
		{
		t = x1;
		x1 = x2;
		x2 = t;
		t = y1;
		y1 = y2;
		y2 = t;
		}
		delta_x = abs(x2 - x1);
		delta_y = abs(y2 - y1);
		parametric_value = 2 * delta_y - delta_x; // -> This decides whether to increment or stay equal relative to the constant incrementation of either X or Y.
		x = x1;
		y = y1;
		while (x <= x2) // -> Draws points from x1 to x2
		{
		
			if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
				mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			x++;
			if (parametric_value >= 0)
			{
				if (m_slope > 1)
					y++;
				else
					y--;
				parametric_value = parametric_value + 2 * delta_y - 2 * delta_x;
			}
			else
			{
				y = y;
				parametric_value = parametric_value + 2  * delta_y;
			}
		}
	}

	if (abs(m_slope) >= 1)
	{
		if (y1 > y2) 
		{
			t = x1;
			x1 = x2;
			x2 = t;
			t = y1;
			y1 = y2;
			y2 = t;
		}
		delta_x = abs(x2 - x1);
		delta_y = abs(y2 - y1);
		parametric_value = 2 * delta_x - delta_y; // -> This decides whether to increment or stay equal relative to the constant incrementation of either X or Y.
		x = x1;
		y = y1;
		while (y <= y2) // -> Draws points from x1 to x2
		{
		
			if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
				mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			y++;
			if (parametric_value >= 0)
			{
				if (m_slope >=1)
					x++;
				else
					x--;
				parametric_value = parametric_value + 2 * delta_x - 2 * delta_y;
			}
			else
			{
				x = x;
				parametric_value = parametric_value + 2  * delta_x;
			}
		}
	}
}

void	render_map(Map **map, mlx_image_t* image)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	while(map[y])
	{
		while (!map[y][x].end_of_row)
		{
			iso(image, x, y, map);
			if (x >= 1)
				draw_omnidirectional_lineX(image, map[y][x - 1].iso_x, map[y][x - 1].iso_y, map[y][x].iso_x, map[y][x].iso_y);
			if (y >= 1)
				draw_omnidirectional_lineY(image, map[y - 1][x].iso_x, map[y - 1][x].iso_y, map[y][x].iso_x, map[y][x].iso_y);
			x++;
		}
		x = 0;
		y++;
	}
}

int32_t	init_window(Map **map)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	render_map(map, g_img);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
