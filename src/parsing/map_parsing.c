/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:07:22 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 14:28:58 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	recup_map(t_data *data)
{
	int	i;
	int	j;
	int	nb_line;

	i = 0;
	j = 0;
	nb_line = nb_line_map(data);
	if (nb_line == 0)
		free_all(data, ERR ERR_MAP_DATA, 1);
	data->map = malloc(sizeof(char *) * (nb_line + 1));
	if (!data->map)
		free_all(data, ERR ERR_MALLOC, 1);
	while (!check_if_data_line(data->all_file[i]))
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
	data->pars.map_h = x;
	return ;
}

void	recover_longest_map_line(t_data *data)
{
	int	tmp_len;
	int	x;

	x = 0;
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

void	pars_map(t_data *data)
{
	recup_map(data);
	check_map_data(data);
	recover_longest_map_line(data);
	fill_space_map(data);
	check_player_is_correct(data);
	recover_player_start_pos(data);
	check_map_is_closed(data, (int)data->rc->pl_pos[1],
		(int)data->rc->pl_pos[0]);
}
