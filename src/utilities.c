/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:08:39 by flip              #+#    #+#             */
/*   Updated: 2023/03/14 17:50:11 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	copy_node_data_zcx(t_map **map, t_lstcoordinate *node, int i, int j)
{
	map[i][j].z = node->z;
	map[i][j].color = node->color;
	map[i][j].x = j;
}

void	copy_node_data_y(t_map **map, int i, int j)
{
	map[i][j].y = i;
}

void	print_map(t_meta *meta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < meta->rows)
	{
		while (j < meta->columns)
		{
			ft_printf("%d ", meta->map[i][j].z);
			if (meta->map[i][j].color != 0)
				ft_printf("%d ", meta->map[i][j].color);
			j++;
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
}
