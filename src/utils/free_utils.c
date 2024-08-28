#include "../../include/cub3d.h"

void	free_str_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
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

void	free_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->txtr[i].img)
			mlx_destroy_image(data->ptr, data->txtr[i].img);
	}
	if (data->img && data->img->img)
		mlx_destroy_image(data->ptr, data->img->img);
	free(data->img);
}

void	free_all(t_data *data, char *msg, int exit_s)
{
	free_str_tab(data->all_file);
	free_str_tab(data->map);
	free_tex_path(data);
	free_img(data);
	free(data->rc);
	if (data->win)
		mlx_destroy_window(data->ptr, data->win);
	if (data->ptr)
		free(data->ptr);
	if (msg)
		ft_printf_fd(2, "%s\n", msg);
	exit(exit_s);
	return ;
}