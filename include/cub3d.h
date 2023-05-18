/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:31 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/18 03:02:21 by mdoumi           ###   ########.fr       */
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

# define WHI 0xFFFFFFFF
# define BLA 0x000000FF
# define RED 0xFF0000FF
# define GRE 0x00FF00FF
# define BLU 0x0000FFFF
# define CYA 0x00FFFFFF
# define YEL 0xFFFF00FF
# define PIN 0xFF00FFFF

# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174533

# define OPEN_ERROR "Error\nOpen failed.\n"
# define INV_ARGS "Error\n1 Argument is required.\n"
# define ETRANGER_ERROR "Error\nInvalid character in map.\n"
# define INVALID_LINE "Error\nInvalid line in file.\n"

typedef struct s_textures
{
	char	*texture_no;
	char	*texture_so;
	char	*texture_ea;
	char	*texture_we;
	int		color_fl;
	int		color_ce;
}	t_textures;

typedef struct s_ray
{
	float	pdx;
	float	pdy;
}	t_ray;

typedef struct s_cub3d
{
	int			i;
	int			j;
	float		p_x;
	float		p_y;
	float		pa;
	int			m_size;
	int			p_size;
	int			p_color;
	char		**map;
	t_textures	*textures;
	t_ray		*ray;
	mlx_t		*mlx;
	mlx_image_t	*player_img;
}	t_cub3d;

void	init_player(t_cub3d *uwu);
void	raycaster(t_cub3d *uwu);
int		ft_strlen(char *str);
int		ft_strrlen(char **str);
void	check_map(char **map);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
char	**parse_map(t_cub3d *uwu, char *path);
void	*error(char *code);
char	**append_to_map(char *line, char **map);
void	quit_program(void);
void	parse_textures(t_cub3d *uwu, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strdup(char *s1);
mlx_image_t	*fill(mlx_t *mlx, int w, int h, uint32_t color);
void		render_map(t_cub3d *uwu);
mlx_image_t	*color_chart(t_cub3d *uwu, char value);
void		render_player(t_cub3d *uwu);
int			get_rgba(int r, int g, int b, int a);
void		get_pp(t_cub3d *uwu);
void		check_map_path(char **av);
int			ft_atoi(char *str);
void		store_texture(t_cub3d *uwu, char **fields);
char		*ft_strdupnonl(char *s1);

#endif // CUB3D_H
