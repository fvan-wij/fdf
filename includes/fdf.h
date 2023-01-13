/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:13:32 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/01/13 21:25:13 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <memory.h>
# include <unistd.h>
# include "glfw3.h"
// # include <MLX42/MLX42.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 900
# define HEIGHT 900

typedef struct Map
{
	int		z;
	char	*hex;

}	Map;

typedef struct s_coordinate
{
	int				x;
	struct s_list	*next;
}	t_coordinate;

void	ft_insert_back(t_coordinate **lst, int coordinate);
void	print_tlist(t_coordinate *head);
t_coordinate	*array_to_list(char **arr, int n);

#endif