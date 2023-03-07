/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:08:39 by flip              #+#    #+#             */
/*   Updated: 2023/03/05 13:51:05 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

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
