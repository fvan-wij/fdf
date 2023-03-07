/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:42:53 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/07 22:48:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	draw_background(t_meta *meta, uint32_t color, int x, int y)
{
	while (x <= WIDTH)
	{
		while (y <= HEIGHT)
		{
			draw_pixel(meta->g_img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	render_map(t_meta *meta, mlx_image_t* image)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	draw_background(meta, convert_rgba(BACKGROUND), x, y);
	while(y < meta->rows)
	{
		while (x < meta->columns)
		{
			if (meta->mode == 0)
				draw_psychedelic_landscape(meta, image, x, y);
			if (meta->mode == 1)
				draw_isometric_landscape(meta, image, x, y);
			if (meta->mode == 2)
				draw_topdown_landscape(meta, image, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int32_t	init_window(t_meta *meta)
{
	meta->tileSize = WIDTH / (meta->columns + meta->rows);
	if (meta->tileSize == 0)
		meta->tileSize = 1;
	meta->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!meta->mlx)
		exit(EXIT_FAILURE);
	meta->g_img = mlx_new_image(meta->mlx, WIDTH, HEIGHT);
	render_map(meta, meta->g_img);
	mlx_image_to_window(meta->mlx, meta->g_img, 0, 0);
	mlx_loop_hook(meta->mlx, &hook, meta);
	mlx_loop(meta->mlx);
	mlx_delete_image(meta->mlx, meta->g_img);
	mlx_terminate(meta->mlx);
	return (EXIT_SUCCESS);
}
