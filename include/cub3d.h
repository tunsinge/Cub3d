/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:31 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/06/08 12:59:39 by mdoumi           ###   ########.fr       */
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

# define MAX_DOF 150

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
# define B 1000000
# define N_SPEED 0.0625
# define S_SPEED 0.25

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
# define MUL_START_ERROR "Error\nMultiple starts for the player in the map\n"
# define LOADING_TEXTURE_ERROR "Error\nError while trying to load a texture\n"
# define FILE_EMPTY "Error\nError file is empty\n"

# define KEY_FORWARD MLX_KEY_W
# define KEY_BACKWARD MLX_KEY_S
# define KEY_STRAF_RIGHT MLX_KEY_D
# define KEY_STRAF_LEFT MLX_KEY_A
# define KEY_OPEN_DOOR MLX_KEY_E
# define KEY_ROTATE_RIGHT MLX_KEY_RIGHT
# define KEY_ROTATE_LEFT MLX_KEY_LEFT
# define KEY_ZOOM_MAP MLX_KEY_LEFT_CONTROL
# define KEY_RUN MLX_KEY_LEFT_SHIFT
# define KEY_SWAP MLX_KEY_Q
# define KEY_JUMP MLX_KEY_SPACE
# define KEY_SHOOT MLX_KEY_R

typedef struct s_rick
{
	int				f_width;
	int				f_height;
	int				f_wh[2];
	uint32_t		f_nb;
	mlx_texture_t	*full;
	mlx_texture_t	*current;
}	t_rick;

typedef struct s_textures
{
	char			*t_no;
	char			*t_so;
	char			*t_ea;
	char			*t_we;
	int				fl;
	int				ce;
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_ea;
	mlx_texture_t	*text_we;
	mlx_texture_t	*weapon_text;
	mlx_image_t		*weapon_img;
	uint32_t		weapon_current;
	uint32_t		weapon_width;
	uint32_t		weapon_height;
	mlx_texture_t	*portal_text;
	mlx_image_t		*portal_img;
	int				current_weapon;
	mlx_texture_t	*door_no;
	mlx_texture_t	*door_so;
	mlx_texture_t	*door_ea;
	mlx_texture_t	*door_we;
}	t_textures;

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_e;
	int	key_r;
	int	key_l;
	int	key_wi;
	int	key_shift;
	int	key_jump;
	int	key_shoot;
}	t_keys;

typedef struct s_ray
{
	int				is_door[2];
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
	int				c;
	int				w;
	int				h;
	int				z;
	int				xy[2];
	mlx_texture_t	*t;
}	t_ray;

typedef struct s_cub3d
{
	int				i;
	int				face_door;
	int				map_s;
	int				map_s_y;
	int				map_s_x;
	int				hehe;
	float			px;
	float			py;
	float			pa;
	int				m_size;
	int				p_size;
	int				p_color;
	int				m_fix_size;
	float			speed;
	float			jumping;
	char			**map;
	mlx_image_t		*player_img;
	mlx_image_t		*map_img;
	mlx_image_t		*trwad_img;
	mlx_image_t		*cross;
	mlx_texture_t	*cross_text;
	t_textures		*t;
	t_ray			*ray;
	t_keys			keys;
	mlx_t			*mlx;
	t_rick			*ricks[2];
	int				rick_nb;
}	t_cub3d;

// animations.c

void			rick_init(t_cub3d *uwu);
void			rick_next(t_cub3d *uwu);
t_rick			*rick_load_texture(char *path, int width, int height);
void			rick_delete(t_cub3d *uwu);

// check_map.c

int				is_etranger(char c);
int				check_map(char **map);
int				check_map_path(char **av);
int				check_map_closed(t_cub3d *uwu);
int				find_map_width(t_cub3d *uwu);

// collisions.c

void			move_x(t_cub3d *uwu, float dx);
void			move_y(t_cub3d *uwu, float dy);

// controls.c

void			init_controls(t_cub3d *uwu);
void			controls_hook(void *param);
void			set_key(mlx_key_data_t keydata, keys_t key, int *value);
void			key_hook(mlx_key_data_t keydata, void *param);
void			move(t_cub3d *uwu);

// controls2.c

