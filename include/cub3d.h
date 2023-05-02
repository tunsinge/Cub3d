/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:31 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/02 17:01:32 by ^@^ Foxan ^@^    ###   ########.fr       */
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
# define OPEN_ERROR "Open failed."

int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
char	**map_to_tab(char *path);
void	*error(char *code);
char	**append_to_map(char *line, char **map);

#endif // CUB3D_H
