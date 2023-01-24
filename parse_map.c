/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:28:18 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/01/24 17:39:13 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
// #include "../includes/fdf.h"
#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
// #include "../MLX42/include/MLX42/MLX42.h"

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
			map[i][j].end_of_row = 0;
			j++;
		}
		else if (j == meta->columns)
		{
			
			map[i][j].end_of_row = 1;
			j = 0;
			map[i][j].y = i;
			i++;
		}
		current = current->next;
	}
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
	int				n;
	t_coordinate	*old_point;

	line = get_next_line(fd);
	old_point = NULL;
	meta->list = ft_calloc(1, sizeof(t_coordinate *));
	meta->rows = 0;
	meta->columns = 0;
	n = 0;
	while (line)
	{
		split_points = ft_split(line, ' ');
		while (split_points[n])
			n++;
		free(line);
		old_point = array_to_list(split_points, n, meta, old_point);
		free_split_points(split_points);
		line = get_next_line(fd);
		if (n > meta->columns)
			meta->columns = n;
		n = 0;
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

	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	meta = create_2Dstructarray(fd, meta);
	// print_map(meta);
	return (meta);
}
