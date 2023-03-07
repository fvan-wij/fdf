/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:42:53 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/03/07 10:23:39 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	draw_background(t_meta *meta, uint32_t color)
{
	int x;
	int y;
	
	x = 0;
	y = 0;

	while (x < WIDTH)
	{
		while (y < HEIGHT)
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
	draw_background(meta, BACKGROUND);
	while(y < meta->rows)
	{
		while (x < meta->columns)
		{
			if (meta->perspective == 0)
				draw_isometric_landscape(meta, image, x, y);
			if (meta->perspective == 1)
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
	if (meta->tileSize == 0.0f)
		meta->tileSize = 0.9f;
	meta->x_offset = WIDTH / 2;
	meta->y_offset = HEIGHT / 6;
	meta->z_offset = 0.5f;
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
