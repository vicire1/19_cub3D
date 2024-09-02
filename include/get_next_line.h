/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:59:23 by vdecleir          #+#    #+#             */
/*   Updated: 2024/08/19 13:16:01 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*gnl_ft_strjoin(char *s1, char *s2, int i, int j);
unsigned int	gnl_ft_strlen(const char *s);
char			*gnl_ft_strchr(const char *s, int c);
char			*gnl_ft_substr(char *s, unsigned int start);
void			*gnl_ft_calloc(size_t nmemb, size_t size);

#endif