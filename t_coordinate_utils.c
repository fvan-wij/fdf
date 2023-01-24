/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_coordinate_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 17:54:51 by flip          #+#    #+#                 */
/*   Updated: 2023/01/24 17:10:10 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/fdf.h"
// #include "../libft/libft.h"
#include "includes/fdf.h"
#include "libft/libft.h"

// void	ft_insert_back(t_coordinate **lst, int coordinate, int row_end)
// {
// 	t_coordinate	*new;
// 	t_coordinate	*current;

// 	new = malloc(sizeof(t_coordinate));
// 	new->z = coordinate;
// 	new->end_of_row = row_end;
// 	// ft_printf("Node->x:%d	Node->nl_boolean:%d\n", new->x, new->nl_boolean);
// 	new->next = NULL;
// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		current = *lst;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = new;
// 	}
// }

t_coordinate	*link_new_to_old(t_coordinate **lst, t_coordinate *new, t_coordinate *old_point, int coordinate, int row_end)
{
	if (*lst == NULL)
		*lst = new;
	new->z = coordinate;
	new->end_of_row = row_end; //-> could be redundant due to meta->columns and meta->rows.
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
		ft_printf("Node->end_of_row:%d\n", current->end_of_row);
		current = current->next;
	}
}

t_coordinate	*array_to_list(char **arr, int n, t_meta *meta, t_coordinate *old_point)
{
	int				i;
	t_coordinate	*point;
	
	i = 0;
	while (i <= n)
	{
		point = ft_calloc(1, sizeof(t_coordinate *));
		if (i == n)
			old_point = link_new_to_old(meta->list, point, old_point, 0, 1);
		// ft_insert_back(&head, 0, 1); // Toggle end_of_row to true
		else
			old_point = link_new_to_old(meta->list, point, old_point, ft_atoi(arr[i]), 0);
		// ft_insert_back(&head, ft_atoi(arr[i]), 0); // Toggle end_of_row to false
		i++;
	}
	// print_tlist(meta->list);
	return (old_point);
}
