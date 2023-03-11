/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:48:18 by flip              #+#    #+#             */
/*   Updated: 2023/03/11 16:49:16 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int    convert_hex(char *hex_string)
{
	unsigned int	hex;
    int             i;

	hex = 0;
    i = 0;
	while (hex_string[i] != '\0')
	{
        if ((hex_string[i] >= 48 && hex_string[i] <= 56)) // 48 == 0, 56 == 9
            hex = hex * 16 + (hex_string[i] - '0');
        else if ((hex_string[i] >= 'A' && hex_string[i] <= 'F')) // 65 == A, 70 == F
            hex = hex * 16 + (10 + hex_string[i] - 'A');
        else if ((hex_string[i] >= 'a' && hex_string[i] <= 'f')) // 65 == A, 70 == F
            hex = hex * 16 + (10 + hex_string[i] - 'a');
        i++;
	}
	return (hex);
}

unsigned int    ft_atoh(char *hex_string)
{
    unsigned int hex;

    hex = convert_hex(hex_string);
	return (hex);
}
