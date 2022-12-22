#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	int		len;
	char	*strjoin;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	strjoin = malloc(len * sizeof(char));
	if (!strjoin)
		return (free(s1), NULL);
	ft_strcpy(strjoin, s1);
	ft_strcpy(strjoin + ft_strlen(s1), s2);
	free(s1);
	return (strjoin);
}


int	**create_2D_int(int fd, int *noc)
{
	int 	n;
	int 	i;
	int 	c_count;
	int 	**int_array;
	char	*line;

	n = 0;
	i = 0;
	c_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while(line[i] != '\0')
		{
			if (line[i] == 32)
				c_count++;
			i++;
		}
		i = 0;
		n++;
	}
	i = 0;
	int_array = malloc(n * sizeof(int *));
	while (i < n)
	{
		int_array[i] = malloc((c_count / n) * sizeof(int));
		i++;
	}
	*noc = c_count / n;
	return (int_array);
}

int	count_lines(char *argv[])
{
	int		fd;
	int		bytes;
	char	buffer[50];
	char	*storage;
	int		i;

	fd = open(argv[1], O_RDONLY);
	bytes = 1;
	while(bytes > 0)
	{
		bytes = read(fd, buffer, 50);
		ft_strjoin_and_free(storage, buffer);
	}
	while (*storage)
	{
		if (storage[i] == '\n')
			i++;
		*storage++;
	}
	return (free(storage), i);
}


int	main(char *argv[])
{
	int		fd;
	int		fd2;
	int		*noc;
	char	*line;
	char	**points;
	int		**coordinates_array;
	int 	i;
	int		j;
	
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	coordinates_array = create_2D_int(fd, &noc);
	ft_printf("NOC = %d\n", noc);
	i = 0;
	j = 0;
	while (1)
	{
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		points = ft_split(line, ' ');
		while (i < (int)noc)
		{
			coordinates_array[j][i] = ft_atoi(points[i]);
			i++;
		}
		i = 0;
		j++;
	}

	ft_printf("%d", coordinates_array[2][7]);
	ft_printf("%d", count_lines(argv[1]));
	
}
