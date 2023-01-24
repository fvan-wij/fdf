/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:13:32 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/25 00:24:59 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <memory.h>
# include <unistd.h>
# include "glfw3.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 1800
# define HEIGHT 1800

typedef struct Map
{
	int			x;
	int			y;
	int			z;
	int			iso_x;
	int			iso_y;
	int			end_of_row;
	uint32_t	color;
}	Map;

typedef struct s_coordinate
{
	int					z;
	uint32_t			color;
	struct s_coordinate	*next;
}	t_coordinate;

typedef struct t_meta
{
	Map				**map;
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_coordinate	**list;
	float			tileSize;
	int				rows;
	int				columns;
	int				x_offset;
	int				y_offset;
	int				z_offset;
	int				x_limit;
	int				y_limit;
} t_meta;

// LIST UTILS
void			print_tlist(t_coordinate *head);
t_coordinate	*array_to_list(char **arr, t_meta *meta, t_coordinate *old_point);

// MEMORY UTILS
void			free_split_points(char **split_points);
void			free_2Dstructarray(t_meta *meta);
void			clean_memory_allocations(t_meta *meta);

// RENDERING & MLX
int32_t			init_window(t_meta *meta);
struct t_meta	*parse_map(int argc, char *argv[], t_meta *meta);

#endif