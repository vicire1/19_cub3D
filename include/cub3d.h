#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

#define START_RED_PRINTF "\033[1;31m"
#define FINISH_RED_PRINTF "\033[00m"

# define ERR START_RED_PRINTF"Error\n"FINISH_RED_PRINTF
# define ERR_ARG_NB_FEW START_RED_PRINTF"Too few arguments\n"FINISH_RED_PRINTF
# define ERR_MALLOC START_RED_PRINTF"Malloc crashed\n"FINISH_RED_PRINTF
# define ERR_OPEN START_RED_PRINTF"Open crashed\n"FINISH_RED_PRINTF
# define ERR_ARG_NB_MUCH START_RED_PRINTF"Too much arguments\n"FINISH_RED_PRINTF
# define ERR_ARG_NOT_CUB START_RED_PRINTF"The map is not a '.cub' file\n"FINISH_RED_PRINTF
# define ERR_ARG_NOT_VALID_NAME START_RED_PRINTF"Invalid file name\n"FINISH_RED_PRINTF


typedef struct s_data
{
	char	*path_N;
	char	*path_S;
	char	*path_W;
	char	*path_E;
	int		color_F[3];
	int		color_C[3];
	char	**map;
	float	pl_x;
	float	pl_y;
	int		fd_map;
	char	**all_file;
}			t_data;

int			main(int ac, char **av);

// parsing
void		parsing(int ac, char **av, t_data *data);


// utils libft
size_t		ft_strlen(const char *str);
// utils parsing
void	copy_all_file(t_data *data, char *map_name);
void	print_exit(char *msg);

#endif