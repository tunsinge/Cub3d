/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:56:05 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/11 09:56:06 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_s(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!('0' <= num[i] && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	store_color(t_cub3d *uwu, char **fields)
{
	char	**color;

	color = ft_split(fields[1], ',');
	if (ft_strrlen(color) != 3)
		return ((void)error(INVALID_COLOR_FORMAT), quit_program());
	if (!is_num(color[0]) || !is_num(color[1]) || !is_num(color[2]))
		return ((void)error(INVALID_COLOR_RGB_VALUE), quit_program());
	if (ft_strcmp(fields[0], "F") == 0 && !uwu->textures->color_fl)
		uwu->textures->color_fl = get_rgba(ft_atoi(color[0]), ft_atoi(color[1]),
				ft_atoi(color[2]), 255);
	else if (ft_strcmp(fields[0], "C") == 0 && !uwu->textures->color_ce)
		uwu->textures->color_ce = get_rgba(ft_atoi(color[0]), ft_atoi(color[1]),
				ft_atoi(color[2]), 255);
	else
		return ((void)error(INVALID_TEXTURES_CODE), quit_program());
}

void	store_texture(t_cub3d *uwu, char **fields)
{
	if (ft_strcmp(fields[0], "NO") == 0 && !uwu->textures->texture_no)
	{
		if (verify_texture(fields[1]))
			uwu->textures->texture_no = ft_strdupnonl(fields[1]);
	}
	else if (ft_strcmp(fields[0], "SO") == 0 && !uwu->textures->texture_so)
	{
		if (verify_texture(fields[1]))
			uwu->textures->texture_so = ft_strdupnonl(fields[1]);
	}
	else if (ft_strcmp(fields[0], "EA") == 0 && !uwu->textures->texture_ea)
	{
		if (verify_texture(fields[1]))
			uwu->textures->texture_ea = ft_strdupnonl(fields[1]);
	}
	else if (ft_strcmp(fields[0], "WE") == 0 && !uwu->textures->texture_we)
	{
		if (verify_texture(fields[1]))
			uwu->textures->texture_we = ft_strdupnonl(fields[1]);
	}
	else
		store_color(uwu, fields);
}

int	verify_texture(char *texture)
{
	int	len;

	len = ft_strlen(texture);
	if (len < 5)
		return (error(INVALID_TEXTURE_PATH), quit_program(), 0);
	if (!(texture[len - 4] == '.' && texture[len - 3] == 'p'
			&& texture[len - 2] == 'n' && texture[len - 1] == 'g'))
		return (error(INVALID_TEXTURE_FORMAT), quit_program(), 0);
	return (1);
}
