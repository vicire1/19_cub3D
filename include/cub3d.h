#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>

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
}   t_data;


#endif