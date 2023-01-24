/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:18 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/25 00:10:57 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

struct Map	**convert_list_to_struct(t_meta *meta, Map **map)
{
	t_coordinate	*current;
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
			map[i][j].x = j;
			j++;
		}
		else if (j == meta->columns)
		{
			j = 0;
			map[i][j].y = i;
			i++;
		}
		free(current);
		current = current->next;
	}
	free(meta->list);
	ft_printf("META->**LIST CLEANED!\n");
	return (map);
}

struct Map	**malloc_2Dstructarray(t_meta *meta)
{
	Map				**map;
	int				i;

	map = ft_calloc(meta->rows + 1, sizeof(Map *));
	i = 0;
	while (i < meta->rows)
	{
		map[i] = ft_calloc(meta->columns + 1, sizeof(Map));
		i++;
	}
	map = convert_list_to_struct(meta, map);
	return (map);
}

struct	t_meta *create_2Dstructarray(int fd, t_meta *meta)
{
	char			*line;
	char			**split_points;
	t_coordinate	*old_point;

	line = get_next_line(fd);
	old_point = NULL;
	meta->list = ft_calloc(1, sizeof(t_coordinate *));
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

void	print_map(t_meta *meta)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while(i < meta->rows)
	{
		while (j < meta->columns)
		{
			ft_printf("%d ", meta->map[i][j].z); 
			j++;
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
}

struct t_meta	*parse_map(int argc, char *argv[], t_meta *meta)
{
	int				fd;

	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	meta = create_2Dstructarray(fd, meta);
	print_map(meta);
	return (meta);
}
