/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:47:20 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/09 14:17:52 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				free_all(data, ERR ERR_DATA_AFTER_MAP, 1);
			j++;
		}
		i++;
	}
}

int	check_if_data_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0')
			break ;
		if (str[i] == '1' || str[i] == '0')
			return (1);
		i++;
	}
	return (0);
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
	while (data->all_file[i] &&!check_if_data_line(data->all_file[i]))
		i++;
	while (check_if_map_line(data->all_file[i]))
	{
		ret++;
		i++;
	}
	check_if_empty_line(data, i);
	return (ret);
}

void	check_map_surrounded(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if ((i == 0 || i == data->pars.map_h - 1) && (data->map[i][j] != '1'
				&& data->map[i][j] != ' '))
				free_all(data, ERR ERR_MAP_NOT_SURR, 1);
			if ((j == 0 || j == data->pars.longest_map_len - 1)
				&& (data->map[i][j] != '1' && data->map[i][j] != ' '))
				free_all(data, ERR ERR_MAP_NOT_SURR, 1);
			if (data->map[i][j] == ' ')
				check_near_space(data, i, j);
		}
	}
}
