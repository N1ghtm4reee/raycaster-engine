/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <mzeouaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:30:52 by mzeouaou          #+#    #+#             */
/*   Updated: 2025/03/15 01:32:54 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <SDL2/SDL.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define ANSI_COLOR_RESET "\033[0m"
# define ANSI_COLOR_BLACK "\033[30m"
# define ANSI_COLOR_RED "\033[31m"
# define ANSI_COLOR_GREEN "\033[32m"
# define ANSI_COLOR_YELLOW "\033[33m"
# define ANSI_COLOR_BLUE "\033[34m"
# define ANSI_COLOR_MAGENTA "\033[35m"
# define ANSI_COLOR_CYAN "\033[36m"
# define ANSI_COLOR_WHITE "\033[37m"

# define WIDTH 1000
# define HEIGHT 600
# define MINI_MAP_H 60
# define MINI_MAP_W 100
# define BLOCK_SIZE 64
# define BLOCK_SIZE_2D 64
# define MINI_MAP_X 100
# define MINI_MAP_Y 100
# define PI 3.141592653589793
# define FOV 60
# define BUFFER_SIZE 13
// view height
# define CUB3D_USAGE "usage ./cub3d [/path/to/map.cub]!"
# define ERR_INVALID_FILENAME "The map file must be ending with .cub!"
# define ERR_NO_PLAYER "No player found!"

typedef struct s_player
{
	int				x;
	int				y;
	int				x_pixel;
	int				y_pixel;
	double			pva; // player view angle
	double			rotaion_speed;
	int				radius;
	int				move_speed;
	int				direction;
}					t_player;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_draw
{
	int				color;
	int				pixel_index;
	int				y;
	int				tex_y;
	int				tex_x;
	double			step;
	double			tex_pos;
}					t_draw;

typedef struct s_texture1
{
	char			*path;
	void			*img;
	char			*tex_data;
	int				width;
	int				height;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_tex;

typedef struct s_window
{
	void			*cnx;
	void			*win;
	t_img			img;
}					t_window;

typedef struct s_ray
{
	double			x;
	double			y;
	double			dst;
	double			ray_angle;
	double			x_intercept;
	double			y_intercept;
	double			x_step;
	double			y_step;
	int				is_ray_facing_down;
	int				is_ray_facing_right;
	double			x_next_step;
	double			y_next_step;
}					t_ray;

typedef struct s_keys
{
	int				forward;
	int				backward;
	int				left;
	int				right;
}					t_keys;

typedef struct s_menu
{
	int				index;
	int				started;
	int				entred;
	int				ended;
	t_tex			menu_img;
}					t_menu;

typedef struct wall_hit
{
	int				vert;
	int				hor;
	int				wall_cord;
}					t_wall;

typedef struct s_game
{
	char			*filename;
	int				map_len;
	int				map_width;
	char			**map;
	void			*img;
	double			view_height;
	double			wall_hit_x;
	double			wall_hit_y;
	double			wall_height;
	int				which_hit;
	int				c_color;
	int				f_color;
	float			slide_amount;
	double			ray_angle;
	t_player		player;
	t_window		window;
	t_ray			ver_ray;
	t_ray			hor_ray;
	t_keys			keys;
	t_wall			wall;
	t_tex			wall_north;
	t_tex			wall_south;
	t_tex			wall_east;
	t_tex			wall_west;
	t_tex			door;
	t_tex			p0;
	t_tex			p1;
	t_tex			p2;
	t_tex			p3;
	t_tex			p4;
	t_menu			menu;
}					t_game;

typedef struct s_texture
{
	char			*line_no;
	char			*line_so;
	char			*line_we;
	char			*line_ea;
	char			*line_f;
	char			*line_c;
}					t_texture;

typedef struct s_texture_F
{
	int				r;
	int				g;
	int				b;
}					t_texture_F;

typedef struct s_texture_C
{
	int				r;
	int				g;
	int				b;
}					t_texture_C;

typedef struct s_dup_texture
{
	bool			no;
	bool			so;
	bool			we;
	bool			ea;
	bool			f;
	bool			c;
}					t_dup_texture;

typedef struct s_data
{
	t_texture_F		*floor;
	t_texture_C		*ceiling;
	t_texture		*map_lines;
	t_dup_texture	*dup_texture;
	char			**map;
	char			**file;
	int				max_len;
	int				num_lines;
	int				fd_map;
}					t_data;

// get_next_line
char				*get_next_line(int fd);

// g scope
void				*get_data(void);
void				*get_game(void);

// parse
char				**parse_map(const char *file_name, t_game *game);
void				find_player(t_game *game);
int					check_path(char *path);
void				init_data(t_data *data);
int					ft_check_file(char *file, t_data *data);
void				store_texture(t_texture *map_lines);
void				convert_fc_to_rgb(t_data *data);
void				check_valid_texture(char A, char B, char *line);
void				format_color(char *line);
void				check_valid_color(char A, char *line);
void				ft_get_texture(char *line, t_texture *map_lines,
						t_data *data);
int					check_spase_tab(char c);
void				check_line_of_map(t_data *data);
void				stor_map(t_data *data, int i);
void				check_zero_and_space(t_data *data);
void				count_lines(char *file, t_data *data);

void				ft_mlx(t_game *game, t_data *data);
void				ft_mlx_pixel_put(t_game *game, int x, int y, int color);

void				setup(t_game *game, int ac, char **av);
void				ft_error(const char *msg);
void				draw_map(t_game *game);
int					found_wall(t_game *game, int x_pos, int y_pos);
double				normalize_angle(double angle);

// hooks
int					keys(int keycode, void *game1);
int					mouse_move_hook(int x, int y, void *game1);
int					drawer(t_game *game);
int					ft_close(t_game *game, int e_status);

//main_utils
int					map_len(char **map);
void				init_keys2(t_game *game);
void				init_keys(t_game *game);

// raycast_utils
int					facing_north(t_game *game);
int					facing_south(t_game *game);
int					facing_west(t_game *game);
int					facing_east(t_game *game);

// raycaster
void				cast_rays(t_game *game);

// ray utils
double				count_distance(double x1, double x2, double y1, double y2);

//
void				cast_rays(t_game *game);
void				draw_3d(t_game *game, int x_start, int y_start,
						int wall_height);
int					is_empty_line(char *line);
void				count_lines(char *file, t_data *data);
void				stor_file(char *file, t_data *data);
void				max_len_of_map(t_data *data, int i);
void				stor_map(t_data *data, int i);
void				check_line_of_map(t_data *data);
void				check_zero_and_space(t_data *data);
void				check_wall(t_data *data);
void				check_valid_map(char *file, t_data *data);
char				*ft_substr_parsing(char *s, int start, int len);
int					r_g_b(int r, int g, int b);
int					ray_facing_north(double ray_angle);
int					ray_facing_south(double ray_angle);
int					ray_facing_east(double ray_angle);
int					ray_facing_west(double ray_angle);
void				draw_ceiling(t_game *game, int y_start, int x_start);
void				draw_floor(t_game *game, int y_start, int x_start,
						int wall_height);
void				destroy_images(t_game *game);
void				init_game(t_game *game, t_ray *hor, t_ray *ver);

// gc
typedef struct s_gc
{
	void			*p;
	struct s_gc		*next;
}					t_gc;

void				*gc_malloc(size_t size);
void				free_all_in_gc(void);
char				*ft_gc_strdup(const char *s);

#endif
