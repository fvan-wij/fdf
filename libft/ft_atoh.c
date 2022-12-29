/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fvan-wij <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:57:30 by fvan-wij      #+#    #+#                 */
/*   Updated: 2022/10/11 13:05:58 by fvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	convert_cap_hex(char *hex, unsigned int n)
{
	unsigned int	remainder;
	int				i;

	remainder = 0;
	i = 0;
	while (n != 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			hex[i] = 48 + remainder;
		else if (remainder >= 10)
			hex[i] = 55 + remainder;
		i++;
		n = n / 16;
	}
	return (i);
}


static int	convert_atoh(char *int_str, int i)
{
	int	atoi;

	atoi = 0;
	while (int_str[i] != '\0')
	{
		if (int_str[i] >= 'A' && int_str[i] <= 'F')
			atoi = atoi * 10 + (int_str[i] - 'A');
		else
			atoi = atoi * 10 + (int_str[i] - '0');
		i++;
	}
	return (atoi);
}

int	ft_atoh(const char *nptr)
{
	char	*int_str;
	int		atoi;
	int		i;

	int_str = (char *) nptr;
	atoi = 0;
	i = 2;
	atoi = convert_atoh(int_str, i);
	return (atoi);
}

int main(void)
{
    printf("FT_ATOI: %d\n", ft_atoh("0XFF0000"));
	// printf("ATOI: %d\n", atoi("2147483647"));
}