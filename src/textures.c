/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:58:14 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2023/05/17 14:58:14 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_textures *textures)
{
	textures->text_no = mlx_load_png(textures->texture_no);
	if (!textures->text_no)
		return (error(LOADING_TEXTURE_ERROR), 1);
	textures->text_so = mlx_load_png(textures->texture_so);
	if (!textures->text_so)
		return (error(LOADING_TEXTURE_ERROR), 1);
	textures->text_ea = mlx_load_png(textures->texture_ea);
	if (!textures->text_ea)
		return (error(LOADING_TEXTURE_ERROR), 1);
	textures->text_we = mlx_load_png(textures->texture_we);
	if (!textures->text_we)
		return (error(LOADING_TEXTURE_ERROR), 1);
	return (0);
}

void	delete_textures(t_textures *textures)
{
	mlx_delete_texture(textures->text_no);
	mlx_delete_texture(textures->text_so);
	mlx_delete_texture(textures->text_ea);
	mlx_delete_texture(textures->text_we);
}

int	pixel_to_color(mlx_texture_t *text, int x, int y)
{
	uint8_t		*pixel;
	uint32_t	color;

	if (!text)
		return (0x000000FF);
	if (x < 0 || x > text->width || y < 0 || y > text->height)
		return (0x000000FF);
	pixel = &text->pixels[(y * text->width + x) * text->bytes_per_pixel];
	color = (pixel[0] << 24) + (pixel[1] << 16) + (pixel[2] << 8) + pixel[3];
	return (color);
}
