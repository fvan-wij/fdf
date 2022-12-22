#include "libft.h"
#include "fdf.h"

//TO DO
// * Fix segfaults on bigger/other maps
// * Fix parsing for hex values
// * Merge printf with libft

char	*get_mapdata(int fd)
{
	char	*mapdata;
	char	buffer[1000];
	int		bytes;

	mapdata = ft_calloc(1, 1);
	if (!mapdata)
		exit (1);
	bytes = 1;
	while(bytes > 0)
	{
		bytes = read(fd, buffer, 1000);
		if (bytes == -1)
		{
			free(mapdata);
			exit (1);
		}
		buffer[bytes] = '\0';
		mapdata = ft_strjoin_and_free(mapdata, buffer);
		if (!mapdata)
			exit (1);
	}
	return (mapdata);
}

int	count_lines(char *mapdata) //Counts the number of lines (Y)
{
	int		i;

	i = 0;
	while (*mapdata != '\0')
	{
		if (*mapdata == '\n')
			i++;
		mapdata++;
	}
	return (i);
}

int	count_coordinates(char *mapdata) //Counts the number of coordinates (X)
{
	int		i;

	i = 0;
	while (*mapdata != '\0')
	{
		if (*mapdata == ' ')
			i++;
		mapdata++;
	}
	return (i);
}

int	**malloc_2Dmap(char *mapdata)
{
	int	**int_array;
	int	x;
	int	y;
	int	i;
	int	noc;

	x = count_coordinates(mapdata);
	y = count_lines(mapdata);
	int_array = malloc(y * sizeof(int *));
	noc = x / y;
	i = 0;
	while (i < y)
	{
		int_array[i] = malloc(noc * sizeof(int));
		i++;
	}
	return (int_array);
}

int	**create_2Dmap(char *mapdata, int x, int y) //Creates a new 2D integer array consisting of all the map coordinates. 
{
	int		i;
	int		j;
	int 	**int_array;
	char	**points;

	int_array = malloc_2Dmap(mapdata);
	points = ft_split(mapdata, ' ');
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < (x / y))
		{
			int_array[i][j] = ft_atoi(*points);
			points++;
			j++;
		}
		int_array[i][j] = 4242; //4242 functions as a null-terminator.
		j = 0;
		i++;
	}
	return (int_array);
}

void	print_map(int **map, int y)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while(i < y)
	{
		while (map[i][j] != 4242)
		{
			ft_printf("%d", map[i][j]);
			j++;
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[]) //Compile as follows: make && ./fdf ./test_maps/10-2.fdf
{
	int		fd;
	char	*mapdata;
	int		**map;
	int		x;
	int		y;

	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.");
	fd = open(argv[1], O_RDONLY);
	mapdata = get_mapdata(fd);
	x = count_coordinates(mapdata);
	y = count_lines(mapdata);
	map = create_2Dmap(mapdata, x, y);
	print_map(map, y);
	return (0);
}
