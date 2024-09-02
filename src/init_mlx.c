/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:45 by vdecleir          #+#    #+#             */
/*   Updated: 2024/09/02 16:42:35 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_textures_addr(t_data *data)
{
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

void	load_xpm(t_data *data)
{
	int	w;
	int	h;

	data->txtr[NO].img = mlx_xpm_file_to_image(data->ptr, data->path[NO], &w,
			&h);
	data->txtr[SO].img = mlx_xpm_file_to_image(data->ptr, data->path[SO], &w,
			&h);
	data->txtr[WE].img = mlx_xpm_file_to_image(data->ptr, data->path[WE], &w,
			&h);
	data->txtr[EA].img = mlx_xpm_file_to_image(data->ptr, data->path[EA], &w,
			&h);
	data->gun = mlx_xpm_file_to_image(data->ptr, "./texture/machine_gun.xpm",
			&w, &h);
	data->shoot_img = mlx_xpm_file_to_image(data->ptr, "texture/explosion.xpm",
			&w, &h);
	if (!data->txtr[NO].img || !data->txtr[SO].img || !data->txtr[WE].img
		|| !data->txtr[EA].img || !data->gun || !data->shoot_img)
		free_all(data, ERR ERR_MALLOC, 1);
	get_textures_addr(data);
}

void	init_rc_struct(t_data *data)
{
	data->rc = malloc(sizeof(t_rc));
	if (!data->rc)
		free_all(data, ERR ERR_MALLOC, 1);
	data->rc->pl_dir[0] = 0;
	data->rc->pl_dir[1] = 0;
	data->rc->plane[0] = 0;
	data->rc->plane[1] = 0;
	data->rc->move_b = 0;
	data->rc->move_f = 0;
	data->rc->move_l = 0;
	data->rc->move_r = 0;
	data->rc->rot_l = 0;
	data->rc->rot_r = 0;
	data->rc->mouse = 0;
	data->rc->shoot = 0;
	data->rc->time = 0;
	data->counter = 0;
}

void	create_window(t_data *data)
{
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, SCREEN_W, SCREEN_H, "Cub3D");
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		free_all(data, ERR ERR_MALLOC, 1);
	data->img->img = NULL;
	load_xpm(data);
	raycasting_loop(data);
	mlx_mouse_move(data->win, SCREEN_W / 2, SCREEN_H / 2);
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 3, 1L << 1, &key_release, data);
	mlx_hook(data->win, 17, 0, &cross_escape, data);
	mlx_loop_hook(data->ptr, &move, data);
	mlx_loop(data->ptr);
}
