/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:27:22 by flip              #+#    #+#             */
/*   Updated: 2023/02/13 14:49:27 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

// 0 - 10 are digits
// >10 - 16 are A, B, C, D, E, F
// Example of a hex string = ,0xFF0000

unsigned int    convert_hex(char *hex_string)
{
	unsigned int	hex;
    int             i;

	hex = 0;
    i = 1;
	while (hex_string[i] != '\0')
	{
        if ((hex_string[i] >= 48 && hex_string[i] <= 56)) // 48 == 0, 56 == 9
            hex = hex * 16 + (hex_string[i] - '0');
        else if ((hex_string[i] >= 65 && hex_string[i] <= 70)) // 65 == A, 70 == F
            hex = hex * 16 + (hex_string[i] - 55);
        i++;
	}
    // ft_printf("Hex is %X\n", hex);
	return (hex);
}

unsigned int    ft_atoh(char *hex_string)
{
    unsigned int hex;

    hex = convert_hex(hex_string);
	return (hex);
}
