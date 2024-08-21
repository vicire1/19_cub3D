#include "../../include/cub3d.h"

void	check_if_empty_line(t_data *data, int i)
{
	int	j;

	while (data->all_file[i])
	{
		j = 0;
		while (data->all_file[i][j])
		{
			if (!is_white_space(data->all_file[i][j])
			&& data->all_file[i][j] != '\n')
			{
				printf("ICI\n");
				free_all(data, NULL, 0);
				print_exit(ERR ERR_DATA_AFTER_MAP);
			}
			j++;
		}
		i++;
	}
}

int	check_if_map_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		if (str[i] == '1' || str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	nb_line_map(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (!check_if_map_line(data->all_file[i]))
		i++;
	while (check_if_map_line(data->all_file[i]))
	{
		ret++;
		i++;
	}
	check_if_empty_line(data, i);
	return (ret);
}

void	recup_map(t_data *data)
{
	int	i;
	int	j;
	int	nb_line;

	i = 0;
	j = 0;
	nb_line = nb_line_map(data);
	data->map = malloc(sizeof(char *) * (nb_line + 1));
	if (!data->map)
		free_all(data, ERR ERR_MALLOC, 1);
	while (!check_if_map_line(data->all_file[i]))
		i++;
	nb_line += i;
	while (i < nb_line)
	{
		data->map[j] = ft_substr(data->all_file[i], 0,
				ft_strlen_before_n_line(data->all_file[i]), data);
		j++;
		i++;
	}
	data->map[j] = NULL;
	return ;
}

int	map_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E' && c != '\n')
		return (0);
	return (1);
}

void	check_map_data(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (!map_char(data->map[x][y]))
				free_all(data, ERR ERR_MAP_DATA, 1);
			y++;
		}
		x++;
	}
	return ;
}

void	recover_longest_map_line(t_data *data)
{
	int	tmp_len;
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->pars.longest_map_len = 0;
	while (data->map[x])
	{
		tmp_len = ft_strlen_before_n_line(data->map[x]);
		if (data->pars.longest_map_len < tmp_len)
			data->pars.longest_map_len = tmp_len;
		x++;
	}
	return ;
}

void	fill_space_map(t_data *data)
{
	int		len_line;
	int		i;
	int		tab_size;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tab_size = recover_tab_size(data->map);
	while (i < tab_size)
	{
		tmp = ft_strdup(data->map[i], data);
		len_line = ft_strlen_before_n_line(data->map[i]);
		free(data->map[i]);
		tmp2 = mall_space_line(data->pars.longest_map_len - len_line, data);
		if (tmp2)
			data->map[i] = ft_strjoin(tmp, tmp2, data);
		else
			data->map[i] = ft_strdup(tmp, data);
		free(tmp2);
		tmp2 = NULL;
		free(tmp);
		tmp = NULL;
		i++;
	}
	return ;
}

void	check_player_is_correct(t_data *data)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
				check++;
			if (check > 1)
				free_all(data, ERR ERR_PLAYER_CNTR, 1);
			j++;
		}
		i++;
	}
	if (check < 1)
		free_all(data, ERR ERR_PLAYER_LESS_CNTR, 1);
	return ;
}

void	recover_player_start_dir(t_data *data, char c)
{
	if (c == 'N')
		data->pl_direction = 0;
	if (c == 'S')
		data->pl_direction = 1;
	if (c == 'W')
		data->pl_direction = 2;
	if (c == 'E')
		data->pl_direction = 3;
}

void	recover_player_start_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->pl_position[0] = i;
				data->pl_position[1] = j;
				recover_player_start_dir(data, data->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	check_map_is_closed(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || !data->map[x][y]
	|| data->map[x][y] == '1' || data->map[x][y] == '2')
		return ;
	if (data->map[x][y] == ' ')
	{
		free_all(data, ERR ERR_MAP_NOT_CLOSED, 1);
	}
	data->map[x][y] = '2';
	check_map_is_closed(data, x - 1, y);
	check_map_is_closed(data, x + 1, y);
	check_map_is_closed(data, x, y - 1);
	check_map_is_closed(data, x, y + 1);
}

void	reset_player_pos(t_data *data, int i)
{
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i == (int)data->pl_position[0]
				&& j == (int)data->pl_position[1])
			{
				if (data->pl_direction == 0)
					data->map[i][j] = 'N';
				else if (data->pl_direction == 1)
					data->map[i][j] = 'S';
				else if (data->pl_direction == 2)
					data->map[i][j] = 'W';
				else if (data->pl_direction == 3)
					data->map[i][j] = 'E';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	pars_map(t_data *data)
{
	recup_map(data);
	check_map_data(data);
	recover_longest_map_line(data);
	fill_space_map(data);
	check_player_is_correct(data);
	recover_player_start_pos(data);
	printf("PLAYER POSITION %f %f\n", data->pl_position[0], data->pl_position[1]);
	check_map_is_closed(data, (int)data->pl_position[0], (int)data->pl_position[1]);
	reset_player_pos(data, 0);
	print_tab(data->map);
}
