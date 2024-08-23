#include "../include/cub3d.h"

void	create_window(t_data *data)
{
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, SCREEN_W, SCREEN_H, "Cub3D");
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		ft_printf_fd(2, "Error malloc\n");
		exit(1);
	}
	raycasting_loop(data);
	mlx_hook(data->win, 2, 1L<<0, &key_press, data);
	mlx_hook(data->win, 3, 1L<<1, &key_release, data);
	mlx_loop_hook(data->ptr, &move, data);
	mlx_loop(data->ptr);
}