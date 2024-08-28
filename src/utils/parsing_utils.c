#include "../../include/cub3d.h"

int	file_size(t_data *data)
{
	char	*line;
	int		ret;

	ret = 0;
	line = get_next_line(data->fd_map);
	while (line)
	{
		free(line);
		line = NULL;
		ret++;
		line = get_next_line(data->fd_map);
	}
	close(data->fd_map);
	return (ret);
}

void	copy_all_file(t_data *data, char *map_name)
{
	int	i;

	i = 0;
	data->all_file = malloc(sizeof(char *) * (file_size(data) + 1));
	if (!data->all_file)
		free_all(data, ERR ERR_MALLOC, 1);
	data->fd_map = open(map_name, O_RDONLY);
	if (data->fd_map == -1)
		free_all(data, ERR ERR_OPEN, 1);
	data->all_file[i] = get_next_line(data->fd_map);
	while (data->all_file[i])
	{
		i++;
		data->all_file[i] = get_next_line(data->fd_map);
	}
	data->all_file[i] = NULL;
	close(data->fd_map);
	return ;
}

int	ft_strlen_before_n_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	recover_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*mall_space_line(int len, t_data *data)
{
	char	*ret;
	int		i;

	i = 0;
	if (len <= 0)
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		free_all(data, ERR_MALLOC, 1);
	while (i < len)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
