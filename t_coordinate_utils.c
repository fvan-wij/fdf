/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordinate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:51 by flip              #+#    #+#             */
/*   Updated: 2023/01/25 00:04:34 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"

t_coordinate	*link_new_to_old(t_coordinate **lst, t_coordinate *new, t_coordinate *old_point, int coordinate)
{
	if (*lst == NULL)
		*lst = new;
	new->z = coordinate;
	if (old_point != NULL)
		old_point->next = new;
	return (new);
}

void	print_tlist(t_coordinate *head)
{
	t_coordinate	*current;

	current = head;
	while (current)
	{
		ft_printf("Node->x:%d\n", current->z);
		current = current->next;
	}
}

t_coordinate	*array_to_list(char **arr, t_meta *meta, t_coordinate *old_point)
{
	int				i;
	int				n;
	t_coordinate	*point;
	
	n = 0;
	while (arr[n])
		n++;
	if (n > meta->columns)
		meta->columns = n;
	i = 0;
	while (i <= n)
	{
		point = ft_calloc(1, sizeof(t_coordinate *));
		if (i == n)
			old_point = link_new_to_old(meta->list, point, old_point, 0);
		else
			old_point = link_new_to_old(meta->list, point, old_point, ft_atoi(arr[i]));
		i++;
	}
	return (old_point);
}
