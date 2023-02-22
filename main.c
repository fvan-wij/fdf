/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 19:12:40 by fvan-wij      #+#    #+#                 */
/*   Updated: 2023/02/22 17:17:01 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

int32_t	main(int argc, char *argv[])
{
	t_meta	*meta;
	int				fd;

	if (argc != 2)
		return (perror("Error: argc is not equal to 2"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Couldn't open argv"), 1);
	meta = malloc(1 * sizeof(t_meta));
	if (!meta)
		return (EXIT_FAILURE);
	meta = parse_map(fd, meta);
	// ft_printf("Rows = %d\nColumns = %d\n", meta->rows, meta->columns);
	init_window(meta);
	clean_memory_allocations(meta);
	return (EXIT_SUCCESS);
}
