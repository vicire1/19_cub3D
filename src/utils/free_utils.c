#include "../../include/cub3d.h"

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
	free(data->all_file);
	data->all_file = NULL;
}

void	free_all(t_data *data, char *msg, int exit_s)
{
	if (data->all_file)
		all_file_free(data);
	if (data->path_N)
		free(data->path_N);
	if (data->path_S)
		free(data->path_S);
	if (data->path_W)
		free(data->path_W);
	if (data->path_E)
		free(data->path_E);
	if (msg)
		printf("%s\n", msg);
	if (exit_s)
		exit(exit_s);
	return ;
}