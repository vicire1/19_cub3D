/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:49:30 by lbirloue          #+#    #+#             */
/*   Updated: 2024/09/02 09:50:38 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_player_is_correct(t_data *data)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
				check++;
			if (check > 1)
				free_all(data, ERR ERR_PLAYER_CNTR, 1);
			j++;
		}
		i++;
	}
	if (check < 1)
		free_all(data, ERR ERR_PLAYER_LESS_CNTR, 1);
	return ;
}

void	recover_player_start_dir(t_data *data, char c)
{
	if (c == 'N')
	{
		data->rc->pl_dir[0] = -1;
		data->rc->plane[1] = FOV;
	}
	if (c == 'S')
	{
		data->rc->pl_dir[0] = 1;
		data->rc->plane[1] = -FOV;
	}
	if (c == 'W')
	{
		data->rc->pl_dir[1] = -1;
		data->rc->plane[0] = -FOV;
	}
	if (c == 'E')
	{
		data->rc->pl_dir[1] = 1;
		data->rc->plane[0] = FOV;
	}
}

void	recover_player_start_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
			{
				data->rc->pl_pos[0] = y + 0.5;
				data->rc->pl_pos[1] = x + 0.5;
				recover_player_start_dir(data, data->map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
