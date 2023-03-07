/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_interactions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:25:38 by flip              #+#    #+#             */
/*   Updated: 2023/03/07 09:15:23 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void    zoom(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL))
        meta->tileSize += 0.2f;
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
        meta->tileSize -= 0.2f;
    ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
    render_map(meta, meta->g_img);
}

void    move_with_arrow_keys(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT))
		meta->x_offset -= 10;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT))
		meta->x_offset += 10;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_UP))
		meta->y_offset -= 10;
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
		meta->y_offset += 10;
	ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
	render_map(meta, meta->g_img);
}

void    raise_lower(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP))
        meta->z_offset ++;
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
        meta->z_offset --;
    ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
    render_map(meta, meta->g_img);
}

void	change_perspective(t_meta *meta)
{
	if (mlx_is_key_down(meta->mlx, MLX_KEY_T))
        meta->perspective = 1;
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_I))
        meta->perspective = 0;
	ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
    render_map(meta, meta->g_img);
}

void	hook(void *param)
{
	t_meta *meta;
	
	meta = param;
	if (mlx_is_key_down(meta->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(meta->mlx);
	zoom(meta);
	move_with_arrow_keys(meta);	
	raise_lower(meta);
	change_perspective(meta);
}
