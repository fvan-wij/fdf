/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:40 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/18 17:14:36 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

int32_t	main(int argc, char *argv[])
{
	Map 	**map;
	t_meta	*meta;

	meta = malloc(sizeof(t_meta));
	meta->map = NULL;
	meta->map = parse_map(argc, argv, meta->map);
	// init_window(meta.map);
	return (0);
}
