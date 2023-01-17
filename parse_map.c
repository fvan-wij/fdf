/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:18 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/17 17:06:03 by fvan-wij         ###   ########.fr       */
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
		if (current->nl_boolean == 0)
		{
			map[i][j].z = current->x;
			map[i][j].nl_boolean = 0;
			j++;
		}
		else if (current->nl_boolean == 1)
		{
			map[i][j].nl_boolean = 1;
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

struct	Map	**create_2Dstructarray(int fd, Map **map, t_coordinate *head)
{
	int				rows;
	char			*line;
	char			**split_points;
	int				n;
	int				columns;

	line = get_next_line(fd);
	rows = 0;
	n = 0;
	columns = 0;
	while (line)
	{
		split_points = ft_split(line, ' ');
		while (split_points[n])
			n++;
		free(line);
		head = array_to_list(split_points, n, head);
		free_split_points(split_points);
		line = get_next_line(fd);
		if (n > columns)
			columns = n;
		n = 0;
		rows++;
	}
	// ft_printf("i = %d\ncolumns = %d\n", rows, columns);
	map = malloc_2Dstructarray(rows, columns, head);
	return (map);
}

void	print_map(Map **map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while(map[i])
	{
		while (!map[i][j].nl_boolean)
		{
			ft_printf("%d ", map[i][j].z); 
			if (map[i][j].z == ROW_END)
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

struct Map **parse_map(int argc, char *argv[], Map **map)
{
	int				fd;
	t_coordinate 	*head;

	head = NULL; // -> Not intilializing head of linked list causes segfaults on Linux!
	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	map = create_2Dstructarray(fd, map, head);
	// print_map(map);
	return (map);
}
