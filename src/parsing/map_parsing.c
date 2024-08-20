#include "../../include/cub3d.h"

void	check_if_empty_line(t_data *data, int	i)
{
	int	j;
	while (data->all_file[i])
	{
		j = 0;
		while(data->all_file[i][j])
		{
			if (!is_white_space(data->all_file[i][j]) && data->all_file[i][j] != '\n')
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

int		check_if_map_line(char *str)
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

int		nb_line_map(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while(!check_if_map_line(data->all_file[i]))
		i++;
	while(check_if_map_line(data->all_file[i]))
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
		data->map[j] = ft_substr(data->all_file[i], 0, ft_strlen_before_n_line(data->all_file[i]), data);
		j++;
		i++;
	}
	data->map[j] = NULL;
	return ;
}

int	map_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '\n')
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
		while(data->map[x][y])
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
	while(data->map[x])
	{
		tmp_len = ft_strlen_before_n_line(data->map[x]);
		if (data->pars.longest_map_len < tmp_len)
			data->pars.longest_map_len = tmp_len;
		x++;
	}
	return ;
}

void	pars_map(t_data *data)
{
	recup_map(data);
	check_map_data(data);
	//fctn qui va delete le /n si il y en a un a la fin de la line
	recover_longest_map_line(data);
	//fctn qui va join (longest_len - len) d'espace à la line
	
	//fctn backtraking like so_long qui va replace les 0 sur les 4 dir autours du player et si c'est un space, tchaooo 
	//fctn verif qui va compter le nb de player 
	print_tab(data->map);
}
