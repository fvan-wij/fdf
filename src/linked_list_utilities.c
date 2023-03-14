/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:51 by flip              #+#    #+#             */
/*   Updated: 2023/03/14 17:49:59 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_lstcoordinate	*link_new_to_old(t_meta *meta,
	t_lstcoordinate *old_point, int coordinate, unsigned int color)
{
	t_lstcoordinate	*new;

	new = ft_calloc(2, sizeof(t_lstcoordinate *));
	if (!new)
		free_with_exit_code(2, meta);
	if (*meta->list == NULL)
		*meta->list = new;
	new->z = coordinate;
	if (color == 0)
		new->color = LINE_COLOR;
	else
		new->color = convert_rgba(color);
	if (old_point != NULL)
		old_point->next = new;
	return (new);
}

t_lstcoordinate	*add_map_points_to_list(int n, t_lstcoordinate *old_point,
	t_meta *meta, char **arr)
{
	int				i;
	char			*color;

	i = 0;
	while (i <= n)
	{
		color = ft_strchr(arr[i], ',');
		if (i == n)
			old_point = link_new_to_old(meta,
					old_point, 0, 0);
		else if (color)
			old_point = link_new_to_old(meta,
					old_point, ft_atoi(arr[i]), ft_atoh(color + 1));
		else
			old_point = link_new_to_old(meta,
					old_point, ft_atoi(arr[i]), 0);
		i++;
	}
	return (old_point);
}

t_lstcoordinate	*convert_array_to_list(char **arr, t_meta *meta,
	t_lstcoordinate *old_point)
{
	int				n;

	n = 0;
	while (arr[n])
		n++;
	if (n > meta->columns)
		meta->columns = n;
	old_point = add_map_points_to_list(n, old_point, meta, arr);
	return (old_point);
}
