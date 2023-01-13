/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:39:45 by fvan-wij          #+#    #+#             */
/*   Updated: 2022/11/22 22:38:55 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strchr_index(const char *s, int c);
char	*ft_strjoin_and_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strcpy(char *dst, const char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif