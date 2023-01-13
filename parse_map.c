/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:18 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/13 22:53:53 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	free_split_points(char **split_points)
{
	int	i;

	i = 0;
	while (split_points[i])
	{
		free(split_points[i]);
		i++;
	}
	free(split_points);
}

struct Map	**malloc_2Dstructarray(int rows, int columns)
{
	Map **map;
	int	i;

	map = ft_calloc(rows + 1, sizeof(Map *));
	i = 0;
	while (i < rows)
	{
		map[i] = ft_calloc(columns + 1, sizeof(Map));
		i++;
	}
	return (map);
}

struct	Map	**create_2Dstructarray(int fd)
{
	int				rows;
	char			*line;
	Map				**map;
	t_coordinate	*head;
	char			**split_points;
	int				n;
	int				columns;

	line = get_next_line(fd);
	rows = 0;
	n = 0;
	columns = 0;
	while (line)
	{
		// -> split line, atoi + append to node
		split_points = ft_split(line, ' ');
		while (split_points[n])
			n++;
		free(line);
		head = array_to_list(split_points, n);
		free_split_points(split_points);
		print_tlist(head);
		line = get_next_line(fd);
		if (n > columns)
			columns = n;
		n = 0;
		rows++;
	}
	ft_printf("i = %d\n", rows);
	ft_printf("columns = %d\n", columns);
	// map = ft_calloc(rows, sizeof(Map *));
	map = malloc_2Dstructarray(rows, columns);
	return (map);
}

int	main(int argc, char *argv[])
{
	int	fd;
	Map	**map;

	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Incorrect fd\n"), 1);
	// Write function that reads line (get_next_line) from map and appends it to a linked list.
	// This function should also split each line(ft_split), and appends the coordinates to each node of the linked list. While appending, convert string to integer (ft_atoi)
	// This function should keep track of the amount of rows in order to dynamically allocate 2D array. Before allocating collumns for each row, this function should keep track of the longest row (= malloc for columns)
	map = create_2Dstructarray(fd);
	return (0); //Success
}
