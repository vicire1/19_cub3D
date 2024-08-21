#include "../../../include/cub3d.h"

void	check_ea_data(t_data *data)
{
	int	i;
	int	start;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.ea_line][i]))
		i++;
	i += 2;
	while (is_white_space(data->all_file[data->pars.ea_line][i]))
		i++;
	start = i;
	len = get_len_of_word(data->all_file[data->pars.ea_line] + i);
	check_after_word(data, data->all_file[data->pars.ea_line] + len + i);
	data->path_E = ft_substr(data->all_file[data->pars.ea_line], i, len, data);
	fd_check = open(data->path_E, O_RDONLY);
	if (fd_check == -1)
	{
		free_all(data, NULL, 0);
		print_exit(ERR ERR_WALL_EA_DATA);
	}
	printf("EA path good => [%s]\n\n", data->path_E);
}

void	check_we_data(t_data *data)
{
	int	i;
	int	start;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.we_line][i]))
		i++;
	i += 2;
	while (is_white_space(data->all_file[data->pars.we_line][i]))
		i++;
	start = i;
	len = get_len_of_word(data->all_file[data->pars.we_line] + i);
	check_after_word(data, data->all_file[data->pars.we_line] + len + i);
	data->path_W = ft_substr(data->all_file[data->pars.we_line], i, len, data);
	fd_check = open(data->path_W, O_RDONLY);
	if (fd_check == -1)
	{
		free_all(data, NULL, 0);
		print_exit(ERR ERR_WALL_WE_DATA);
	}
	printf("WE path good => [%s]\n", data->path_W);
}

void	check_so_data(t_data *data)
{
	int	i;
	int	start;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.so_line][i]))
		i++;
	i += 2;
	while (is_white_space(data->all_file[data->pars.so_line][i]))
		i++;
	start = i;
	len = get_len_of_word(data->all_file[data->pars.so_line] + i);
	check_after_word(data, data->all_file[data->pars.so_line] + len + i);
	data->path_S = ft_substr(data->all_file[data->pars.so_line], i, len, data);
	fd_check = open(data->path_S, O_RDONLY);
	if (fd_check == -1)
	{
		free_all(data, NULL, 0);
		print_exit(ERR ERR_WALL_SO_DATA);
	}
	printf("SO path good => [%s]\n", data->path_S);
}

void	check_no_data(t_data *data)
{
	int	i;
	int	start;
	int	len;
	int	fd_check;

	i = 0;
	while (is_white_space(data->all_file[data->pars.no_line][i]))
		i++;
	i += 2;
	while (is_white_space(data->all_file[data->pars.no_line][i]))
		i++;
	start = i;
	len = get_len_of_word(data->all_file[data->pars.no_line] + i);
	check_after_word(data, data->all_file[data->pars.no_line] + len + i);
	data->path_N = ft_substr(data->all_file[data->pars.no_line], i, len, data);
	fd_check = open(data->path_N, O_RDONLY);
	if (fd_check == -1)
	{
		free_all(data, NULL, 0);
		print_exit(ERR ERR_WALL_NO_DATA);
	}
	printf("NO path good => [%s]\n", data->path_N);
}
