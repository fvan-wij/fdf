/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:40 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/09 20:05:27 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	init_meta(t_meta *meta)
{
	t_menu *menu;
	
	menu = malloc(sizeof(t_menu));
	meta->menu = menu;
	meta->menu->x = 50;
	meta->menu->y = HEIGHT / (13 * 4);
	meta->rows = 0;
	meta->columns = 0;
	meta->x_offset = MENU_WIDTH * 3;
	meta->y_offset = HEIGHT / 4;
	meta->z_offset = 1.0f;
	
}

void f()
{
	system("Leaks fdf");
}

int32_t	main(int argc, char *argv[])
{
	t_meta	*meta;
	int		fd;
	atexit(f);
	if (argc != 2)
		return (perror("Error: argc is not equal to 2"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Couldn't open argv"), 1);
	meta = malloc(1 * sizeof(t_meta));
	init_meta(meta);
	if (!meta)
		return (EXIT_FAILURE);
	meta = parse_map(fd, meta);
	init_window(meta);
	clean_memory_allocations(meta);
	return (EXIT_SUCCESS);
}
