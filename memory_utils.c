/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:59:41 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/25 00:19:29 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	free_split_points(char **split_points)
{
	int	i;

	i = 0;
	while (split_points[i])
	{
		free(split_points[i]);
		i++;
	}
	free(split_points);
}

void	free_2Dstructarray(t_meta *meta)
{
	int	i;

	i = 0;
	while (meta->map[i])
	{
		free(meta->map[i]);
		i++;
	}
	free(meta->map);
}

void	clean_memory_allocations(t_meta *meta)
{
	if (*meta->map)
	{	
		free_2Dstructarray(meta);
		ft_printf("**MAP CLEANED!\n");
	}
	ft_printf("MEMORY ALLOCATIONS CLEANED!\n");
	ft_printf("IT'S ALL OGRE NOW...\n");
}