/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:13:32 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/16 19:22:38 by fvan-wij         ###   ########.fr       */
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

# define WIDTH 900
# define HEIGHT 900

# define 	ROW_END	4242
# define	MAP_END	42424242

typedef struct Map
{
	int		z;
	int		nl_boolean;
	char	*hex;
}	Map;

typedef struct s_coordinate
{
	int				x;
	int				nl_boolean;
	struct s_list	*next;
}	t_coordinate;

// LIST UTILS
void			ft_insert_back(t_coordinate **lst, int coordinate, int nl_boolean);
void			print_tlist(t_coordinate *head);
t_coordinate	*array_to_list(char **arr, int n, t_coordinate *head);

// MEMORY UTILS
void			free_split_points(char **split_points);

// RENDERING & MLX
int32_t	init_window(Map **map);
struct Map **parse_map(int argc, char *argv[], Map **map);

#endif