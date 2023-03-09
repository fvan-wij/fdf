/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:56:27 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/09 20:03:59 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void draw_menu_background(t_meta *meta)
{
	meta->menu->menu_bg = mlx_new_image(meta->mlx, MENU_WIDTH, HEIGHT);	
	int i;
	int j;

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

void print_menu(t_meta *meta)
{
	char *rows;
	char *columns;

	rows = ft_itoa(meta->rows);
	columns = ft_itoa(meta->columns);
	mlx_put_string(meta->mlx, "CONTROLS", meta->menu->x - 25, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Move: Arrow keys", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Zoom in: +", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Zoom out: -", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Raise: Page Up", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Lower: Page Down", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "MODES", meta->menu->x - 25, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Isometric: I",meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Greyscales: G", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Topdown: T", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "MAP INFO", meta->menu->x - 25, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Rows: ", meta->menu->x, meta->menu->menu_items * meta->menu->y + 25);
	mlx_put_string(meta->mlx, rows, meta->menu->x + 100, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Columns: ", meta->menu->x, meta->menu->menu_items * meta->menu->y + 25);
	mlx_put_string(meta->mlx, columns, meta->menu->x + 100, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Tilesize: ", meta->menu->x, meta->menu->menu_items++ * meta->menu->y + 25);
	mlx_put_string(meta->mlx, "Depth: ", meta->menu->x, meta->menu->menu_items * meta->menu->y + 25);
	free(rows);
	free(columns);
}

void draw_static_menu(t_meta *meta)
{
	draw_menu_background(meta);
	print_menu(meta);
	draw_tilesize_info(meta);
	draw_depth_info(meta);
}

void	draw_tilesize_info(t_meta *meta)
{
	char *tilesize_temp;
	
	tilesize_temp = ft_itoa(meta->tileSize);
	if (meta->menu->menu_info_tilesize)
		mlx_delete_image(meta->mlx, meta->menu->menu_info_tilesize);
	meta->menu->menu_info_tilesize = mlx_put_string(meta->mlx, tilesize_temp, meta->menu->x + 100, (meta->menu->menu_items - 1) * meta->menu->y + 25);
	free(tilesize_temp);
}

void	draw_depth_info(t_meta *meta)
{
	char *depth_temp;

	depth_temp = ft_itoa(meta->z_offset * 100);
	if (meta->menu->menu_info_depth)
		mlx_delete_image(meta->mlx, meta->menu->menu_info_depth);
	meta->menu->menu_info_depth = mlx_put_string(meta->mlx, depth_temp, meta->menu->x + 100, meta->menu->menu_items * meta->menu->y + 25);
	free(depth_temp);
}
