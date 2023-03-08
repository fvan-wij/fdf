/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:25:50 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/08 20:34:15 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*strjoin;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	strjoin = malloc(len * sizeof(char));
	if (!strjoin)
		return (0);
	else
	{
		ft_strcpy(strjoin, s1);
		ft_strcpy(strjoin + ft_strlen(s1), s2);
		return (strjoin);
	}
}

// int	main(void)
// {
// 	//  char	s1[] = "Join me one more time, moterhefucker ";
// 	//  char	s2[] = "I double dare you";

// 	printf("%s", ft_strjoin("Join me one more time, ", "I double dare you"));
// }
