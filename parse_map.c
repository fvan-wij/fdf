/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:18 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/23 18:08:25 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
// #include "../includes/fdf.h"
#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
// #include "../MLX42/include/MLX42/MLX42.h"

struct Map	**convert_list_to_struct(t_coordinate *head, Map **map)
{
	t_coordinate	*current;
	int				i;
	int				j;
	
	current = head;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		if (current->end_of_row == 0)
		{
			map[i][j].z = current->z;
			map[i][j].end_of_row = 0;
			j++;
		}
		else if (current->end_of_row == 1)
		{
			map[i][j].end_of_row = 1;
			j = 0;
			i++;
		}
		current = current->next;
	}
	return (map);
}

struct Map	**malloc_2Dstructarray(int rows, int columns, t_coordinate *head)
{
	Map				**map;
	int				i;

	map = ft_calloc(rows + 1, sizeof(Map *));
	i = 0;
	while (i < rows)
	{
		map[i] = ft_calloc(columns + 1, sizeof(Map));
		i++;
	}
	map = convert_list_to_struct(head, map);
	return (map);
}

struct	t_meta *create_2Dstructarray(int fd, t_meta *meta, t_coordinate *head)
{
	char			*line;
	char			**split_points;
	int				n;

	line = get_next_line(fd);
	meta->rows = 0;
	meta->columns = 0;
	n = 0;
	while (line)
	{
		split_points = ft_split(line, ' ');
		while (split_points[n])
			n++;
		free(line);
		head = array_to_list(split_points, n, head);
		free_split_points(split_points);
		line = get_next_line(fd);
		if (n > meta->columns)
			meta->columns = n;
		n = 0;
		meta->rows++;
	}
	meta->map = malloc_2Dstructarray(meta->rows, meta->columns, head);
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
		while (!meta->map[i][j].end_of_row)
		{
			ft_printf("%d ", meta->map[i][j].z); 
			if (meta->map[i][j].end_of_row == 1)
			{
				j = 0;
				break ;
			}
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
	t_coordinate 	*head;

	head = NULL; // -> Not intilializing head of linked list causes segfaults on Linux!
	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	meta = create_2Dstructarray(fd, meta, head);
	// print_map(meta);
	return (meta);
}
