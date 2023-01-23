/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:40 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/23 16:12:07 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

int32_t	main(int argc, char *argv[])
{
	t_meta	*meta;
	
	meta = malloc(1 * sizeof(t_meta));
	meta = parse_map(argc, argv, meta);
	ft_printf("Rows = %d\nColumns = %d\n", meta->rows, meta->columns);
	init_window(meta);
	return (0);
}
