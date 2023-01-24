/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:42:53 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/01/24 14:58:27 by flip          ########   odam.nl         */
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

void translate_to_isometric(int x, int y, t_meta *meta)
{
    meta->map[y][x].iso_x = (x - y) * meta->tileSize + (WIDTH/2);
    meta->map[y][x].iso_y = (x + y - meta->map[y][x].z) * (meta->tileSize / 2) + 450;
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

void	render_map(t_meta *meta, mlx_image_t* image)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	while(y < meta->rows)
	{
		while (x < meta->columns)
		{
			translate_to_isometric(x, y, meta);
			if (x >= 1)
				draw_omnidirectional_lineX(image, meta->map[y][x - 1].iso_x + meta->x_offset, meta->map[y][x - 1].iso_y + meta->y_offset, meta->map[y][x].iso_x + meta->x_offset, meta->map[y][x].iso_y + meta->y_offset);
			if (y >= 1)
				draw_omnidirectional_lineY(image, meta->map[y - 1][x].iso_x + meta->x_offset, meta->map[y - 1][x].iso_y + meta->y_offset, meta->map[y][x].iso_x + meta->x_offset, meta->map[y][x].iso_y + meta->y_offset);
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
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PERIOD))	
	{
		meta->tileSize+=0.1;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}	
	if (mlx_is_key_down(meta->mlx, MLX_KEY_COMMA))	
	{
		meta->tileSize-=0.1;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT))
	{
		meta->x_offset -= 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT))
	{
		meta->x_offset += 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_UP))
	{
		meta->y_offset -= 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
	{
		meta->y_offset += 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
	{
		meta->columns--;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL))
	{
		
		if (meta->columns < meta->x_limit)
		{
			meta->columns++;
			ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
			render_map(meta, meta->g_img);
		}
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP))
	{
		meta->rows--;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
	{
		
		if (meta->rows < meta->y_limit)
		{
			meta->rows++;
			ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
			render_map(meta, meta->g_img);
		}
	}
}

int32_t	init_window(t_meta *meta)
{
	meta->tileSize = 10.0;
	meta->x_limit = meta->columns;
	meta->y_limit = meta->rows;
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
