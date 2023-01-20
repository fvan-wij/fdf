/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 12:13:32 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/01/20 09:35:25 by flip          ########   odam.nl         */
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
// # include <MLX42/MLX42.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 1800
# define HEIGHT 1800

# define 	ROW_END	4242
# define	MAP_END	42424242

typedef struct Map
{
	int		z;
	int		iso_x;
	int		iso_y;
	int		end_of_row;
	int		color;
}	Map;

typedef struct t_meta
{
	Map **map;
	int columns;
	int rows;
	int tileSize;
} t_meta;

typedef struct s_coordinate
{
	int				z;
	int				color;
	int				end_of_row;
	struct s_list	*next;
}	t_coordinate;

// LIST UTILS
void			ft_insert_back(t_coordinate **lst, int coordinate, int row_end);
void			print_tlist(t_coordinate *head);
t_coordinate	*array_to_list(char **arr, int n, t_coordinate *head);

// MEMORY UTILS
void			free_split_points(char **split_points);

// RENDERING & MLX
int32_t			init_window(t_meta *meta);
struct t_meta	*parse_map(int argc, char *argv[], t_meta *meta);

#endif