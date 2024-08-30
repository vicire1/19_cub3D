/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:55 by vdecleir          #+#    #+#             */
/*   Updated: 2024/08/30 23:44:00 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_ray_and_deltadist(t_data *data, int i)
{
	data->rc->cam_x = 2 * (i / (double)SCREEN_W) - 1;
	data->rc->ray_dir_x = data->rc->pl_dir[1] + data->rc->plane[1]
		* data->rc->cam_x;
	data->rc->ray_dir_y = data->rc->pl_dir[0] + data->rc->plane[0]
		* data->rc->cam_x;
	data->rc->map_x = (int)data->rc->pl_pos[1];
	data->rc->map_y = (int)data->rc->pl_pos[0];
	if (data->rc->ray_dir_x == 0)
		data->rc->delta_dist_x = 1e30;
	else
		data->rc->delta_dist_x = fabs(1 / data->rc->ray_dir_x);
	if (data->rc->ray_dir_y == 0)
		data->rc->delta_dist_y = 1e30;
	else
		data->rc->delta_dist_y = fabs(1 / data->rc->ray_dir_y);
}

void	get_side_dist(t_data *data)
{
	if (data->rc->ray_dir_x < 0)
	{
		data->rc->step_x = -1;
		data->rc->side_dist_x = (data->rc->pl_pos[1] - data->rc->map_x)
			* data->rc->delta_dist_x;
	}
	else
	{
		data->rc->step_x = 1;
		data->rc->side_dist_x = (data->rc->map_x + 1.0 - data->rc->pl_pos[1])
			* data->rc->delta_dist_x;
	}
	if (data->rc->ray_dir_y < 0)
	{
		data->rc->step_y = -1;
		data->rc->side_dist_y = (data->rc->pl_pos[0] - data->rc->map_y)
			* data->rc->delta_dist_y;
	}
	else
	{
		data->rc->step_y = 1;
		data->rc->side_dist_y = (data->rc->map_y + 1.0 - data->rc->pl_pos[0])
			* data->rc->delta_dist_y;
	}
}

void	hit_a_wall(t_data *data)
{
	while (data->rc->hit == 0)
	{
		if (data->rc->side_dist_x < data->rc->side_dist_y)
		{
			data->rc->side = WE;
			if (data->rc->ray_dir_x < 0)
				data->rc->side = EA;
			data->rc->side_dist_x += data->rc->delta_dist_x;
			data->rc->map_x += data->rc->step_x;
		}
		else
		{
			data->rc->side = NO;
			if (data->rc->ray_dir_y < 0)
				data->rc->side = SO;
			data->rc->side_dist_y += data->rc->delta_dist_y;
			data->rc->map_y += data->rc->step_y;
		}
		if (data->map[data->rc->map_y][data->rc->map_x] == '1')
			data->rc->hit = 1;
	}
	if (data->rc->side == EA || data->rc->side == WE)
		data->rc->ray_len = data->rc->side_dist_x - data->rc->delta_dist_x;
	else
		data->rc->ray_len = data->rc->side_dist_y - data->rc->delta_dist_y;
}

void	get_line_spec(t_data *data)
{
	data->rc->line_h = (int)(SCREEN_H / data->rc->ray_len);
	data->rc->line_start = -data->rc->line_h / 2 + SCREEN_H / 2 - 1;
	if (data->rc->line_start < 0)
		data->rc->line_start = 0;
	data->rc->line_end = data->rc->line_h / 2 + SCREEN_H / 2;
	if (data->rc->line_end >= SCREEN_H)
		data->rc->line_end = SCREEN_H - 1;
	if (data->rc->side == EA || data->rc->side == WE)
		data->rc->wall_x = data->rc->pl_pos[0] + data->rc->ray_len
			* data->rc->ray_dir_y;
	else
		data->rc->wall_x = data->rc->pl_pos[1] + data->rc->ray_len
			* data->rc->ray_dir_x;
	data->rc->wall_x -= floor(data->rc->wall_x);
	data->rc->tex_x = (int)(data->rc->wall_x * (double)TEX_SIZE);
	if (data->rc->side == EA || data->rc->side == NO)
		data->rc->tex_x = TEX_SIZE - data->rc->tex_x - 1;
	data->rc->step = 1.0 * TEX_SIZE / data->rc->line_h;
	data->rc->tex_pos = (data->rc->line_start - (SCREEN_H / 2)
			+ (data->rc->line_h / 2)) * data->rc->step;
}

void	raycasting_loop(t_data *data)
{
	int	i;

	i = -1;
	data->img->img = mlx_new_image(data->ptr, SCREEN_W, SCREEN_H);
	if (!data->img->img)
		free_all(data, ERR ERR_MALLOC, 1);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	while (++i < SCREEN_W)
	{
		data->rc->hit = 0;
		get_ray_and_deltadist(data, i);
		get_side_dist(data);
		hit_a_wall(data);
		get_line_spec(data);
		draw_lines(data, i);
	}
	put_minimap(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
	if (data->rc->shoot == 1)
	{
		if (data->counter > 10)
			data->counter = 0;
		if (data->counter < 5)
			mlx_put_image_to_window(data->ptr, data->win, data->shoot_img, 590, 370);\
		data->counter++;
	}
	mlx_put_image_to_window(data->ptr, data->win, data->gun, 0, 0);
}
