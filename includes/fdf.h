/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 12:13:32 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/03/03 16:55:20 by flip          ########   odam.nl         */
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

# define WIDTH 900
# define HEIGHT 900

typedef struct Map
{
	int			x;
	int			y;
	int			z;
	int			iso_x;
	int			iso_y;
	int			iso_z;
	uint32_t	color;
}	Map;

typedef struct s_bresenham
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			cx;
	int			cy;
	int			y;
	int			x;
}	s_line;

typedef struct t_point
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}	s_point;

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
	s_line			point;
	float			tileSize;
	int				tileWidth;
	int				tileHeight;
	int				rows;
	int				columns;
	int				x_offset;
	int				y_offset;
	float			z_offset;
} t_meta;

// LIST UTILS
void			print_tlist(t_coordinate *head);
t_coordinate	*array_to_list(char **arr, t_meta *meta, t_coordinate *old_point);

// MEMORY UTILS
void			free_split_points(char **split_points);
void			free_2Dstructarray(t_meta *meta);
void			clean_memory_allocations(t_meta *meta);
void			clear_list(t_coordinate **list);
void			free_with_exit_code(int error_code, t_meta *meta);

// RENDERING & MLX
int32_t			init_window(t_meta *meta);
t_meta			*parse_map(int fd, t_meta *meta);
void			render_map(t_meta *meta, mlx_image_t* image);
uint32_t		convert_rgb(unsigned int color);

// DRAWING
void	draw_line(mlx_image_t *image, uint32_t color, s_line point, s_point p);
void 	draw_pixel(mlx_image_t *image, int x, int y, uint32_t color);
void	draw_isometric_landscape(t_meta *meta, mlx_image_t *image, int x, int y);

// ARRAY TO HEX
uint32_t    	ft_atoh(char *hex_string);

// KEYBOARD INTERACTION
void			hook(void *param);
void			zoom(t_meta *meta);
void			move_with_arrow_keys(t_meta *meta);
void    		raise_lower(t_meta *meta);

#endif