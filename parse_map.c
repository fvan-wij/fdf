/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:28:18 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/01/15 20:37:08 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define ROW_END	4242
#define	MAP_END	42424242

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

struct Map	**malloc_2Dstructarray(int rows, int columns, t_coordinate *head)
{
	Map				**map;
	t_coordinate	*current;
	int				i;
	int				j;

	map = ft_calloc(rows + 1, sizeof(Map *));
	i = 0;
	while (i < rows)
	{
		map[i] = ft_calloc(columns + 1, sizeof(Map));
		i++;
	}
	current = head;
	// i = 0;
	// j = 0;
	// ft_printf("Size of lst = %d\n", ft_lstsize(current));
	// while (current != NULL)
	// {
	// 	map[i][j].z = current->x;
	// 	j++;
	// 	if (j >= columns)
	// 	{
	// 		map[i][j].z = ROW_END;
	// 		j = 0;
	// 		i++;
	// 	}
	// 	current = current->next;
	// }
	// map[i][j].z = MAP_END;
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
	ft_printf("i = %d\ncolumns = %d\n", rows, columns);
	map = malloc_2Dstructarray(rows, columns, head);
	return (map);
}

void	print_map(Map **map)
{
	int i;
	
	i = 0;
	while(map[0][i].z != MAP_END)
	{
		if (map[0][i].z != ROW_END)
			ft_printf("%d ", map[0][i].z);
		if (map[0][i].z == ROW_END)
			ft_printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	fd;
	Map	**map;
	t_coordinate *head;

	head = NULL; // -> Not intilializing head of linked list causes segfaults on Linux!
	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Incorrect fd\n"), 1);
	map = create_2Dstructarray(fd, map, head);
	// print_map(map);
	// ft_printf("Map Z = %d\n", map[0][22].z);
	return (0); //Success
}
