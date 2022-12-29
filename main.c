#include "../libft/libft.h"
#include "../includes/fdf.h"

//TO DO
// * Write a function that converts a hexadecimal string to a hexadecimal integer
// * Freeing double pointer gives segfaults



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

int	count_coordinates(char *mapdata)
{
	int		i;
	int		c_count;

	i = 0;
	c_count = 0;
	while (mapdata[i])
	{	
		while (mapdata[i] && mapdata[i] != ' ')
		{
			if (mapdata[i] == '\n' || mapdata[i] == ',')
				break ;
			i++;
		}
		c_count++;
		while (mapdata[i] && (mapdata[i] == ' ' || mapdata[i] == '\n' || mapdata[i] == ','))
			i++;
	}
	return (c_count);
}

struct Map	**malloc_2Dstructarray(char *mapdata)
{
	Map **point;
	int	x;
	int	y;
	int	i;
	int	noc;

	x = count_coordinates(mapdata);
	y = count_lines(mapdata);
	point = malloc(y * sizeof(Map *));
	noc = x / y;
	i = 0;
	while (i < y)
	{
		point[i] = malloc(noc * sizeof(Map));
		i++;
	}
	return (point);
}

void	free_doubleptr(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

struct Map	**create_2Dstructarray(char *mapdata, int x, int y) //Creates a new 2D integer array consisting of all the map coordinates. 
{
	int		i;
	int		j;
	char	**points_arr;
	Map		**point;

	point = malloc_2Dstructarray(mapdata);
	points_arr = ft_split_nl(mapdata, ' ');
	i = 0;
	j = 0;
	while (i < y)
	{
		while (*points_arr && j < (x / y))
		{
			if (ft_strchr(*points_arr, 'x'))
				ft_printf("%s\n", *points_arr); // ->Convert from array to hex
			point[i][j].z = ft_atoi(*points_arr);
			points_arr++;
			j++;
		}
		point[i][j].z = 4242; //4242 functions as a null-terminator.
		j = 0;
		i++;
	}
	// free_doubleptr(points, x); // <- segfaults
	return (free(mapdata), point);
}

void	print_map(Map **map, int y)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while(i < y)
	{
		while (map[i][j].z != 4242)
		{
			ft_printf("%d", map[i][j].z);
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
	Map		**point;
	int		x;
	int		y;

	if (argc != 2)
		ft_printf("Error, provide executable + mapname in order to run this program.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Incorrect fd\n"), 1);
	mapdata = get_mapdata(fd);
	x = count_coordinates(mapdata);
	y = count_lines(mapdata);
	point = create_2Dstructarray(mapdata, x, y);
	print_map(point, y);
	return (0);
}
