/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_interactions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:25:38 by flip              #+#    #+#             */
/*   Updated: 2023/03/14 17:49:57 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_meta *meta)
{
	if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL))
		meta->tilesize += 0.5f;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
		meta->tilesize -= 0.5f;
	draw_tilesize_info(meta, meta->menu);
	render_map(meta, meta->g_img);
}

void	move_with_arrow_keys(t_meta *meta)
{
	if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT))
		meta->x_offset -= 10;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT))
		meta->x_offset += 10;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_UP))
		meta->y_offset -= 10;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
		meta->y_offset += 10;
	render_map(meta, meta->g_img);
}

void	raise_lower(t_meta *meta)
{
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP))
		meta->z_offset += 0.01f * (meta->tilesize * 0.5f);
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
		meta->z_offset -= 0.01f * (meta->tilesize * 0.5f);
	draw_depth_info(meta, meta->menu);
	render_map(meta, meta->g_img);
}

void	change_mode(t_meta *meta)
{
	if (mlx_is_key_down(meta->mlx, MLX_KEY_G))
		meta->mode = 0;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_I))
		meta->mode = 1;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_T))
		meta->mode = 2;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_P))
		meta->mode = 3;
	render_map(meta, meta->g_img);
}

void	hook(void *param)
{
	t_meta	*meta;

	meta = param;
	if (mlx_is_key_down(meta->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(meta->mlx);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
		zoom(meta);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
		move_with_arrow_keys(meta);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
		raise_lower(meta);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_T)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_I)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_G)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_P))
		change_mode(meta);
}
