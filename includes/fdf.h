/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:13:32 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/15 17:31:45 by fvan-wij         ###   ########.fr       */
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
# include <stdint.h>
# include "glfw3.h"
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 1600
# define HEIGHT 1600
# define MENU_WIDTH 250
# define MENU_HEIGHT 1600
# define MENU_OFFSET 50
# define BACKGROUND 0x11111111
# define LINE_COLOR 0xFFFFFFFF

typedef union s_rgba
{
	int32_t	color;
	struct
	{
		int8_t	a;
		int8_t	b;
		int8_t	g;
		int8_t	r;
	};
}	t_rgba;

typedef struct s_map
{
	int			x;
	int			y;
	int			z;
	int			iso_x;
	int			iso_y;
	int			iso_z;
	uint32_t	color;
}	t_map;

typedef struct s_bresenham
{
	int			error[2];
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			cx;
	int			cy;
	int			y;
	int			x;
}	t_line;

typedef struct s_point
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}	t_point;

typedef struct s_coordinate
{
	int					z;
	uint32_t			color;
	struct s_coordinate	*next;
}	t_lstcoordinate;

typedef struct s_menu
{
	mlx_image_t		*menu_bg;
	mlx_image_t		*menu_info_tilesize;
	mlx_image_t		*menu_info_depth;
	int				items;
	int				x;
	int				y;
}	t_menu;

typedef struct s_meta
{
	t_lstcoordinate	**list;
	t_map			**map;
	t_line			point;
	t_menu			*menu;
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	int				mode;
	float			tilesize;
	int				rows;
	int				columns;
	int				x_offset;
	int				y_offset;
	float			z_offset;
}	t_meta;

// MEMORY UTILS
void			free_map_points(char **split_points);
void			free_2d_struct_array(t_meta *meta);
void			clean_memory_allocations(t_meta *meta);
void			clear_list(t_lstcoordinate **list);
void			free_with_exit_code(int error_code, t_meta *meta);

// RENDERING & MLX
int32_t			init_window(t_meta *meta);
void			init_meta(t_meta *meta);
t_meta			*parse_map(int fd, t_meta *meta);
void			render_map(t_meta *meta, mlx_image_t *image);
unsigned int	convert_rgba(unsigned int color);
int				mix_rgba(int r, int g, int b, int a);
int				gradient_color(t_meta *meta, int x, int y);
unsigned int	union_rgba(unsigned int color);

// PERSPECTIVE TRANSLATION
void			translate_to_isometric(int x, int y, t_meta *meta);
void			translate_to_topdown(int x, int y, t_meta *meta);

// DRAWING
void			bresenham_line(mlx_image_t *image, uint32_t color,
					t_line point, t_point p);
void			draw_pixel(mlx_image_t *image, int x, int y, uint32_t color);
void			draw_menu_pixel(mlx_image_t *image, int x, int y,
					uint32_t color);
void			draw_isometric_landscape(t_meta *meta, mlx_image_t *image,
					int x, int y);
void			draw_topdown_landscape(t_meta *meta, mlx_image_t *image,
					int x, int y);
void			draw_gradient_landscape(t_meta *meta, mlx_image_t *image,
					int x, int y);
void			draw_static_menu(t_meta *meta);
void			draw_depth_info(t_meta *meta, t_menu *menu);
void			draw_tilesize_info(t_meta *meta, t_menu *menu);
void			draw_background(t_meta *meta, uint32_t color, int x, int y);
void			draw_menu_background(t_meta *meta);
void			draw_particle_landscape(t_meta *meta,
					mlx_image_t *image, int x, int y);

// UTILITIES
t_lstcoordinate	*convert_array_to_list(char **arr, t_meta *meta,
					t_lstcoordinate *old_point);
void			copy_node_data_zcx(t_map **map, t_lstcoordinate *node,
					int i, int j);
void			copy_node_data_y(t_map **map, int i, int j);

// KEYBOARD INTERACTION
void			hook(void *param);
void			zoom(t_meta *meta);
void			move_with_arrow_keys(t_meta *meta);
void			raise_lower(t_meta *meta);

#endif