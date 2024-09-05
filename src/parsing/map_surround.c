/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surround.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:28:34 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/05 08:51:19 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_first_and_last_line(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			free_all(data, ERR_MAP_NOT_CLOSE_BY_ONE, 1);
		i++;
	}
}

void	check_mid_line(t_data *data, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_before_n_line(str);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '1')
		i++;
	else
		free_all(data, ERR_MAP_NOT_CLOSE_BY_ONE, 1);
	len--;
	while (len != 0)
	{
		if (str[len] != ' ')
		{
			if (str[len] == '1')
				break ;
			else
				free_all(data, ERR_MAP_NOT_CLOSE_BY_ONE, 1);
		}
		len--;
	}
}

void	check_map_is_surround(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pars.map_h)
	{
		if (i == 0)
			check_first_and_last_line(data, data->map[i]);
		else
			check_mid_line(data, data->map[i]);
		i++;
	}
}
