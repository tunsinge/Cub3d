/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:31 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/04 10:03:14 by mdoumi           ###   ########.fr       */
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

# define OPEN_ERROR "Error\nOpen failed.\n"
# define INV_ARGS "Error\n1 Argument is required.\n"
# define ETRANGER_ERROR "Error\nInvalid character in map.\n"
# define INVALID_LINE "Error\nInvalid line in file"

typedef struct s_case
{
	char	value;
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
	char		**map;
	t_textures	textures;
	mlx_t		*mlx;
	t_case		***tab;
}	t_cub3d;


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

#endif // CUB3D_H
