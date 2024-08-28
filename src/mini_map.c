#include "../include/cub3d.h"

void    draw_map_bg(t_data *data)
{
    int i;
    int j;

    j = SCREEN_W/100 - 1;
    while (++j < MAP_SIZE + SCREEN_W/100)
    {
        i = SCREEN_W - MAP_SIZE - SCREEN_W/100 -1 ;
        while (++i < SCREEN_W - SCREEN_W/100)
            my_mlx_pixel_put(data->img, i, j, 0x00D1D1D1);
    }
}

void    draw_wall(t_data *data, double x, double y)
{
    
}

void    draw_map(t_data *data)
{
    int i;
    int j;

    j = -1;
    while (data->map[++j][i])
    {
        
    }
}

void    put_mini_map(t_data *data)
{
    draw_map_bg(data);
    draw_map(data);
}