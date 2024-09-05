/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:59:54 by vdecleir          #+#    #+#             */
/*   Updated: 2024/09/05 08:39:20 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/ft_printf_fd/ft_printf.h"
# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR "\033[1;31mError\n\033[00m"
# define ERR_ARG_NB_FEW "\033[1;31mToo few arguments\n\033[00m"
# define ERR_MALLOC "\033[1;31mMalloc failed\n\033[00m"
# define ERR_OPEN "\033[1;31mOpen failed\n\033[00m"
# define ERR_ARG_NB_MUCH "\033[1;31mToo many arguments\n\033[00m"
# define ERR_ARG_NOT_CUB "\033[1;31mThe map is not a '.cub' file\n\033[00m"
# define ERR_ARG_NOT_VALID_NAME "\033[1;31mInvalid file name\n\033[00m"
# define ERR_MISSING_DATA "\033[1;31mMissing data(s)\n\033[00m"
# define ERR_TO_MUCH_DATA "\033[1;31mData(s) in double\n\033[00m"
# define ERR_BAD_DATA "\033[1;31mBad data\n\033[00m"

# define ERR_COL_C_DATA "\033[1;31mBad ceiling data\n\033[00m"
# define ERR_COL_F_DATA "\033[1;31mBad floor data\n\033[00m"

# define ERR_WALL_NO_DATA "\033[1;31mBad north wall data\n\033[00m"
# define ERR_WALL_SO_DATA "\033[1;31mBad south wall data\n\033[00m"
# define ERR_WALL_WE_DATA "\033[1;31mBad west wall data\n\033[00m"
# define ERR_WALL_EA_DATA "\033[1;31mBad east wall data\n\033[00m"

# define ERR_DATA_AFTER_MAP "\033[1;31mData after the map\n\033[00m"
# define ERR_MAP_DATA "\033[1;31mIncorect data in the map\n\033[00m"

# define ERR_PLAYER_CNTR "\033[1;31mMore than one player\n\033[00m"
# define ERR_MAP_NOT_CLOSED "\033[1;31mMap is not closed\n\033[00m"
# define ERR_MAP_NOT_CLOSE_BY_ONE "\033[1;31mOnly \'1\' can surround the map\n\033[00m"
# define ERR_PLAYER_LESS_CNTR "\033[1;31mNo player\n\033[00m"

# define FOV 0.8
# define SCREEN_W 1280
# define SCREEN_H 720
# define TEX_SIZE 64
# define MAP_SIZE 180

# define A 0
# define W 13
# define S 1
# define D 2
# define L_ARR 123
# define R_ARR 124
# define TAB 48
# define SPACE 49
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

typedef struct s_parsing_col
{
	int				check_n;
	int				check_v;
	int				v1;
	int				v2;
	int				check_nb;
}					t_parsing_col;

typedef struct s_parsing
{
	int				no_line;
	int				so_line;
	int				we_line;
	int				ea_line;
	int				col_c_line;
	int				col_f_line;
	int				no_status;
	int				so_status;
	int				we_status;
	int				ea_status;
	int				col_c_status;
	int				col_f_status;
	int				longest_map_len;
	int				map_h;
}					t_parsing;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_rc
{
	double	pl_pos[2]; // position du player
	double	pl_dir[2]; // direction du player (-1, 0, 1) en x ou y
	double	plane[2]; // l'angle de vue
	double	time;
	double	oldtime;
	double	cam_x;
	double	ray_dir_x; // rayon de vue
	double	ray_dir_y;
	double	side_dist_x; // distance entre jour et prochain crsement avec x ou y
	double	side_dist_y;
	double	delta_dist_x; // distance entre un x et un autre x
	double	delta_dist_y;
	int		map_x; // int de la position qui va permettre d'aller voir plus loin
	int		map_y;
	int		step_x; // direction
	int		step_y;
	int		hit; // flag pour avoir si on a rencontre un mur
	int		side; // savoir si on touche en NS ou WE
	double	ray_len; // longueur du rayon de vue avant qu'il touche
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
	int		mouse;
	int		shoot;
	double	wall_x; // ou le mur a ete touche exactement
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}					t_rc;

typedef struct s_data
{
	char			*path[4];
	t_img			txtr[4];
	void			*gun;
	void			*shoot_img;
	int				color_f[3];
	int				floor_color;
	int				color_c[3];
	int				cell_color;
	char			**map;
	int				fd_map;
	char			**all_file;
	t_parsing		pars;
	t_parsing_col	pars_col;
	void			*ptr;
	void			*win;
	t_img			*img;
	t_rc			*rc;
	int				counter;
}					t_data;

// parsing
void				parsing(int ac, char **av, t_data *data);
// paring_data
void				init_pars_data(t_data *data);

// colors_pasing
// c_colors_parsing
int					init_pars_col(t_data *data);
void				check_color_c_data(t_data *data);
void				convert_rgb_hex_cell(t_data *data);
// f_colors_parsing
void				check_comma(t_data *data, char c, int i);
void				check_color_f_data(t_data *data);
void				convert_rgb_hex_floor(t_data *data);

// walls_parsing
// wall_parsing
void				check_ea_data(t_data *data);
void				check_we_data(t_data *data);
void				check_so_data(t_data *data);
void				check_no_data(t_data *data);
// wall parsing_utils
void				check_after_word(t_data *data, char *str);
int					get_len_of_word(char *str);

// map_parsing
void				pars_map(t_data *data);

// map_surround
void				check_map_is_surround(t_data *data);

// map_parsing_utils
void				check_if_empty_line(t_data *data, int i);
int					check_if_data_line(char *str);
int					check_if_map_line(char *str);
int					nb_line_map(t_data *data);
void				check_map_is_closed(t_data *data, int x, int y);

// player_parsing
void				check_player_is_correct(t_data *data);
void				recover_player_start_dir(t_data *data, char c);
void				recover_player_start_pos(t_data *data);

// parsing_lil_fctn
void				col_c_in_line(t_data *data, int which);
void				col_f_in_line(t_data *data, int which);
void				no_in_line(t_data *data, int which);
void				so_in_line(t_data *data, int which);
void				we_in_line(t_data *data, int which);
// parsing_lil_fctn_p2
void				ea_in_line(t_data *data, int which);
void				check_if_missing_data(t_data *data);
void				check_if_to_much_data(t_data *data);
int					map_char(char c);

// map_parsing_utils
void				check_if_empty_line(t_data *data, int i);
int					check_if_data_line(char *str);
int					check_if_map_line(char *str);
int					nb_line_map(t_data *data);
void				check_map_is_closed(t_data *data, int x, int y);

// player_parsing
void				check_player_is_correct(t_data *data);
void				recover_player_start_dir(t_data *data, char c);
void				recover_player_start_pos(t_data *data);

// parsing_lil_fctn
void				col_c_in_line(t_data *data, int which);
void				col_f_in_line(t_data *data, int which);
void				no_in_line(t_data *data, int which);
void				so_in_line(t_data *data, int which);
void				we_in_line(t_data *data, int which);
// parsing_lil_fctn_p2
void				ea_in_line(t_data *data, int which);
void				check_if_missing_data(t_data *data);
void				check_if_to_much_data(t_data *data);
int					map_char(char c);

// MLX
void				create_window(t_data *data);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				draw_lines(t_data *data, int i);
int					cross_escape(t_data *data);
int					key_release(int keysym, t_data *data);
int					key_press(int keysym, t_data *data);
void				init_rc_struct(t_data *data);
void				put_minimap(t_data *data);
int					is_in_map(t_data *data, double x, double y);
int					is_wall(t_data *data, int x, int y);
void				mouse_rot(t_data *data);
void				gun_shoot(t_data *data);

// raycasting
void				raycasting_loop(t_data *data);
int					move(t_data *data);
void				rotate(t_data *data, double speed);

// utils libft
char				*ft_strdup(const char *s, t_data *data);
char				*ft_substr(char const *s, unsigned int start, size_t len,
						t_data *data);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
int					is_white_space(char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char const *s1, char const *s2, t_data *data);
size_t				ft_strlen(const char *str);

// utils parsing
void				copy_all_file(t_data *data, char *map_name);
int					ft_strlen_before_n_line(char *str);
int					recover_tab_size(char **tab);
char				*mall_space_line(int len, t_data *data);

// free_utils
void				free_all(t_data *data, char *msg, int exit_s);

#endif