/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordinate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:51 by flip              #+#    #+#             */
/*   Updated: 2023/01/23 16:09:25 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/fdf.h"
// #include "../libft/libft.h"
#include "includes/fdf.h"
#include "libft/libft.h"

void	ft_insert_back(t_coordinate **lst, int coordinate, int row_end)
{
	t_coordinate	*new;
	t_coordinate	*current;

	new = malloc(sizeof(t_coordinate));
	new->z = coordinate;
	new->end_of_row = row_end;
	// ft_printf("Node->x:%d	Node->nl_boolean:%d\n", new->x, new->nl_boolean);
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

// void	print_tlist(t_coordinate *head)
// {
// 	t_coordinate	*current;

// 	current = head;
// 	while (current)
// 	{
// 		ft_printf("Node->x:%d\n", current->z);
// 		current = current->next;
// 	}
// }

t_coordinate	*array_to_list(char **arr, int n, t_coordinate *head)
{
	int		i;

	i = 0;
	while (i <= n)
	{
		if (i == n)
			ft_insert_back(&head, 0, 1); // Toggle end_of_row to true
		else
			ft_insert_back(&head, ft_atoi(arr[i]), 0); // Toggle end_of_row to false
		i++;
	}
	return (head);
}
