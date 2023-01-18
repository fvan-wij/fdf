/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:42:53 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/01/18 22:58:58 by flip          ########   odam.nl         */
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
    int previous_x; 
    int previous_y;
	int	tileWidth;

    previous_x = x;
    previous_y = y;
	tileWidth = 20;
    map[y][x].iso_x = (x - y) * tileWidth + (WIDTH/2);
    map[y][x].iso_y = (previous_x + y - map[y][x].z) * (tileWidth / 2) + 450;
	// if ((map[y][x].iso_x  > 0 && map[y][x].iso_x  < WIDTH) && (map[y][x].iso_y  > 0 && map[y][x].iso_y < HEIGHT))
	// 	mlx_put_pixel(image, map[y][x].iso_x, map[y][x].iso_y, 0xFFFFFFFF);
	
}

void	draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;
	
	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;
	
	p = 2 * dy - dx;
 
	while(x < x1)
	{
		// ft_printf("YEET");
		if(p >= 0)
		{
			if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
				mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			if ((x  > 0 && x  < WIDTH) && (y  > 0 && y < HEIGHT))
				mlx_put_pixel(image, x, y, 0xFFFFFFFF);
			p = p + 2 * dy;
		}
		x = x + 1;
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
			if (x > 1)
				draw_line(image, map[y][x - 1].iso_x, map[y][x - 1].iso_y, map[y][x].iso_x, map[y][x].iso_y);
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
	// ft_printf("iso_x = %d\n", map[0][0].iso_x);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
