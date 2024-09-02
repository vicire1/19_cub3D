/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lil_fctn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:42:28 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 09:42:30 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	col_c_in_line(t_data *data, int which)
{
	data->pars.col_c_status++;
	data->pars.col_c_line = which;
}

void	col_f_in_line(t_data *data, int which)
{
	data->pars.col_f_status++;
	data->pars.col_f_line = which;
}

void	no_in_line(t_data *data, int which)
{
	data->pars.no_status++;
	data->pars.no_line = which;
}

void	so_in_line(t_data *data, int which)
{
	data->pars.so_status++;
	data->pars.so_line = which;
}

void	we_in_line(t_data *data, int which)
{
	data->pars.we_status++;
	data->pars.we_line = which;
}