void			rotate(t_cub3d *uwu);
void			mouse(t_cub3d *uwu);
void			map_zoom(t_cub3d *uwu);
void			jump(t_cub3d *uwu);
void			open_doors(t_cub3d *uwu);

// error.c

void			*error(char *code);

// fill.c

void			print_map(t_cub3d *uwu);
void			fill_map(t_cub3d *uwu);
int				max_width(t_cub3d *uwu);

// ft_atoi.c

int				ft_atoi(char *str);

// ft_split.c

char			**ft_split(char const *s, char c);

// ft_strcmp.c

int				ft_strcmp(char *s1, char *s2);

// ft_strdup.c

char			*ft_strdup(char *s1);
char			**ft_strrdup(char **s1);
char			**ft_strrldup(char **s1, int l);
char			*ft_strdupnonl(char *s1);
char			*ft_strldup(char *s1, int l);

// ft_strjoin.c

char			*ft_strjoinn(char *s1, char **str2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char **s1, char const *s2);
char			*ft_strjoinnfree(char **s1, char **str2, char *sep);

// ft_strlen.c

int				ft_strlen(char *str);
int				ft_strrlen(char **str);

// ft_substr.c

char			*ft_substr(char *s, int start, int len);

// main.c

void			init_(t_cub3d *uwu, char **av);

// parsing_utils.c

void			free_s(char **str);
int				is_num(char *num);
int				store_color(t_cub3d *uwu, char **fields);
int				store_texture(t_cub3d *uwu, char **fields);
int				verify_texture(char *texture, int *pb);

// parsing.c

char			**parse_map(t_cub3d *uwu, char *path);
char			**append_to_map(char *line, char **map);
int				parse_textures(t_cub3d *uwu, int fd);

// quit.c

void			quit_program(t_cub3d *uwu, int err);

// raycast.c

void			draw_col(mlx_image_t *img, int xy[2], int x, int color);
float			dist(float ax, float ay, float bx, float by);
void			check_angle(float *ra);
void			raycaster(t_cub3d *uwu);

// raycast2.c

void			orientation(t_cub3d *uwu, t_ray *rays, int t);
void			setup(t_cub3d *uwu);
void			calculations(t_cub3d *uwu);
void			draw(t_cub3d *uwu);

// rc_h.c

void			horizontal(t_cub3d *uwu, t_ray *rays);
void			horizontal2(t_cub3d *uwu, t_ray *rays);

// rc_v.c

void			vertical(t_cub3d *uwu, t_ray *rays);
void			vertical2(t_cub3d *uwu, t_ray *rays);

// render.c

void			init_img(t_cub3d *uwu);
void			render(t_cub3d *uwu);
void			render_player(t_cub3d *uwu);
void			init_player(t_cub3d *uwu);
void			init_map(t_cub3d *uwu);

// render2.c

mlx_image_t		*fill(mlx_t *mlx, int w, int h, uint32_t color);
void			fill_img(t_cub3d *uwu, int w, int h, uint32_t color);
int				is_transparent(char c);

// textures.c

int				load_textures2(t_textures *t);
int				load_textures(t_textures *textures);
void			delete_textures(t_textures *textures);
int				pixel_to_color(t_cub3d *uwu, uint32_t x, uint32_t y);
mlx_texture_t	*texture_area_to_texture(mlx_texture_t *texture,
					int xy[2], int wh[2]);

// textures2.c

void			set_texture_size(t_cub3d *uwu);
void			pick_textures(t_cub3d *uwu, int egal, int type);
void			pick_textures2(t_cub3d *uwu, int egal);

// utils.c

void			set_angle(t_cub3d *uwu, char c);
int				is_player(char c);
int				get_pp(t_cub3d *uwu);
int				get_rgba(int r, int g, int b, int a);
int				is_etranger_restrained(char c);

// weapon.c

void			load_weapons(t_cub3d *uwu);
void			weapon_load(t_cub3d *uwu);
void			weapon_next_image(t_cub3d *uwu);
void			shoot(t_cub3d *uwu);
void			one_ray(t_cub3d *uwu);

// weapon2.c

void			portal_load(t_cub3d *uwu);
void			display_weapon(t_cub3d *uwu);
void			change_weapon(t_cub3d *uwu);
void			delete_weapons(t_cub3d *uwu);

#endif // CUB3D_H
