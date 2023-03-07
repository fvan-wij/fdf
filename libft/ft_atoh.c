/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flip <flip@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:48:18 by flip              #+#    #+#             */
/*   Updated: 2023/03/05 13:52:24 by flip             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int    convert_hex(char *hex_string)
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