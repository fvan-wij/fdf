/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:56:27 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/14 17:49:52 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	print_menu_b(t_meta *meta, t_menu *menu)
{
	char	*rows;
	char	*columns;

	rows = ft_itoa(meta->rows);
	columns = ft_itoa(meta->columns);
	mlx_put_string(meta->mlx, "MAP INFO",
		menu->x - 25, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Rows: ",
		menu->x, (menu->items) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, rows,
		menu->x + 100, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Columns: ",
		menu->x, (menu->items) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, columns,
		menu->x + 100, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Tilesize: ",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Depth: ",
		menu->x, (menu->items) * menu->y + MENU_OFFSET);
	free(rows);
	free(columns);
}

static void	print_menu(t_meta *meta, t_menu *menu)
{
	mlx_put_string(meta->mlx, "CONTROLS",
		menu->x - 25, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Move: Arrow keys",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Zoom in: +",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Zoom out: -",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Raise: Page Up",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Lower: Page Down",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "MODES",
		menu->x - 25, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Isometric: I",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Greyscales: G",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Topdown: T",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	mlx_put_string(meta->mlx, "Particles: P",
		menu->x, (menu->items++) * menu->y + MENU_OFFSET);
	print_menu_b(meta, meta->menu);
}

void	draw_tilesize_info(t_meta *meta, t_menu *menu)
{
	char	*tilesize_temp;

	tilesize_temp = ft_itoa(meta->tilesize);
	if (meta->menu->menu_info_tilesize)
		mlx_delete_image(meta->mlx, meta->menu->menu_info_tilesize);
	meta->menu->menu_info_tilesize = mlx_put_string(meta->mlx, tilesize_temp,
			menu->x + 100, (menu->items - 1) * menu->y + MENU_OFFSET);
	free(tilesize_temp);
}

void	draw_depth_info(t_meta *meta, t_menu *menu)
{
	char	*depth_temp;

	depth_temp = ft_itoa(meta->z_offset * 100);
	if (meta->menu->menu_info_depth)
		mlx_delete_image(meta->mlx, meta->menu->menu_info_depth);
	meta->menu->menu_info_depth = mlx_put_string(meta->mlx, depth_temp,
			menu->x + 100, (menu->items) * menu->y + MENU_OFFSET);
	free(depth_temp);
}

void	draw_static_menu(t_meta *meta)
{
	draw_menu_background(meta);
	print_menu(meta, meta->menu);
	draw_tilesize_info(meta, meta->menu);
	draw_depth_info(meta, meta->menu);
}
