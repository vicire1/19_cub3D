/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:39 by vdecleir          #+#    #+#             */
/*   Updated: 2024/08/29 15:39:58 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

uint32_t	get_color_value(t_data *data)
{
	int				pix_index;
	unsigned char	*pixel;
	uint32_t		color;

	pix_index = (TEX_SIZE * data->rc->tex_y + data->rc->tex_x)
		* (data->txtr[data->rc->side].bits_per_pixel / 8);
	pixel = (unsigned char *)&data->txtr[data->rc->side].addr[pix_index];
	color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
	return (color);
}

void	draw_cross(t_data *data)
{
	int	x;
	int	y;
	
	x = SCREEN_W/2 - 11;
	y = SCREEN_H/2 - 11;
	if (x < 0 || y < 0)
		free_all(data, "Screen too small", 1);
	while (++x <= SCREEN_W/2 + 10)
		my_mlx_pixel_put(data->img, x, SCREEN_H/2, 0x00FFFFFF);
	while (++y <= SCREEN_H/2 + 10)
		my_mlx_pixel_put(data->img, SCREEN_W/2, y, 0x00FFFFFF);
}

void	draw_lines(t_data *data, int i)
{
	uint32_t color;
	int n;

	n = -1;
	while (++n < data->rc->line_start)
		my_mlx_pixel_put(data->img, i, n, data->cell_color);
	while (data->rc->line_start <= data->rc->line_end)
	{
		data->rc->tex_y = (int)data->rc->tex_pos & (TEX_SIZE - 1);
		data->rc->tex_pos += data->rc->step;
		color = get_color_value(data);
		my_mlx_pixel_put(data->img, i, data->rc->line_start, color);
		data->rc->line_start++;
	}
	n = data->rc->line_end;
	while (++n < SCREEN_H)
		my_mlx_pixel_put(data->img, i, n, data->floor_color);
	draw_cross(data);
}
