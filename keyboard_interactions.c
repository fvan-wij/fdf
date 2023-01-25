/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard_interactions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 12:25:38 by flip          #+#    #+#                 */
/*   Updated: 2023/01/25 14:59:31 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void    zoom(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_EQUAL))
        {
            meta->tileSize+=0.2;
            ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
            render_map(meta, meta->g_img);
        }
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_MINUS))
        {
            meta->tileSize-=0.2;
            ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
            render_map(meta, meta->g_img);
        }
}

void    move_with_arrow_keys(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_LEFT))
	{
		meta->x_offset -= 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_RIGHT))
	{
		meta->x_offset += 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_UP))
	{
		meta->y_offset -= 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
	else if (mlx_is_key_down(meta->mlx, MLX_KEY_DOWN))
	{
		meta->y_offset += 5;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
		render_map(meta, meta->g_img);
	}
}

void    raise_lower(t_meta *meta)
{
    if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_UP))
	{
        meta->z_offset += 0.2;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
        render_map(meta, meta->g_img);
    }
    else if (mlx_is_key_down(meta->mlx, MLX_KEY_PAGE_DOWN))
	{
        meta->z_offset -= 0.2;
		ft_bzero(meta->g_img->pixels, sizeof(int) * meta->g_img->width * meta->g_img->height);
        render_map(meta, meta->g_img);
    }
    
}