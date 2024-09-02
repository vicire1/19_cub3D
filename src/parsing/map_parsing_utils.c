/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:47:20 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 09:49:08 by lbirloue         ###   ########.fr       */
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

void	check_map_is_closed(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || data->map[y][x] == '1' || data->map[y][x] == 'O')
		return ;
	if (data->map[y][x] == ' ' || data->map[y][x] == '\n' || !data->map[y][x])
		free_all(data, ERR ERR_MAP_NOT_CLOSED, 1);
	data->map[y][x] = 'O';
	check_map_is_closed(data, x - 1, y);
	check_map_is_closed(data, x + 1, y);
	check_map_is_closed(data, x, y - 1);
	check_map_is_closed(data, x, y + 1);
}
