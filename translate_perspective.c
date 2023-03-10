/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_perspective.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:23:57 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/10 19:38:00 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	translate_to_isometric(int x, int y, t_meta *meta)
{
	meta->map[y][x].iso_z = meta->map[y][x].z * meta->z_offset;
	meta->map[y][x].iso_x = (x - y) * meta->tilesize + meta->x_offset;
	meta->map[y][x].iso_y = (x + y - meta->map[y][x].iso_z)
		* (meta->tilesize * 0.5) + meta->y_offset;
}

void	translate_to_topdown(int x, int y, t_meta *meta)
{
	meta->map[y][x].x = (x * meta->tilesize) + meta->x_offset;
	meta->map[y][x].y = (y * meta->tilesize) + meta->y_offset;
}
