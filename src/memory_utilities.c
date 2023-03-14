/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:59:41 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/14 18:11:05 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map_points(char **split_points)
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

void	free_2d_struct_array(t_meta *meta)
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

void	clear_list(t_lstcoordinate **list)
{
	t_lstcoordinate	*current;
	t_lstcoordinate	*previous;

	current = *list;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*list = NULL;
}

void	clean_memory_allocations(t_meta *meta)
{
	if (*meta->map)
		free_2d_struct_array(meta);
	if (meta->list)
	{
		clear_list(meta->list);
		free(meta->list);
	}
	if (meta->menu)
		free(meta->menu);
	free(meta);
}

void	free_with_exit_code(int error_code, t_meta *meta)
{
	if (error_code == 1)
		free_2d_struct_array(meta);
	else if (error_code == 2)
		clear_list(meta->list);
	free(meta);
	exit(error_code);
}
