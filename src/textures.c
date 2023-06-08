/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:58:14 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/25 11:46:22 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures2(t_textures *t)
{
	t->door_no = mlx_load_png("./textures/door_no.png");
	if (!t->text_no)
		return (error(LOADING_TEXTURE_ERROR), 1);
	t->door_so = mlx_load_png("./textures/door_so.png");
	if (!t->text_so)
		return (error(LOADING_TEXTURE_ERROR), 1);
	t->door_ea = mlx_load_png("./textures/door_ea.png");
	if (!t->text_ea)
		return (error(LOADING_TEXTURE_ERROR), 1);
	t->door_we = mlx_load_png("./textures/door_we.png");
	if (!t->text_we)
		return (error(LOADING_TEXTURE_ERROR), 1);
	return (0);
}

int	load_textures(t_textures *t)
{
	t->text_no = mlx_load_png(t->t_no);
	if (!t->text_no)
		return (error(LOADING_TEXTURE_ERROR), 1);
	t->text_so = mlx_load_png(t->t_so);
	if (!t->text_so)
		return (error(LOADING_TEXTURE_ERROR), 1);
	t->text_ea = mlx_load_png(t->t_ea);
	if (!t->text_ea)
		return (error(LOADING_TEXTURE_ERROR), 1);
	t->text_we = mlx_load_png(t->t_we);
	if (!t->text_we)
		return (error(LOADING_TEXTURE_ERROR), 1);
	return (0);
}

void	delete_textures(t_textures *t)
{
	if (t->text_no)
		mlx_delete_texture(t->text_no);
	if (t->text_so)
		mlx_delete_texture(t->text_so);
	if (t->text_ea)
		mlx_delete_texture(t->text_ea);
	if (t->text_we)
		mlx_delete_texture(t->text_we);
	if (t->door_no)
		mlx_delete_texture(t->door_no);
	if (t->door_so)
		mlx_delete_texture(t->door_so);
	if (t->door_ea)
		mlx_delete_texture(t->door_ea);
	if (t->door_we)
		mlx_delete_texture(t->door_we);
}

int	pixel_to_color(t_cub3d *uwu, uint32_t x, uint32_t y, int rick)
{
	uint8_t		*pixel;
	uint32_t	color;

	if (rick)
		return (rick_pixel_to_color(uwu, x, y));
	if (!uwu->ray->t)
		return (0x000000FF);
	if (x > uwu->ray->t->width || y > uwu->ray->t->height)
		return (0x000000FF);
	pixel = &uwu->ray->t->pixels[(y * uwu->ray->t->width + x)
		* uwu->ray->t->bytes_per_pixel];
	color = (pixel[0] << 24) + (pixel[1] << 16) + (pixel[2] << 8) + pixel[3];
	return (color);
}
