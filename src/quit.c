/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:56:18 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/25 11:43:26 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	quit_program(t_cub3d *uwu)
{
	delete_textures(uwu->t);
	if (uwu->mlx)
		mlx_terminate(uwu->mlx);
//	system("leaks cub3d");
	exit(0);
}
