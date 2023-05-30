/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:56:18 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/30 13:35:22 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	quit_program(t_cub3d *uwu)
{
	delete_textures(uwu->t);
	if (uwu->t->t_ea)
		free(uwu->t->t_ea);
	if (uwu->t->t_no)
		free(uwu->t->t_no);
	if (uwu->t->t_so)
		free(uwu->t->t_so);
	if (uwu->t->t_we)
		free(uwu->t->t_we);
	free(uwu->t);
	free(uwu->ray);
	if (uwu->map)
		free_s(uwu->map);
	free(uwu);
	if (uwu->mlx)
		mlx_terminate(uwu->mlx);
	exit(0);
}
