/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordinate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:51 by flip              #+#    #+#             */
/*   Updated: 2023/03/05 13:43:53 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"

t_lstcoordinate	*link_new_to_old(t_lstcoordinate **lst, t_lstcoordinate *new, t_lstcoordinate *old_point, int coordinate, unsigned int color)
{
	if (*lst == NULL)
		*lst = new;
	new->z = coordinate;
	if (color == 0)
		new->color = convert_rgb(0xFFFFFFFF);
	else
		new->color = convert_rgb(color);
	if (old_point != NULL)
		old_point->next = new;
	return (new);
}

void	print_tlist(t_lstcoordinate *head)
{
	t_lstcoordinate	*current;

	current = head;
	while (current)
	{
		ft_printf("Node->x:%d\n", current->z);
		current = current->next;
	}
}

t_lstcoordinate	*array_to_list(char **arr, t_meta *meta, t_lstcoordinate *old_point)
{
	int				i;
	int				n;
	t_lstcoordinate	*point;
	char			*color;
	
	n = 0;
	while (arr[n])
		n++;
	if (n > meta->columns)
		meta->columns = n;
	i = 0;
	while (i <= n)
	{
		point = ft_calloc(2, sizeof(t_lstcoordinate *));
		if (!point)
			free_with_exit_code(2, meta);
		if (i == n)
			old_point = link_new_to_old(meta->list, point, old_point, 0, 0);
		else if ((color = ft_strchr(arr[i], ',')))
			old_point = link_new_to_old(meta->list, point, old_point, ft_atoi(arr[i]), ft_atoh(color));
		else
			old_point = link_new_to_old(meta->list, point, old_point, ft_atoi(arr[i]), 0);	
		i++;
	}
	return (old_point);
}
