#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

uint32_t	get_color_value(t_data *data)
{
	int	pix_index;
	unsigned char *pixel;
	uint32_t color;

	pix_index = (TEX_SIZE * data->rc->tex_y + data->rc->tex_x) * (data->txtr[data->rc->side].bits_per_pixel / 8);
	pixel = (unsigned char *)&data->txtr[data->rc->side].addr[pix_index];
	color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
	return (color);
}

void	draw_lines(t_data *data, int i)
{
	uint32_t	color;
	int			n;

	n = -1;
	while (++n < data->rc->line_start)
		my_mlx_pixel_put(data->img, i, n, 0x00CCFFFF);
	while (data->rc->line_start < data->rc->line_end)
	{
		data->rc->tex_y = (int)data->rc->tex_pos & (TEX_SIZE - 1);
		data->rc->tex_pos += data->rc->step;
		color = get_color_value(data);
		my_mlx_pixel_put(data->img, i, data->rc->line_start, color);
		data->rc->line_start++;
	}
	n = data->rc->line_end;
	while (++n < SCREEN_H)
		my_mlx_pixel_put(data->img, i, n, 0x00C0C0C0);
}