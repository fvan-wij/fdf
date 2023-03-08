/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:56:27 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/08 21:08:53 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void draw_menu(t_meta *meta)
{
	mlx_image_t *menu_img;
	int y;

	y = 25;	
	menu_img = mlx_new_image(meta->mlx, MENU_WIDTH, HEIGHT);
	mlx_image_to_window(meta->mlx, menu_img, 0, 0);
	mlx_put_string(meta->mlx, "CONTROLS", 50, y);
	mlx_put_string(meta->mlx, "Move: Arrow keys", 25, y += 50);
	mlx_put_string(meta->mlx, "Zoom: + / -", 25, y += 25);
	mlx_put_string(meta->mlx, "Raise/Lower: Page Up / Page Down", 25, y += 25);
	mlx_put_string(meta->mlx, "MODES", 50, y += 50);
	mlx_put_string(meta->mlx, "Isometric", 25, y += 50);
	mlx_put_string(meta->mlx, "Greyscales", 25, y += 25);
	mlx_put_string(meta->mlx, "Topdown", 25, y += 25);
	mlx_put_string(meta->mlx, "MAP INFO", 50, y += 50);
	mlx_put_string(meta->mlx, ft_strjoin("Rows: ", ft_itoa(meta->rows)), 25, y += 50);
	mlx_put_string(meta->mlx, ft_strjoin("Columns: ", ft_itoa(meta->columns)), 25, y += 25);
	mlx_put_string(meta->mlx, ft_strjoin("Tilesize: ", ft_itoa(meta->tileSize)), 25, y += 25);
}
