#include "../../include/cub3d.h"

int	check_empty_line_data(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_white_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_map_line_data(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]))
		i++;
	if (str[i] != '0' && str[i] != '1' && str[i] != '\n')
		return (1);
	return (0);
}

int	check_in_line(t_data *data, char *str, int which)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]))
		i++;
	if (!ft_strncmp(str + i, PARS_C, ft_strlen(PARS_C)))
	{
		data->pars.col_c_status++;
		data->pars.col_c_line = which;
	}
	else if (!ft_strncmp(str + i, PARS_F, ft_strlen(PARS_F)))
	{
		data->pars.col_f_status++;
		data->pars.col_f_line = which;
	}
	else if (!ft_strncmp(str + i, PARS_NO, ft_strlen(PARS_NO)))
	{
		data->pars.no_status++;
		data->pars.no_line = which;
	}
	else if (!ft_strncmp(str + i, PARS_SO, ft_strlen(PARS_SO)))
	{
		data->pars.so_status++;
		data->pars.so_line = which;
	}
	else if (!ft_strncmp(str + i, PARS_WE, ft_strlen(PARS_WE)))
	{
		data->pars.we_status++;
		data->pars.we_line = which;
	}
	else if (!ft_strncmp(str + i, PARS_EA, ft_strlen(PARS_EA)))
	{
		data->pars.ea_status++;
		data->pars.ea_line = which;
	}
	else if (!check_empty_line_data(str))
		;
	else if (!check_map_line_data(str))
		;
	else
	{
		all_file_free(data);
		print_exit(ERR ERR_BAD_DATA);
	}
	return (0);
}

void	check_if_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_file[i])
	{
		check_in_line(data, data->all_file[i], i);
		i++;
	}
	return ;
}

void	check_if_missing_data(t_data *data)
{
	if (data->pars.col_c_status == 0 || data->pars.col_f_status == 0
		|| data->pars.no_status == 0 || data->pars.so_status == 0
		|| data->pars.we_status == 0 || data->pars.ea_status == 0)
	{
		all_file_free(data);
		print_exit(ERR ERR_MISSING_DATA);
	}
	return ;
}

void	check_if_to_much_data(t_data *data)
{
	if (data->pars.col_c_status > 1 || data->pars.col_f_status > 1
		|| data->pars.no_status > 1 || data->pars.so_status > 1
		|| data->pars.we_status > 1 || data->pars.ea_status > 1)
	{
		all_file_free(data);
		print_exit(ERR ERR_TO_MUCH_DATA);
	}
	return ;
}

void	init_pars_data(t_data *data)
{
	data->pars.col_c_status = 0;
	data->pars.col_f_status = 0;
	data->pars.no_status = 0;
	data->pars.so_status = 0;
	data->pars.we_status = 0;
	data->pars.ea_status = 0;
	data->rc = malloc(sizeof(t_rc));
	if (!data->rc)
		free_all(data, ERR ERR_MALLOC, 1);
	data->rc->pl_dir[0] = 0;
	data->rc->pl_dir[1] = 0;
	data->rc->plane[0] = 0;
	data->rc->plane[1] = 0;
	data->rc->move_b = 0;
	data->rc->move_f = 0;
	data->rc->move_l = 0;
	data->rc->move_r = 0;
	data->rc->rot_l = 0;
	data->rc->rot_r = 0;
	data->rc->time = 0;
	check_if_data(data);
	check_if_missing_data(data);
	check_if_to_much_data(data);
	check_color_c_data(data);
	check_color_f_data(data);
	check_no_data(data);
	check_so_data(data);
	check_we_data(data);
	check_ea_data(data);
}
