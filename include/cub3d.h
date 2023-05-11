/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:31 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/04 12:36:33 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WHI 0xFFFFFFFF
# define BLA 0x000000FF
# define RED 0xFF0000FF
# define GRE 0x00FF00FF
# define BLU 0x0000FFFF
# define CYA 0x00FFFFFF
# define YEL 0xFFFF00FF
# define PIN 0xFF00FFFF
# define ALP 0x00000000

# define INVALID_PATH "Error\nMap is not valid. It must end with .cub.\n"
# define OPEN_ERROR "Error\nOpen failed.\n"
# define INV_ARGS "Error\n1 Argument is required.\n"
# define ETRANGER_ERROR "Error\nInvalid character in map.\n"
# define INVALID_LINE "Error\nInvalid line in file.\n"
# define NOT_CLOSED_MAP "Error\nMap is not closed\n"
# define INVALID_COLOR_FORMAT "Error\nInvalid color format in textures\n"
# define INVALID_COLOR_RGB_VALUE "Error\nInvalid color RGB value in textures\n"
# define INVALID_TEXTURES_CODE "Error\nInvalid or duplicate texture or color identifier in textures\n"

typedef struct s_case
{
	char		value;
	mlx_image_t	*img;
}	t_case;

typedef struct s_textures
{
	char	*texture_no;
	char	*texture_so;
	char	*texture_ea;
	char	*texture_we;
	int		color_fl;
	int		color_ce;
}	t_textures;

typedef struct s_cub3d
{
	int			i;
	int			j;
	int			p_x;
	int			p_y;
	int			case_size;
	int			player_size;
	int			map_s_x;
	int			map_s_y;
	char		**map;
	t_textures	*textures;
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	t_case		***tab;
}	t_cub3d;

int			ft_strlen(char *str);
int			ft_strrlen(char **str);
void		check_map(char **map);
char		*ft_substr(char *s, int start, int len);
int			ft_strcmp(char *s1, char *s2);
char		**parse_map(t_cub3d *uwu, char *path);
void		*error(char *code);
char		**append_to_map(char *line, char **map);
void		quit_program(void);
void		parse_textures(t_cub3d *uwu, int fd);
char		**ft_split(char const *str, char c);
char		*ft_strdup(char *s1);
mlx_image_t	*fill(mlx_t *mlx, int w, int h, uint32_t color);
void		render(t_cub3d *uwu);
mlx_image_t	*color_chart(t_cub3d *uwu, char value);
void		render_player(t_cub3d *uwu);
int			get_rgba(int r, int g, int b, int a);
void		get_pp(t_cub3d *uwu);
void		check_map_path(char **av);
t_case		***tab_to_struct(t_cub3d *uwu);
int			ft_atoi(char *str);
void		store_texture(t_cub3d *uwu, char **fields);
char		*ft_strdupnonl(char *s1);
int			check_map_closed(t_cub3d *uwu);
void		free_s(char **str);
int			is_num(char *num);

#endif // CUB3D_H
