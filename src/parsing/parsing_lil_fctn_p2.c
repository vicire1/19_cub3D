/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lil_fctn_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:42:34 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 09:50:52 by lbirloue         ###   ########.fr       */
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
	if (c != ' ' && c != '1' && c != '0' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E' && c != '\n')
		return (0);
	return (1);
}
