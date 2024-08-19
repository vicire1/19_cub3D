#include "../../include/cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if ((str1[0] == 0 && str2[0] == 0) || n == 0)
		return (0);
	while (str1[i] == str2[i] && n > i && str1[i] && str2[i])
		i++;
	if (i == n || str1[i] == str2[i])
		return (0);
	if (str1[i] >= 0 && str2[i] >= 0 && str2[i] > str1[i])
		return (-1);
	else
		return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_white_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}
