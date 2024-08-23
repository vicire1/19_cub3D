#include "../include/cub3d.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == W)
		data->rc->move_f = 1;
	if (keysym == S)
		data->rc->move_b = 1;
	if (keysym == L_ARR)
		data->rc->rot_l = 1;
	if (keysym == R_ARR)
		data->rc->rot_r = 1;
	// if (keysym == A)
	//     data->rc->move_l = 1;
	// if (keysym == D)
	//     data->rc->move_r = 1;
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == W)
		data->rc->move_f = 0;
	if (keysym == S)
		data->rc->move_b = 0;
	if (keysym == L_ARR)
		data->rc->rot_l = 0;
	if (keysym == R_ARR)
		data->rc->rot_r = 0;
	// if (keysym == A)
	//     data->rc->move_l = 0;
	// if (keysym == D)
	//     data->rc->move_r = 0;
	return (0);
}

void	move_fwd(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->rc->pl_pos[1] + (data->rc->pl_dir[1] * data->rc->frame_time * 5);
	new_pos_y = data->rc->pl_pos[0] + (data->rc->pl_dir[0] * data->rc->frame_time * 5);
	if (data->map[(int)new_pos_y][(int)new_pos_x] == 'O'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'N'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'W'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'E'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'S')
	{
		data->rc->pl_pos[1] = new_pos_x;
		data->rc->pl_pos[0] = new_pos_y;
		mlx_destroy_image(data->ptr, data->img->img);
		raycasting_loop(data);
	}
}

void	move_back(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->rc->pl_pos[1] - (data->rc->pl_dir[1] * data->rc->frame_time * 5);
	new_pos_y = data->rc->pl_pos[0] - (data->rc->pl_dir[0] * data->rc->frame_time * 5);
	if (data->map[(int)new_pos_y][(int)new_pos_x] == 'O'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'N'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'W'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'E'
		|| data->map[(int)new_pos_y][(int)new_pos_x] == 'S')
	{
		data->rc->pl_pos[1] = new_pos_x;
		data->rc->pl_pos[0] = new_pos_y;
		mlx_destroy_image(data->ptr, data->img->img);
		raycasting_loop(data);
	}
}

void	rotate(t_data *data, double speed)
{
	double	old_dir_X;
	double	old_plane_X;

	old_dir_X = data->rc->pl_dir[1];
	data->rc->pl_dir[1] = data->rc->pl_dir[1] * cos(speed) - data->rc->pl_dir[0]
		* sin(speed);
	data->rc->pl_dir[0] = old_dir_X * sin(speed) + data->rc->pl_dir[0]
		* cos(speed);
	old_plane_X = data->rc->plane[1];
	data->rc->plane[1] = data->rc->plane[1] * cos(speed) - data->rc->plane[0]
		* sin(speed);
	data->rc->plane[0] = old_plane_X * sin(speed) + data->rc->plane[0]
		* cos(speed);
	mlx_destroy_image(data->ptr, data->img->img);
	raycasting_loop(data);
}

int	move(t_data *data)
{
    struct timeval	time;

    data->rc->oldtime = data->rc->time;
	gettimeofday(&time, NULL);
	data->rc->time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	data->rc->frame_time = (data->rc->time - data->rc->oldtime) / 1000;
	if (data->rc->move_f == 1)
		move_fwd(data);
	if (data->rc->move_b == 1)
		move_back(data);
	if (data->rc->rot_r == 1)
		rotate(data, data->rc->frame_time * 3);
	if (data->rc->rot_l == 1)
		rotate(data, -data->rc->frame_time * 3);
	return (0);
}
