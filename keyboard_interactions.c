/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard_interactions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 12:25:38 by flip          #+#    #+#                 */
/*   Updated: 2023/03/07 10:26:05 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#define BPP sizeof(int32_t)

void    zoom(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL))
        meta->tileSize += 0.2f;
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
        meta->tileSize -= 0.2f;
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
	render_map(meta, meta->g_img);
}

void    raise_lower(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP))
        meta->z_offset += 0.1f;
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
        meta->z_offset -= 0.1f;
    render_map(meta, meta->g_img);
}

void	change_perspective(t_meta *meta)
{
	if (mlx_is_key_down(meta->mlx, MLX_KEY_T))
        meta->perspective = 1;
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_I))
        meta->perspective = 0;
    render_map(meta, meta->g_img);
}

void	hook(void *param)
{
	t_meta *meta;
	
	meta = param;
	if (mlx_is_key_down(meta->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(meta->mlx);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL) || mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
		zoom(meta);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT) || mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(meta->mlx, MLX_KEY_UP) || mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
		move_with_arrow_keys(meta);	
	if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP) || mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
		raise_lower(meta);
	if (mlx_is_key_down(meta->mlx, MLX_KEY_T) || mlx_is_key_down(meta->mlx, MLX_KEY_I))
		change_perspective(meta);
}
