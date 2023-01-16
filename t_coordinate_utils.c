/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordinate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:51 by flip              #+#    #+#             */
/*   Updated: 2023/01/16 18:20:50 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/fdf.h"
// #include "../libft/libft.h"
#include "includes/fdf.h"
#include "libft/libft.h"

void	ft_insert_back(t_coordinate **lst, int coordinate, int nl_boolean)
{
	t_coordinate	*new;
	t_coordinate	*current;

	new = malloc(sizeof(t_coordinate));
	new->x = coordinate;
	new->nl_boolean = nl_boolean;
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

void	print_tlist(t_coordinate *head)
{
	t_coordinate	*current;

	current = head;
	while (current)
	{
		ft_printf("Node->x:%d\n", current->x);
		current = current->next;
	}
}

t_coordinate	*array_to_list(char **arr, int n, t_coordinate *head)
{
	int		i;

	i = 0;
	while (i <= n)
	{
		if (i == n) //-> No space after last coordinate followed by \n
			ft_insert_back(&head, ROW_END, 1);
		else
			ft_insert_back(&head, ft_atoi(arr[i]), 0);
		i++;
	}
	return (head);
}
