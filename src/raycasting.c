#include "../include/cub3d.h"

void	get_ray_and_deltadist(t_data *data, int i)
{
	data->rc->cam_x = 2 * (i / (double)SCREEN_W) - 1;
	data->rc->ray_dirX = data->rc->pl_dir[1] + data->rc->plane[1]
		* data->rc->cam_x;
	data->rc->ray_dirY = data->rc->pl_dir[0] + data->rc->plane[0]
		* data->rc->cam_x;
	data->rc->mapX = (int)data->rc->pl_pos[1];
	data->rc->mapY = (int)data->rc->pl_pos[0];
	if (data->rc->ray_dirX == 0)
		data->rc->delta_distX = 1e30;
	else
		data->rc->delta_distX = fabs(1 / data->rc->ray_dirX);
	if (data->rc->ray_dirY == 0)
		data->rc->delta_distY = 1e30;
	else
		data->rc->delta_distY = fabs(1 / data->rc->ray_dirY);
}

void	get_side_dist(t_data *data)
{
	if (data->rc->ray_dirX < 0)
	{
		data->rc->stepX = -1;
		data->rc->side_distX = (data->rc->pl_pos[1] - data->rc->mapX)
			* data->rc->delta_distX;
	}
	else
	{
		data->rc->stepX = 1;
		data->rc->side_distX = (data->rc->mapX + 1.0 - data->rc->pl_pos[1])
			* data->rc->delta_distX;
	}
	if (data->rc->ray_dirY < 0)
	{
		data->rc->stepY = -1;
		data->rc->side_distY = (data->rc->pl_pos[0] - data->rc->mapY)
			* data->rc->delta_distY;
	}
	else
	{
		data->rc->stepY = 1;
		data->rc->side_distY = (data->rc->mapY + 1.0 - data->rc->pl_pos[0])
			* data->rc->delta_distY;
	}
}

void	hit_a_wall(t_data *data)
{
	while (data->rc->hit == 0)
	{
		if (data->rc->side_distX < data->rc->side_distY)
		{
			data->rc->side = EA;
			if (data->rc->ray_dirX < 0)
				data->rc->side = WE;
			data->rc->side_distX += data->rc->delta_distX;
			data->rc->mapX += data->rc->stepX;
		}
		else
		{
			data->rc->side = SO;
			if (data->rc->ray_dirY < 0)
				data->rc->side = NO;
			data->rc->side_distY += data->rc->delta_distY;
			data->rc->mapY += data->rc->stepY;
		}
		if (data->map[data->rc->mapY][data->rc->mapX] == '1')
			data->rc->hit = 1;
	}
	if (data->rc->side == EA || data->rc->side == WE)
		data->rc->ray_len = data->rc->side_distX - data->rc->delta_distX;
	else
		data->rc->ray_len = data->rc->side_distY - data->rc->delta_distY;
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
			* data->rc->ray_dirY;
	else
		data->rc->wall_x = data->rc->pl_pos[1] + data->rc->ray_len
			* data->rc->ray_dirX;
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
		exit(1);
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
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
}
