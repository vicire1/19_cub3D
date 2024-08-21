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

# define ERR_WALL_NO_DATA START_RED_PRINTF"Bad north wall data in the file\n"FINISH_RED_PRINTF
# define ERR_WALL_SO_DATA START_RED_PRINTF"Bad south wall data in the file\n"FINISH_RED_PRINTF
# define ERR_WALL_WE_DATA START_RED_PRINTF"Bad west wall data in the file\n"FINISH_RED_PRINTF
# define ERR_WALL_EA_DATA START_RED_PRINTF"Bad east wall data in the file\n"FINISH_RED_PRINTF

# define ERR_DATA_AFTER_MAP START_RED_PRINTF"There is some data after the map in the file\n"FINISH_RED_PRINTF
# define ERR_MAP_DATA START_RED_PRINTF"There is some incorect data for the map in the file\n"FINISH_RED_PRINTF

# define ERR_PLAYER_CNTR START_RED_PRINTF"There is more than one player in this map\n"FINISH_RED_PRINTF
# define ERR_MAP_NOT_CLOSED START_RED_PRINTF"The map is not closed\n"FINISH_RED_PRINTF
# define ERR_PLAYER_LESS_CNTR START_RED_PRINTF"There is less than one player in this map\n"FINISH_RED_PRINTF



# define PARS_C "C"
# define PARS_F "F"
# define PARS_NO "NO"
# define PARS_SO "SO"
# define PARS_WE "WE"
# define PARS_EA "EA"


typedef struct	s_parsing
{
	int no_line;
	int	so_line;
	int	we_line;
	int	ea_line;
	int	col_c_line;
	int	col_f_line;

	int no_status;
	int	so_status;
	int	we_status;
	int	ea_status;
	int	col_c_status;
	int	col_f_status;

	int longest_map_len;
}				t_parsing;
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
	char	*path_N;
	char	*path_S;
	char	*path_W;
	char	*path_E;
	int		color_f[3];
	int		color_c[3];
	char	**map;
	float	pl_position[2];
	int		pl_direction;
	//0 NORD | 1 SOUTH | 2 WEST | 3 EAST
	int		fd_map;
	char	**all_file;
	t_parsing pars;
}			t_data;



/*!!!!!!!*/
void	print_tab(char **tab);

int			main(int ac, char **av);

// parsing
void		parsing(int ac, char **av, t_data *data);
// paring_data
void	init_pars_data(t_data *data);


//colors_pasing
// c_colors_parsing
void	check_color_c_data(t_data *data);
// f_colors_parsing
void	check_color_f_data(t_data *data);

//walls_parsing
//wall_parsing
void	check_ea_data(t_data *data);
void	check_we_data(t_data *data);
void	check_so_data(t_data *data);
void	check_no_data(t_data *data);
//wall parsing_utils
void	check_after_word(t_data *data, char *str);
int		get_len_of_word(char *str);
    void    *ptr;
    void    *win;
    t_img   *img;

//map_parsing
void	pars_map(t_data *data);


void    create_window(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// utils libft
char	*ft_strdup(const char *s, t_data *data);
char	*ft_substr(char const *s, unsigned int start, size_t len, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		is_white_space(char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2, t_data *data);
size_t	ft_strlen(const char *str);

// utils parsing
void	copy_all_file(t_data *data, char *map_name);
int	ft_strlen_before_n_line(char *str);
int	recover_tab_size(char **tab);
char	*mall_space_line(int len, t_data *data);
void	print_exit(char *msg);

//free_utils
void	all_file_free(t_data *data);
void	free_all(t_data *data, char *msg, int exit_s);

#endif