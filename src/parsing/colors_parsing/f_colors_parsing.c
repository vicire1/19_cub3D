/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_colors_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:03:37 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 09:03:40 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	convert_and_check_col_f(t_data *data, char *str)
{
	if (data->pars_col.check_nb != 2)
		return (1);
	data->color_f[0] = atoi(str);
	data->color_f[1] = atoi(str + data->pars_col.v1 + 1);
	data->color_f[2] = atoi(str + data->pars_col.v2 + 1);
	if (data->color_f[0] < 0 || data->color_f[0] > 255 || data->color_f[1] < 0
		|| data->color_f[1] > 255 || data->color_f[2] < 0
		|| data->color_f[2] > 255)
		return (1);
	return (0);
}

void	check_comma(t_data *data, char c, int i)
{
	if (c && ft_isdigit(c))
		data->pars_col.check_nb++;
	if (!data->pars_col.v1)
		data->pars_col.v1 = i;
	else
		data->pars_col.v2 = i;
	data->pars_col.check_n = 0;
	data->pars_col.check_v++;
}

int	check_color_f_data_p2(t_data *data, char *str, int i)
{
	i = init_pars_col(data);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			data->pars_col.check_v = 0;
			data->pars_col.check_n++;
		}
		if (data->pars_col.check_n > 3)
			return (1);
		if (str[i] == ',')
			check_comma(data, str[i + 1], i);
		if (data->pars_col.check_v > 1)
			return (1);
		if (!ft_isdigit(str[i]) && str[i] != ','
			&& !is_white_space(str[i]) && str[i] != '\n')
			return (1);
		i++;
	}
	return (convert_and_check_col_f(data, str));
}

void	check_color_f_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_file[data->pars.col_f_line][i] != '\n'
		&& is_white_space(data->all_file[data->pars.col_f_line][i]))
		i++;
	i++;
	while (data->all_file[data->pars.col_f_line][i] != '\n'
		&& is_white_space(data->all_file[data->pars.col_f_line][i]))
		i++;
	if (data->all_file[data->pars.col_f_line][i] == '\n'
		|| !ft_isdigit(data->all_file[data->pars.col_f_line][i]))
		free_all(data, ERR ERR_COL_F_DATA, 1);
	if (check_color_f_data_p2(data,
			data->all_file[data->pars.col_f_line] + i, 0))
		free_all(data, ERR ERR_COL_F_DATA, 1);
	return ;
}

void	convert_rgb_hex_floor(t_data *data)
{
	data->floor_color = (1 << 24 | data->color_f[0] << 16
			| data->color_f[1] << 8 | data->color_f[2]);
}
