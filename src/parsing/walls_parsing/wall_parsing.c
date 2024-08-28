#include "../../../include/cub3d.h"

void	check_ea_data(t_data *data)
{
	int	i;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.ea_line][i]))
		i++;
	i+=2;
	while (is_white_space(data->all_file[data->pars.ea_line][i]))
		i++;
	len = get_len_of_word(data->all_file[data->pars.ea_line] + i);
	check_after_word(data, data->all_file[data->pars.ea_line] + len + i);
	data->path[EA] = ft_substr(data->all_file[data->pars.ea_line], i, len, data);
	fd_check = open(data->path[EA], O_RDONLY);
	if (fd_check == -1)
		free_all(data, ERR ERR_WALL_EA_DATA, 1);
}

void	check_we_data(t_data *data)
{
	int	i;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.we_line][i]))
		i++;
	i+=2;
	while (is_white_space(data->all_file[data->pars.we_line][i]))
		i++;
	len = get_len_of_word(data->all_file[data->pars.we_line] + i);
	check_after_word(data, data->all_file[data->pars.we_line] + len + i);
	data->path[WE] = ft_substr(data->all_file[data->pars.we_line], i, len, data);
	fd_check = open(data->path[WE], O_RDONLY);
	if (fd_check == -1)
		free_all(data, ERR ERR_WALL_WE_DATA, 1);
}

void	check_so_data(t_data *data)
{
	int	i;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.so_line][i]))
		i++;
	i+=2;
	while (is_white_space(data->all_file[data->pars.so_line][i]))
		i++;
	len = get_len_of_word(data->all_file[data->pars.so_line] + i);
	check_after_word(data, data->all_file[data->pars.so_line] + len + i);
	data->path[SO] = ft_substr(data->all_file[data->pars.so_line], i, len, data);
	fd_check = open(data->path[SO], O_RDONLY);
	if (fd_check == -1)
		free_all(data, ERR ERR_WALL_SO_DATA, 1);
}

void	check_no_data(t_data *data)
{
	int	i;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.no_line][i]))
		i++;
	i+=2;
	while (is_white_space(data->all_file[data->pars.no_line][i]))
		i++;
	len = get_len_of_word(data->all_file[data->pars.no_line] + i);
	check_after_word(data, data->all_file[data->pars.no_line] + len + i);
	data->path[NO] = ft_substr(data->all_file[data->pars.no_line], i, len, data);
	fd_check = open(data->path[NO], O_RDONLY);
	if (fd_check == -1)
		free_all(data, ERR ERR_WALL_NO_DATA, 1);
}
