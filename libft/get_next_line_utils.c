/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:21:38 by fvan-wij          #+#    #+#             */
/*   Updated: 2022/11/13 17:21:38 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)s + i);
// 	return (NULL);
// }

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(len + 1 * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (j < len && s[i] != '\0')
	{
		substr[j] = s[i + start];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	int		len;
	char	*strjoin;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	strjoin = malloc(len * sizeof(char));
	if (!strjoin)
		return (free(s1), NULL);
	ft_strcpy(strjoin, s1);
	ft_strcpy(strjoin + ft_strlen(s1), s2);
	free(s1);
	return (strjoin);
}
