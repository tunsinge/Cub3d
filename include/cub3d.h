#ifndef CUB3D
# define CUB3D

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define OPEN_ERROR "Open failed."

int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
char	**map_to_tab(char *path);
void	*error(char *code);

#endif
