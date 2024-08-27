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
	if (keysym == A)
		data->rc->move_l = 1;
	if (keysym == D)
		data->rc->move_r = 1;
	if (keysym == ESC)
	{
		free_all(data, NULL, 0);
		exit(0);
	}
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
	if (keysym == A)
		data->rc->move_l = 0;
	if (keysym == D)
		data->rc->move_r = 0;
	return (0);
}

int	cross_escape(t_data *data)
{
	free_all(data, NULL, 0);
	exit(0);
	return (0);
}

void	load_xpm(t_data *data)
{
	int	w;
	int	h;

	data->txtr[NO].img = mlx_xpm_file_to_image(data->ptr, data->path[NO], &w, &h);
	data->txtr[SO].img = mlx_xpm_file_to_image(data->ptr, data->path[SO], &w, &h);
	data->txtr[WE].img = mlx_xpm_file_to_image(data->ptr, data->path[WE], &w, &h);
	data->txtr[EA].img = mlx_xpm_file_to_image(data->ptr, data->path[EA], &w, &h);
	if (!data->txtr[NO].img || !data->txtr[SO].img || !data->txtr[WE].img
		|| !data->txtr[EA].img)
		exit(1);
	data->txtr[NO].addr = mlx_get_data_addr(data->txtr[NO].img,
			&data->txtr[NO].bits_per_pixel, &data->txtr[NO].line_length,
			&data->txtr[NO].endian);
	data->txtr[SO].addr = mlx_get_data_addr(data->txtr[SO].img,
			&data->txtr[SO].bits_per_pixel, &data->txtr[SO].line_length,
			&data->txtr[SO].endian);
	data->txtr[WE].addr = mlx_get_data_addr(data->txtr[WE].img,
			&data->txtr[WE].bits_per_pixel, &data->txtr[WE].line_length,
			&data->txtr[WE].endian);
	data->txtr[EA].addr = mlx_get_data_addr(data->txtr[EA].img,
			&data->txtr[EA].bits_per_pixel, &data->txtr[EA].line_length,
			&data->txtr[EA].endian);
}

void	create_window(t_data *data)
{
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, SCREEN_W, SCREEN_H, "Cub3D");
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		free_all(data, ERR ERR_MALLOC, 1);
	load_xpm(data);
	raycasting_loop(data);
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 3, 1L << 1, &key_release, data);
	mlx_hook(data->win, 17, 0, &cross_escape, data);
	mlx_loop_hook(data->ptr, &move, data);
	mlx_loop(data->ptr);
}