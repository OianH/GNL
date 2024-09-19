/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:17:32 by oiahidal          #+#    #+#             */
/*   Updated: 2024/07/04 01:17:32 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		search_for(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	update_buffer(char *s1);
char	*ft_strdup(const char *s1);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	gnl_strlen(const char *s);

#endif