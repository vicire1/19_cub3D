#include "../../../include/cub3d.h"

int		check_color_c_data_p2(t_data *data, char *str)
{
	int	i;
	int	check_n;
	int	check_v;
	int	v1;
	int	v2;
	int	check_nb;

	i = 0;
	v1 = 0;
	v2 = 0;
	check_n = 0;
	check_v = 0;
	check_nb = 0;

	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			check_v = 0;
			check_n++;
		}
		if (check_n > 3)
			return (1);
		if (str[i] == ',')
		{
			if (str[i + 1] && ft_isdigit(str[i + 1]))
				check_nb++;
			if (!v1)
				v1 = i;
			else
				v2 = i;
			check_n = 0;
			check_v++;
		}
		if (check_v > 1)
			return (1);
		if (!ft_isdigit(str[i]) && str[i] != ',' && !is_white_space(str[i]) && str[i] != '\n')
			return (1);
		i++;
	}
	if (check_nb != 2)
		return (1);
	data->color_c[0] = atoi(str);
	data->color_c[1] = atoi(str+v1+1);
	data->color_c[2] = atoi(str+v2+1);
	if (data->color_c[0] < 0 || data->color_c[0] > 255 || data->color_c[1] < 0 || data->color_c[1] > 255 || data->color_c[2] < 0 || data->color_c[2] > 255)
		return (1);
	return (0);
}

void	check_color_c_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_file[data->pars.col_c_line][i] != '\n' && is_white_space(data->all_file[data->pars.col_c_line][i]))
		i++;
	i++;
	while (data->all_file[data->pars.col_c_line][i] != '\n' && is_white_space(data->all_file[data->pars.col_c_line][i]))
		i++;
	if (data->all_file[data->pars.col_c_line][i] == '\n' || !ft_isdigit(data->all_file[data->pars.col_c_line][i]))
	{
		free_all(data, NULL, 0);
		print_exit(ERR ERR_COL_C_DATA);
	}
	if (check_color_c_data_p2(data, data->all_file[data->pars.col_c_line] + i))
	{
		free_all(data, NULL, 0);
		print_exit(ERR ERR_COL_C_DATA);
	}
	return ;
}

void	convert_rgb_hex_cell(t_data *data)
{
	data->cell_color = (1 << 24 | data->color_c[0] << 16 | data->color_c[1] << 8 | data->color_c[2]);
	printf("CELL => %d \n", data->cell_color);
}