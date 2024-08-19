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
		print_exit(ERR ERR_MALLOC);
	data->fd_map = open(map_name, O_RDONLY);
	if (data->fd_map == -1)
	{
		free(data->all_file);
		print_exit(ERR ERR_OPEN);
	}
	data->all_file[i] = get_next_line(data->fd_map);
	while (data->all_file[i])
	{
		i++;
		data->all_file[i] = get_next_line(data->fd_map);
	}
	close(data->fd_map);
	return ;
}

void	all_file_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_file[i])
	{
		free(data->all_file[i]);
		data->all_file[i] = NULL;
		i++;
	}
}

void	print_exit(char *msg)
{
	printf("%s", msg);
	exit(0);
}
