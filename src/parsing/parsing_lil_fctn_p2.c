/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lil_fctn_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:42:34 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/09 14:12:07 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ea_in_line(t_data *data, int which)
{
	data->pars.ea_status++;
	data->pars.ea_line = which;
}

void	check_if_missing_data(t_data *data)
{
	if (data->pars.col_c_status == 0 || data->pars.col_f_status == 0
		|| data->pars.no_status == 0 || data->pars.so_status == 0
		|| data->pars.we_status == 0 || data->pars.ea_status == 0)
		free_all(data, ERR ERR_MISSING_DATA, 1);
	return ;
}

void	check_if_to_much_data(t_data *data)
{
	if (data->pars.col_c_status > 1 || data->pars.col_f_status > 1
		|| data->pars.no_status > 1 || data->pars.so_status > 1
		|| data->pars.we_status > 1 || data->pars.ea_status > 1)
		free_all(data, ERR ERR_TO_MUCH_DATA, 1);
	return ;
}

int	map_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E' && c != '\n')
		return (0);
	return (1);
}

void	check_near_space(t_data *data, int i, int j)
{
	if (j - 1 >= 0 && (data->map[i][j - 1] != '1' && data->map[i][j
		- 1] != ' '))
		free_all(data, ERR ERR_MAP_NOT_SURR, 1);
	if (j + 1 < data->pars.longest_map_len && (data->map[i][j + 1] != '1'
		&& data->map[i][j + 1] != ' '))
		free_all(data, ERR ERR_MAP_NOT_SURR, 1);
	if (i - 1 >= 0 && (data->map[i - 1][j] != '1' && data->map[i
			- 1][j] != ' '))
		free_all(data, ERR ERR_MAP_NOT_SURR, 1);
	if (i + 1 < data->pars.map_h && (data->map[i + 1][j] != '1' && data->map[i
			+ 1][j] != ' '))
		free_all(data, ERR ERR_MAP_NOT_SURR, 1);
}
