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

void	free_tex_path(t_data *data)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (data->path[i])
		{
			free(data->path[i]);
			data->path[i] = NULL;
		}
	}
}

void	free_tex_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(data->ptr, data->txtr[i].img);
	mlx_destroy_image(data->ptr, data->img->img);
	free(data->img);
}

void	free_all(t_data *data, char *msg, int exit_s)
{
	if (data->all_file)
		all_file_free(data);
	free_tex_path(data);
	free_tex_img(data);
	free(data->rc);
	if (msg)
		printf("%s\n", msg);
	if (exit_s)
		exit(exit_s);
	return ;
}