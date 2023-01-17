/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:42:53 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/17 18:54:19 by fvan-wij         ###   ########.fr       */
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

void iso(mlx_image_t* image, int x, int y, int z)
{
    int previous_x; 
    int previous_y;
	int	tileWidth;

    previous_x = x;
    previous_y = y;
	tileWidth = 50;
    x = (x - y) * tileWidth;
    y = (previous_x + y + - z) * (tileWidth / 2);
	
	printf("x = %i	y = %i\n", x, y);
	mlx_put_pixel(image, x + 850, y + 200, 0xFFFFFFFF);
}

void	render_map(Map **map, mlx_image_t* image)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	while(map[y])
	{
		while (!map[y][x].nl_boolean)
		{
			ft_printf("map = %d\n", map[y][x].z);
			iso(image, x, y, map[y][x].z);
			if (map[y][x].z == ROW_END)
			{
				x = 0;
				break ;
			}
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
