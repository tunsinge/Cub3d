/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:31 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/25 09:52:48 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "get_next_line_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <string.h>

# define VAR uwu->ray
# define MAX_DOF 25

# define WHI 0xFFFFFFFF
# define BLA 0x000000FF
# define WHITR 0xFFFFFF1F
# define RED 0xFF0000FF
# define GRE 0x00FF00FF
# define BLU 0x0000FFFF
# define CYA 0x00FFFFFF
# define YEL 0xFFFF00FF
# define PIN 0xFF00FFFF
# define ALP 0x00000000

# define PI 3.1415926535
# define P2 1.57079632675
# define P3 4.71238898038
# define DR 0.0174533

# define WINW 1440
# define WINH 960
# define N_SPEED 0.25
# define S_SPEED 0.75

# define OPEN_ERROR "Error\nOpen failed.\n"
# define INV_ARGS "Error\n1 Argument is required.\n"
# define ETRANGER_ERROR "Error\nInvalid character in map.\n"
# define INVALID_LINE "Error\nInvalid line in file.\n"
# define NOT_CLOSED_MAP "Error\nMap is not closed\n"
# define INVALID_COLOR_FORMAT "Error\nInvalid color format\n"
# define INVALID_COLOR_RGB_VALUE "Error\nInvalid RGB value in colors\n"
# define INVALID_TEXTURES_CODE "Error\nInvalid or duplicate texture or color \
								identifier in textures\n"
# define INVALID_TEXTURE_PATH "Error\nInvalid texture path\n"
# define INVALID_TEXTURE_FORMAT "Error\nInvalid texture format\n"
# define INVALID_PATH "Error\nMap is not valid. It must end with .cub.\n"
# define NO_START_ERROR "Error\nNo start for the player in the map\n"
# define LOADING_TEXTURE_ERROR "Error\nError while trying to load a texture\n"
# define FILE_EMPTY "Error\nError file is empty\n"

# define KEY_FORWARD MLX_KEY_W
# define KEY_BACKWARD MLX_KEY_S
# define KEY_STRAF_RIGHT MLX_KEY_D
# define KEY_STRAF_LEFT MLX_KEY_A
# define KEY_ROTATE_RIGHT MLX_KEY_RIGHT
# define KEY_ROTATE_LEFT MLX_KEY_LEFT
# define KEY_RUN MLX_KEY_LEFT_SHIFT

typedef struct s_textures
{
	char			*texture_no;
	char			*texture_so;
	char			*texture_ea;
	char			*texture_we;
	int				color_fl;
	int				color_ce;
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_ea;
	mlx_texture_t	*text_we;
}	t_textures;

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_r;
	int	key_l;
	int	key_wi;
	int	key_shift;
	int	key_jump;
}	t_keys;

typedef struct s_drwlvars
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;
}	t_drwlvars;

typedef struct s_ray
{
	float			pdx;
	float			pdy;
	float			pdxs;
	float			pdys;
	float			pxx;
	float			pyy;
	float			px;
	float			py;
	float			pa;
	float			rx;
	float			ry;
	float			ra;
	float			xo;
	float			yo;
	float			ray_nb;
	float			r;
	float			dist;
	float			dis_h;
	float			hx;
	float			hy;
	float			a_tan;
	float			dis_v;
	float			vx;
	float			vy;
	float			ntan;
	float			shade;
	float			ca;
	float			line_h;
	float			sext;
	float			seyt;
	float			ty_step;
	float			ty_off;
	float			line_o;
	float			ty;
	float			tx;
	int				mx;
	int				my;
	int				dof;
	int				y;
	int				color;
	int				w;
	int				h;
	int				z;
	int				xy[2];
	mlx_texture_t	*texture;
}	t_ray;

typedef struct s_cub3d
{
	int			i;
	int			map_s_x;
	int			map_s_y;
	int			hehe;
	float		px;
	float		py;
	float		pa;
	int			m_size;
	int			p_size;
	int			p_color;
	float		speed;
	float		jumping;
	char		**map;
	mlx_image_t	*player_img;
	mlx_image_t	*map_img;
	mlx_image_t	*trwad_img;
	t_textures	*textures;
	t_ray		*ray;
	t_keys		keys;
	mlx_t		*mlx;
}	t_cub3d;

