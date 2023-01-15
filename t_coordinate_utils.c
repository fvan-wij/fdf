/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_coordinate_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: flip <flip@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 17:54:51 by flip          #+#    #+#                 */
/*   Updated: 2023/01/15 18:01:20 by flip          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

void	ft_insert_back(t_coordinate **lst, int coordinate)
{
	t_coordinate	*new;
	t_coordinate	*current;

	new = ft_calloc(1, sizeof(t_coordinate));
	new->x = coordinate;
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

t_coordinate	*array_to_list(char **arr, int n)
{
	int		i;
	t_coordinate	*head;

	head = NULL; // -> Not intilializing head of linked list causes segfaults on Linux!
	i = 0;
	while (i < n)
	{
		ft_insert_back(&head, ft_atoi(arr[i]));
		i++;
	}
	return (head);
}
