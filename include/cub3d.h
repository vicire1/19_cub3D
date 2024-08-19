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
# define ERR_MISSING_DATA START_RED_PRINTF"Some data is missing in the file\n"FINISH_RED_PRINTF
# define ERR_TO_MUCH_DATA START_RED_PRINTF"Some data is in double in the file\n"FINISH_RED_PRINTF     /// check la trad
# define ERR_BAD_DATA START_RED_PRINTF"Bad data in the file\n"FINISH_RED_PRINTF 
# define ERR_COL_C_DATA START_RED_PRINTF"Bad ceiling data in the file\n"FINISH_RED_PRINTF
# define ERR_COL_F_DATA START_RED_PRINTF"Bad floor data in the file\n"FINISH_RED_PRINTF 


# define PARS_C "C"
# define PARS_F "F"
# define PARS_NO "NO"
# define PARS_SU "SU"
# define PARS_WE "WE"
# define PARS_EA "EA"


typedef struct	s_parsing
{
	int no_line;
	int	su_line;
	int	we_line;
	int	ea_line;
	int	col_c_line;
	int	col_f_line;

	int no_status;
	int	su_status;
	int	we_status;
	int	ea_status;
	int	col_c_status;
	int	col_f_status;
}				t_parsing;

typedef struct s_data
{
	char	*path_N;
	char	*path_S;
	char	*path_W;
	char	*path_E;
	int		color_f[3];
	int		color_c[3];
	char	**map;
	float	pl_x;
	float	pl_y;
	int		fd_map;
	char	**all_file;
	t_parsing pars;
}			t_data;

int			main(int ac, char **av);

// parsing
void		parsing(int ac, char **av, t_data *data);
// paring_data
void	init_pars_data(t_data *data);
// c_colors_parsing
void	check_color_c_data(t_data *data);
// f_colors_parsing
void	check_color_f_data(t_data *data);

// utils libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		is_white_space(char c);
size_t	ft_strlen(const char *str);
// utils parsing
void	copy_all_file(t_data *data, char *map_name);
void	all_file_free(t_data *data);
void	print_exit(char *msg);

#endif