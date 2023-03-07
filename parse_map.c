/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:18 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/07 17:16:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

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
			map[i][j].z = current->z;
			map[i][j].color = current->color;
			map[i][j].x = j;
			j++;
		}
		else if (j == meta->columns)
		{
			j = 0;
			map[i][j].y = i;
			i++;
		}
		current = current->next;
	}
	clear_list(meta->list);
	return (map);
}

t_map	**malloc_2Dstructarray(t_meta *meta)
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

t_meta *create_2Dstructarray(int fd, t_meta *meta)
{
	char			*line;
	char			**split_points;
	t_lstcoordinate	*old_point;

	line = get_next_line(fd);
	old_point = NULL;
	meta->list = ft_calloc(1, sizeof(t_lstcoordinate *));
	if (!meta->list)
		free(meta->list);
	while (line)
	{
		split_points = ft_split(line, ' ');
		free(line);
		old_point = array_to_list(split_points, meta, old_point);
		free_split_points(split_points);
		line = get_next_line(fd);
		meta->rows++;
	}
	meta->map = malloc_2Dstructarray(meta);
	return (meta);
}

t_meta	*parse_map(int fd, t_meta *meta)
{
	meta = create_2Dstructarray(fd, meta);
	if (!meta)
		free_with_exit_code(1, meta);
	return (meta);
}
