#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <mlx.h>
# include "../src/ft_printf_fd/ft_printf.h"

typedef struct s_img
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}      t_img;

typedef struct s_data
{
    char    *path_N;
    char    *path_S;
    char    *path_W;
    char    *path_E;
    int     color_F[3];
    int     color_C[3];
    char    **map;
    float   pl_x;
    float   pl_y;
    void    *ptr;
    void    *win;
    t_img   *img;
}   t_data;


void    create_window(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif