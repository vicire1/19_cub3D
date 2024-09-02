/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:52:00 by vdecleir          #+#    #+#             */
/*   Updated: 2024/09/02 11:01:57 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_in_map(t_data *data, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x > data->pars.longest_map_len - 1 || y > data->pars.map_h - 1)
		return (0);
	else
		return (1);
}

int	is_wall(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (1);
	else
		return (0);
}

void	mouse_rot(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_show();
	if (data->rc->mouse == 0)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(data->win, &x, &y);
		if (x != (SCREEN_W / 2))
			rotate(data, data->rc->frame_time * (x - SCREEN_W / 2) / 3);
		mlx_mouse_move(data->win, SCREEN_W / 2, SCREEN_H / 2);
	}
}

void	gun_shoot(t_data *data)
{
	if (data->rc->shoot == 1)
	{
		if (data->counter > 6)
			data->counter = 0;
		if (data->counter < 3)
			mlx_put_image_to_window(data->ptr, data->win, data->shoot_img, 590,
				370);
		data->counter++;
	}
	mlx_put_image_to_window(data->ptr, data->win, data->gun, 0, 0);
}
