/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:01:17 by vdecleir          #+#    #+#             */
/*   Updated: 2024/08/19 13:16:53 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

unsigned int	gnl_ft_strlen(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1));
	if (!join)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join [i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (join);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&str[i]);
	return (0);
}

char	*gnl_ft_substr(char *s, unsigned int start)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	if (!s)
		return (0);
	while (start + i < gnl_ft_strlen(s))
		i++;
	sub = malloc(sizeof(char) * (i + 1));
	if (!sub)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	i = 0;
	while (start + i < gnl_ft_strlen(s))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	free(s);
	s = NULL;
	return (sub);
}

void	*gnl_ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	bytes;

	bytes = nmemb * size;
	array = malloc(bytes);
	if (array == NULL)
		return (NULL);
	while (bytes)
	{
		array[bytes - 1] = '\0';
		bytes--;
	}
	return (array);
}
