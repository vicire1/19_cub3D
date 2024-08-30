#include "../include/cub3d.h"

int    is_in_map(t_data *data, int x, int y)
{
    if (x < 0 || y < 0)
        return (0);
    if (x > data->pars.longest_map_len - 1 || y > data->pars.map_h - 1)
        return (0);
    else
        return (1);
}

int is_wall(t_data *data, int x, int y)
{
    if (data->map[y][x] == '1')
        return (1);
    else
        return (0);
}

void    put_bg(t_data *data)
{
    int x;
    int y;
    double dist_x;
    double dist_y;

    y = SCREEN_H/90;
    dist_y = data->rc->pl_pos[0] - 4.5;
    while (y < MAP_SIZE + SCREEN_H/90)
    {
        x = SCREEN_W - SCREEN_H/90 - MAP_SIZE;
        dist_x = data->rc->pl_pos[1] - 4.5;
        while (x < SCREEN_W - SCREEN_H/90)
        {
            // printf("y : %d     %d\n", (int)dist_y, data->pars.map_h);
            // printf("x : %d     %d\n", (int)dist_x, data->pars.longest_map_len);
            if (is_in_map(data, (int)dist_x, (int)dist_y) && is_wall(data, (int)dist_x, (int)dist_y))
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

// void    draw_minimap(t_data *data)
// {
//     double  dist_x;
//     double  dist_y;

//     dist_y = data->rc->pl_pos[0] - 4.0;

//     while (dist_y < data->rc->pl_pos[0] + 4.0)
//     {
//         dist_x = data->rc->pl_pos[1] - 4.0;
//         while (dist_x < data->rc->pl_pos[1] + 4.0)
//         {
//             is_in_map(data, (int)dist_x, (int)dist_y);
//         }
//     }
// }

// void    draw_minimap(t_data *data)
// {
//     int x;
//     int y;

//     y = SCREEN_H/90;
//     while (y < SCREEN_H/90 + MAP_SIZE)
//     {
//         x = SCREEN_W - SCREEN_H/90 - MAP_SIZE;
//         while (x < SCREEN_W - SCREEN_H/90)
//         {
//             my_mlx_pixel_put(data->img, x, y, 0x00E0E0E0);
//             x++;
//         }
//         y++;
//     }
// }

void    put_player(t_data *data)
{
    int x;
    int y;

    y = (SCREEN_H/90) + (MAP_SIZE/2) - 3;
    while (y < (SCREEN_H/90) + (MAP_SIZE/2) + 3)
    {
        x = SCREEN_W - (MAP_SIZE/2) - (SCREEN_H/90) - 3;
        while (x < SCREEN_W - (MAP_SIZE/2) - (SCREEN_H/90) + 3)
        {
            my_mlx_pixel_put(data->img, x, y, 0x00FF0000);
            x++;
        }
        y++;
    }
}

void    put_minimap(t_data *data)
{
    put_bg(data);
    // draw_minimap(data);
    put_player(data);
}
