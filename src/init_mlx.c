#include "../include/cub3d.h"

void    put_mini_map(t_data *data)
{
    int x;
    int y;

    x = 804;
    y = 19;
    while (++y <= 120)
    {
        while (++x <= 1004)
            my_mlx_pixel_put(data->img, x, y, 0x00A0A0A0);
        x = 804;
    }
}

void    create_window(t_data *data)
{
    data->ptr = mlx_init();
    data->win = mlx_new_window(data->ptr, 1024, 512, "Cub3D");
    data->img = malloc(sizeof(t_img));
    if (!data->img)
    {
        ft_printf_fd(2, "Error malloc\n");
        exit (1);
    }
    data->img->img = mlx_new_image(data->ptr, 1024, 512);
    data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	put_mini_map(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
	mlx_loop(data->ptr);
}