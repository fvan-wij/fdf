/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <fvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 12:13:32 by fvan-wij      #+#    #+#                 */
/*   Updated: 2022/12/29 14:38:54 by fvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 900
# define HEIGHT 900

typedef struct Map
{
	int		z;
	char	*hex;
} Map;


#endif