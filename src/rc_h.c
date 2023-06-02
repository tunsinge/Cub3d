/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:28:46 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/26 12:02:23 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal(t_cub3d *uwu)
{
	t_ray	*n;

	((void)0, n = uwu->ray, n->dof = 0, n->hx = n->px);
	((void)0, n->hy = n->py, n->a_tan = -1 / tan(n->ra));
	if (n->ra > PI)
	{
		n->ry = (((int)n->py / 8) * 8) - 0.0001;
		n->rx = (n->py - n->ry) * n->a_tan + n->px;
		n->yo = -8;
		n->xo = -n->yo * n->a_tan;
	}
	else if (n->ra < PI)
	{
		n->ry = (((int)n->py / 8) * 8) + 8;
		n->rx = (n->py - n->ry) * n->a_tan + n->px;
		n->yo = 8;
		n->xo = -n->yo * n->a_tan;
	}
	else
	{
		n->ry = n->py;
		n->rx = n->px;
		n->dof = MAX_DOF;
	}
	horizontal2(uwu);
}

void	horizontal2(t_cub3d *uwu)
{
	t_ray	*n;

	n = uwu->ray;
	while (n->dof < MAX_DOF)
	{
		n->mx = (int)(n->rx) / 8;
		n->my = (int)(n->ry) / 8;
		if (n->mx >= 0 && n->my >= 0 && n->mx < uwu->map_s_x
			&& n->my < uwu->map_s_y
			&& (uwu->map[n->my][n->mx] == '1' || uwu->map[n->my][n->mx] == '4'))
		{
			if (uwu->map[n->my][n->mx] == '4')
				uwu->ray->is_door = 1;
			n->hx = n->rx;
			n->hy = n->ry;
			n->dis_h = dist(n->px, n->py, n->hx, n->hy);
			n->dof = MAX_DOF;
		}
		else
		{
			n->rx += n->xo;
			n->ry += n->yo;
			n->dis_h = 1000000;
			n->dof++;
		}
	}
}