// check_map.c

int			is_etranger(char c);
int			check_map(char **map);
int			check_map_path(char **av);
int			check_map_closed(t_cub3d *uwu);

// collisions.c

int			test_collide(t_cub3d *uwu, int x, int y);
int			find_x_pos(t_cub3d *uwu, int dx);
int			find_y_pos(t_cub3d *uwu, int dy);
void		move_x(t_cub3d *uwu, float dx);
void		move_y(t_cub3d *uwu, float dy);

// controls.c

void		init_controls(t_cub3d *uwu);
void		controls_hook(void *param);
void		set_key(mlx_key_data_t keydata, keys_t key, int *value);
void		key_hook(mlx_key_data_t keydata, void *param);
void		move(t_cub3d *uwu);

// controls2.c

void		rotate(t_cub3d *uwu);
void		mouse(t_cub3d *uwu);
void		map_zoom(t_cub3d *uwu);
void		jump(t_cub3d *uwu);

// error.c

void		*error(char *code);

// fill.c

void		print_map(t_cub3d *uwu);
void		fill_map(t_cub3d *uwu);
int			max_width(t_cub3d *uwu);

// ft_atoi.c

int			ft_atoi(char *str);

// ft_split.c

char		**ft_split(char const *s, char c);

// ft_strcmp.c

int			ft_strcmp(char *s1, char *s2);

// ft_strdup.c

char		*ft_strdup(char *s1);
char		**ft_strrdup(char **s1);
char		**ft_strrldup(char **s1, int l);
char		*ft_strdupnonl(char *s1);
char		*ft_strldup(char *s1, int l);

// ft_strjoin.c

char		*ft_strjoinn(char *s1, char **str2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinfree(char **s1, char const *s2);
char		*ft_strjoinnfree(char **s1, char **str2, char *sep);

// ft_strlen.c

int			ft_strlen(char *str);
int			ft_strrlen(char **str);

// ft_substr.c

char		*ft_substr(char *s, int start, int len);

// main.c`

void		init_(t_cub3d *uwu, char **av);

// parsing_utils.c

void		free_s(char **str);
int			is_num(char *num);
int			store_color(t_cub3d *uwu, char **fields);
int			store_texture(t_cub3d *uwu, char **fields);
int			verify_texture(char *texture, int *pb);

// parsing.c

char		**parse_map(t_cub3d *uwu, char *path);
char		**append_to_map(char *line, char **map);
int			parse_textures(t_cub3d *uwu, int fd);

// quit.c

void		quit_program(void);

// raycast.c

void		draw_col(mlx_image_t *img, int xy[2], int x, int color);
float		dist(float ax, float ay, float bx, float by);
void		check_angle(float *ra);
void		raycaster(t_cub3d *uwu);

// raycast2.c

void		orientation(t_cub3d *uwu);
void		setup(t_cub3d *uwu);
void		calculations(t_cub3d *uwu);
void		draw(t_cub3d *uwu);

// rc_h.c

void		horizontal(t_cub3d *uwu);
void		horizontal2(t_cub3d *uwu);

// rc_v.c

void		vertical(t_cub3d *uwu);
void		vertical2(t_cub3d *uwu);

// render.c

void		init_img(t_cub3d *uwu);
void		render(t_cub3d *uwu);
void		render_player(t_cub3d *uwu);
void		init_player(t_cub3d *uwu);
void		init_map(t_cub3d *uwu);

// render2.c

mlx_image_t	*fill(mlx_t *mlx, int w, int h, uint32_t color);
void		fill_img(t_cub3d *uwu, int w, int h, uint32_t color);

// textures.c

int			load_textures(t_textures *textures);
void		delete_textures(t_textures *textures);
int			pixel_to_color(mlx_texture_t *text, uint32_t x, uint32_t y);

// utils.c

void		set_angle(t_cub3d *uwu, char c);
int			is_player(char c);
int			get_pp(t_cub3d *uwu);
int			get_rgba(int r, int g, int b, int a);

// weapon.c

#endif // CUB3D_H
