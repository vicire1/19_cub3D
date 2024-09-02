/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:09:04 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 09:45:57 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_empty_line_data(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_white_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_map_line_data(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]))
		i++;
	if (str[i] != '0' && str[i] != '1' && str[i] != '\n')
		return (1);
	return (0);
}

int	check_in_line(t_data *data, char *str, int which)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]))
		i++;
	if (!ft_strncmp(str + i, PARS_C, ft_strlen(PARS_C)))
		col_c_in_line(data, which);
	else if (!ft_strncmp(str + i, PARS_F, ft_strlen(PARS_F)))
		col_f_in_line(data, which);
	else if (!ft_strncmp(str + i, PARS_NO, ft_strlen(PARS_NO)))
		no_in_line(data, which);
	else if (!ft_strncmp(str + i, PARS_SO, ft_strlen(PARS_SO)))
		so_in_line(data, which);
	else if (!ft_strncmp(str + i, PARS_WE, ft_strlen(PARS_WE)))
		we_in_line(data, which);
	else if (!ft_strncmp(str + i, PARS_EA, ft_strlen(PARS_EA)))
		ea_in_line(data, which);
	else if (!check_empty_line_data(str))
		;
	else if (!check_map_line_data(str))
		;
	else
		free_all(data, ERR ERR_BAD_DATA, 1);
	return (0);
}

void	check_if_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_file[i])
	{
		check_in_line(data, data->all_file[i], i);
		i++;
	}
	return ;
}

void	init_pars_data(t_data *data)
{
	data->pars.col_c_status = 0;
	data->pars.col_f_status = 0;
	data->pars.no_status = 0;
	data->pars.so_status = 0;
	data->pars.we_status = 0;
	data->pars.ea_status = 0;
	check_if_data(data);
	check_if_missing_data(data);
	check_if_to_much_data(data);
	check_color_c_data(data);
	check_color_f_data(data);
	check_no_data(data);
	check_so_data(data);
	check_we_data(data);
	check_ea_data(data);
}
