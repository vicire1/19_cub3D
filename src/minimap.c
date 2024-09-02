/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:52:46 by vdecleir          #+#    #+#             */
/*   Updated: 2024/09/02 14:10:52 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_frame(t_data *data)
{
	int	x;
	int	y;

	y = SCREEN_H / 45 - 3;
	while (y < MAP_SIZE + SCREEN_H / 45 + 3)
	{
		x = SCREEN_W - (SCREEN_H / 45) - MAP_SIZE - 3;
		while (x < SCREEN_W - (SCREEN_H / 45) + 3)
		{
			my_mlx_pixel_put(data->img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int		x;
	int		y;
	double	dist_x;
	double	dist_y;

	y = SCREEN_H / 45;
	dist_y = data->rc->pl_pos[0] - 4.5;
	while (y < MAP_SIZE + SCREEN_H / 45)
	{
		x = SCREEN_W - (SCREEN_H / 45) - MAP_SIZE;
		dist_x = data->rc->pl_pos[1] - 4.5;
		while (x < SCREEN_W - (SCREEN_H / 45))
		{
			if (is_in_map(data, dist_x, dist_y) && is_wall(data,
					(int)dist_x, (int)dist_y))
				my_mlx_pixel_put(data->img, x, y, 0x00404040);
			else
				my_mlx_pixel_put(data->img, x, y, 0x00C0C0C0);
			x++;
			dist_x += 0.05;
		}
		y++;
		dist_y += 0.05;
	}
}

void	put_player(t_data *data)
{
	int	x;
	int	y;

	y = (SCREEN_H / 45) + (MAP_SIZE / 2) - 3;
	while (y < (SCREEN_H / 45) + (MAP_SIZE / 2) + 3)
	{
		x = SCREEN_W - (MAP_SIZE / 2) - (SCREEN_H / 45) - 3;
		while (x < SCREEN_W - (MAP_SIZE / 2) - (SCREEN_H / 45) + 3)
		{
			my_mlx_pixel_put(data->img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	put_minimap(t_data *data)
{
	draw_frame(data);
	draw_minimap(data);
	put_player(data);
}
