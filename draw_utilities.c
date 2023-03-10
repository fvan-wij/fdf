/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:41:17 by flip              #+#    #+#             */
/*   Updated: 2023/03/10 18:27:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	draw_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if ((x >= MENU_WIDTH && x < WIDTH) && (y >= 0 && y < HEIGHT))
		mlx_put_pixel(image, x, y, color);
}

void	draw_menu_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if ((x >= 0 && x < MENU_WIDTH) && (y >= 0 && y < HEIGHT))
		mlx_put_pixel(image, x, y, color);
}

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

void	draw_menu_background(t_meta *meta)
{
	int	i;
	int	j;

	meta->menu->menu_bg = mlx_new_image(meta->mlx, MENU_WIDTH, HEIGHT);
	i = 0;
	j = 0;
	mlx_image_to_window(meta->mlx, meta->menu->menu_bg, 0, 0);
	while (i < MENU_WIDTH)
	{
		while (j < HEIGHT)
		{
			draw_menu_pixel(meta->menu->menu_bg, i, j, 0x191919FF);
			j++;
		}
		j = 0;
		i++;
	}
	while (j < HEIGHT)
	{
		i = MENU_WIDTH;
		draw_menu_pixel(meta->menu->menu_bg, i - 1, j, 0x77777777);
		j++;
	}
}
