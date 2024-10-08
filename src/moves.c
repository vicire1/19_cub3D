/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:51 by vdecleir          #+#    #+#             */
/*   Updated: 2024/09/09 14:04:01 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	actualise_pos(t_data *data, double new_pos_x, double new_pos_y)
{
	double	pos_coll_x;
	double	pos_coll_y;

	if (new_pos_x > data->rc->pl_pos[1])
		pos_coll_x = new_pos_x + 0.125;
	else
		pos_coll_x = new_pos_x - 0.125;
	if (new_pos_y > data->rc->pl_pos[0])
		pos_coll_y = new_pos_y + 0.125;
	else
		pos_coll_y = new_pos_y - 0.125;
	if (data->map[(int)pos_coll_y][(int)data->rc->pl_pos[1]] == '0')
		data->rc->pl_pos[0] = new_pos_y;
	if (data->map[(int)data->rc->pl_pos[0]][(int)pos_coll_x] == '0')
		data->rc->pl_pos[1] = new_pos_x;
}

void	go_fwd_back(t_data *data, int dir)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->rc->pl_pos[1];
	new_pos_y = data->rc->pl_pos[0];
	if (dir == W)
	{
		new_pos_x = data->rc->pl_pos[1] + (data->rc->pl_dir[1]
				* data->rc->frame_time * 5);
		new_pos_y = data->rc->pl_pos[0] + (data->rc->pl_dir[0]
				* data->rc->frame_time * 5);
	}
	if (dir == S)
	{
		new_pos_x = data->rc->pl_pos[1] - (data->rc->pl_dir[1]
				* data->rc->frame_time * 5);
		new_pos_y = data->rc->pl_pos[0] - (data->rc->pl_dir[0]
				* data->rc->frame_time * 5);
	}
	actualise_pos(data, new_pos_x, new_pos_y);
}

void	go_left_right(t_data *data, int dir)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->rc->pl_pos[1];
	new_pos_y = data->rc->pl_pos[0];
	if (dir == A)
	{
		new_pos_x = data->rc->pl_pos[1] + (data->rc->pl_dir[0]
				* data->rc->frame_time * 2);
		new_pos_y = data->rc->pl_pos[0] - (data->rc->pl_dir[1]
				* data->rc->frame_time * 2);
	}
	if (dir == D)
	{
		new_pos_x = data->rc->pl_pos[1] - (data->rc->pl_dir[0]
				* data->rc->frame_time * 2);
		new_pos_y = data->rc->pl_pos[0] + (data->rc->pl_dir[1]
				* data->rc->frame_time * 2);
	}
	actualise_pos(data, new_pos_x, new_pos_y);
}

void	rotate(t_data *data, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->rc->pl_dir[1];
	data->rc->pl_dir[1] = data->rc->pl_dir[1] * cos(speed) - data->rc->pl_dir[0]
		* sin(speed);
	data->rc->pl_dir[0] = old_dir_x * sin(speed) + data->rc->pl_dir[0]
		* cos(speed);
	old_plane_x = data->rc->plane[1];
	data->rc->plane[1] = data->rc->plane[1] * cos(speed) - data->rc->plane[0]
		* sin(speed);
	data->rc->plane[0] = old_plane_x * sin(speed) + data->rc->plane[0]
		* cos(speed);
}

int	move(t_data *data)
{
	struct timeval	time;

	data->rc->oldtime = data->rc->time;
	gettimeofday(&time, NULL);
	data->rc->time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	data->rc->frame_time = (data->rc->time - data->rc->oldtime) / 1000;
	if (data->rc->move_f == 1)
		go_fwd_back(data, W);
	if (data->rc->move_b == 1)
		go_fwd_back(data, S);
	if (data->rc->move_l == 1)
		go_left_right(data, A);
	if (data->rc->move_r == 1)
		go_left_right(data, D);
	if (data->rc->rot_r == 1)
		rotate(data, data->rc->frame_time * 3);
	if (data->rc->rot_l == 1)
		rotate(data, -data->rc->frame_time * 3);
	mouse_rot(data);
	mlx_destroy_image(data->ptr, data->img->img);
	raycasting_loop(data);
	return (0);
}
