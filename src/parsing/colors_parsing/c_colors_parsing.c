#include "../../../include/cub3d.h"

int	check_color_c_data_p2(t_data *data, char *str)
{
	int	i;

	i = 0;
	data->pars.v1 = 0;
	data->pars.v2 = 0;
	data->pars.check_n = 0;
	data->pars.check_v = 0;
	data->pars.check_nb = 0;

	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			data->pars.check_v = 0;
			data->pars.check_n++;
		}
		if (data->pars.check_n > 3)
			return (1);
		if (str[i] == ',')
		{
			if (str[i + 1] && ft_isdigit(str[i + 1]))
				data->pars.check_nb++;
			if (!data->pars.v1)
				data->pars.v1 = i;
			else
				data->pars.v2 = i;
			data->pars.check_n = 0;
			data->pars.check_v++;
		}
		if (data->pars.check_v > 1)
			return (1);
		if (!ft_isdigit(str[i]) && str[i] != ',' && !is_white_space(str[i]) && str[i] != '\n')
			return (1);
		i++;
	}
	if (data->pars.check_nb != 2)
		return (1);
	data->color_c[0] = atoi(str);
	data->color_c[1] = atoi(str + data->pars.v1 + 1);
	data->color_c[2] = atoi(str + data->pars.v2 + 1);
	if (data->color_c[0] < 0 || data->color_c[0] > 255 || data->color_c[1] < 0 || data->color_c[1] > 255 || data->color_c[2] < 0 || data->color_c[2] > 255)
		return (1);
	return (0);
}

void	check_color_c_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_file[data->pars.col_c_line][i] != '\n'
		&& is_white_space(data->all_file[data->pars.col_c_line][i]))
		i++;
	i++;
	while (data->all_file[data->pars.col_c_line][i] != '\n'
		&& is_white_space(data->all_file[data->pars.col_c_line][i]))
		i++;
	if (data->all_file[data->pars.col_c_line][i] == '\n'
		|| !ft_isdigit(data->all_file[data->pars.col_c_line][i]))
	{
		all_file_free(data);
		print_exit(ERR ERR_COL_C_DATA);
	}
	if (check_color_c_data_p2(data, data->all_file[data->pars.col_c_line] + i))
	{
		all_file_free(data);
		print_exit(ERR ERR_COL_C_DATA);
	}
	return ;
}
