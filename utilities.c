/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/05 13:08:39 by flip          #+#    #+#                 */
/*   Updated: 2023/03/11 10:39:46 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

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
	int i;
	int	j;

	i = 0;
	j = 0;
	while(i < meta->rows)
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
