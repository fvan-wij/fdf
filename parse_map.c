/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:18 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/10 19:27:05 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

static void	copy_node_data(t_meta *meta, t_lstcoordinate *node, t_map **map, int i, int j)
{
	if (j != meta->columns)
	{
		map[i][j].z = node->z;
		map[i][j].color = node->color;
		map[i][j].x = j;	
	}
	else if (j == meta->columns)
		map[i][j].y = i;		
}

t_map	**convert_list_to_struct(t_meta *meta, t_map **map)
{
	t_lstcoordinate	*current;
	int				i;
	int				j;

	current = *meta->list;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		if (j != meta->columns)
		{
			copy_node_data(meta, current, map, i, j);
			j++;
		}
		else if (j == meta->columns)
		{
			j = 0;
			copy_node_data(meta, current, map, i, j);
			i++;
		}
		current = current->next;
	}
	clear_list(meta->list);
	return (map);
}

t_map	**malloc_2d_struct_array(t_meta *meta)
{
	t_map			**map;
	int				i;

	map = ft_calloc(meta->rows + 1, sizeof(t_map *));
	i = 0;
	while (i < meta->rows)
	{
		map[i] = ft_calloc(meta->columns + 1, sizeof(t_map));
		i++;
	}
	map = convert_list_to_struct(meta, map);
	return (map);
}

t_meta	*create_2d_struct_array_from_map(int fd, t_meta *meta)
{
	char			*line;
	char			**map_points;
	t_lstcoordinate	*old_point;

	line = get_next_line(fd);
	old_point = NULL;
	meta->list = ft_calloc(1, sizeof(t_lstcoordinate *));
	if (!meta->list)
		free(meta->list);
	while (line)
	{
		map_points = ft_split(line, ' ');
		free(line);
		old_point = convert_array_to_list(map_points, meta, old_point);
		free_map_points(map_points);
		line = get_next_line(fd);
		meta->rows++;
	}
	meta->map = malloc_2d_struct_array(meta);
	return (meta);
}

t_meta	*parse_map(int fd, t_meta *meta)
{
	meta = create_2d_struct_array_from_map(fd, meta);
	if (!meta)
		free_with_exit_code(1, meta);
	return (meta);
}
