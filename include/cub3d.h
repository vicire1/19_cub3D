#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "../src/mlx/mlx.h"
# include "../src/ft_printf_fd/ft_printf.h"

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

# define FOV 0.8
# define SCREEN_W 1280
# define SCREEN_H 720
# define TEX_SIZE 64
# define MAP_SIZE SCREEN_H/4

# define A 0
# define W 13
# define S 1
# define D 2
# define L_ARR 123
# define R_ARR 124
# define ESC 53

# define PARS_C "C"
# define PARS_F "F"
# define PARS_NO "NO"
# define PARS_SO "SO"
# define PARS_WE "WE"
# define PARS_EA "EA"

# define NO 0
# define SO 1
# define WE 2
# define EA 3


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
	int	map_h;
}				t_parsing;

typedef struct s_img
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}      t_img;

typedef struct	s_rc
{
	double	pl_pos[2];     //position du player
	double	pl_dir[2];	// direction du player (-1, 0, 1) en x ou y
	double	plane[2];	// l'angle de vue
	double	time;
	double	oldtime;
	double	cam_x;
	double	ray_dirX;  //rayon de vue
	double	ray_dirY;
	double	side_distX;		//distance entre jour et prochain croisement avec x ou y
	double	side_distY;
	double	delta_distX;	// distance entre un x et un autre x
	double	delta_distY;
	int		mapX;			// int de la position qui va permettre d'aller voir plus loin
	int		mapY;
	int		stepX;			// direction
	int		stepY;
	int		hit;		// flag pour avoir si on a rencontre un mur
	int		side;		// savoir si on touche en NS ou WE
	double	ray_len;	// longueur du rayon de vue avant qu'il touche
	int		line_h;
	int		line_start;
	int		line_end;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
	int		move_f;
	int		move_b;
	int		move_l;
	int		move_r;
	int		rot_l;
	int		rot_r;
	double	wall_x;    // ou le mur a ete touche exactement
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}	t_rc;

typedef struct s_data
{
	char	*path[4];
	t_img	txtr[4];
	int		color_f[3];
	int		floor_color;
	int		color_c[3];
	int		cell_color;
	char	**map;
	int		fd_map;
	char	**all_file;
	t_parsing pars;
    void    *ptr;
    void    *win;
    t_img   *img;
	t_rc	*rc;
}			t_data;


// parsing
void		parsing(int ac, char **av, t_data *data);
// paring_data
void	init_pars_data(t_data *data);


//colors_pasing
// c_colors_parsing
void	check_color_c_data(t_data *data);
void	convert_rgb_hex_cell(t_data *data);
// f_colors_parsing
void	check_color_f_data(t_data *data);
void	convert_rgb_hex_floor(t_data *data);

//walls_parsing
//wall_parsing
void	check_ea_data(t_data *data);
void	check_we_data(t_data *data);
void	check_so_data(t_data *data);
void	check_no_data(t_data *data);
//wall parsing_utils
void	check_after_word(t_data *data, char *str);
int		get_len_of_word(char *str);

//map_parsing
void	pars_map(t_data *data);

// MLX
void    create_window(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_lines(t_data *data, int i);
int	cross_escape(t_data *data);
int	key_release(int keysym, t_data *data);
int	key_press(int keysym, t_data *data);
void	init_rc_struct(t_data *data);
void    put_mini_map(t_data *data);


// raycasting
void	raycasting_loop(t_data *data);
int 	move(t_data *data);

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

//free_utils
void	free_all(t_data *data, char *msg, int exit_s);

#endif