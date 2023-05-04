/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:58:49 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/04 15:01:02 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Juste faire une fonction qui dessine une droite avec un vecteur
//Donc la fonction prend un vecteur, va parcourir chaque pixel X, trouver son Y avec le vecteur en parametre
//avec mx+p, et trace un pixel au coo trouvees.
mlx_t		*mlx;
mlx_image_t	*img;

void	une_ligne(t_vector	*u)
{
	int		len;
	float	x;
	float	coeff;

	x = 0;
	coeff = u->y / u->x;
	len = 0;
	while (len < 50)
	{
		mlx_put_pixel(img, x, coeff * x, 0xFFFFFFFF);
		x += 1;
		len++;
	}
}

int	main()
{
	t_vector	*u;

	u = malloc(sizeof(t_vector));
	u->x = 1;
	u->y = 1;

	mlx = mlx_init(200, 200, "cub3d", true);
	img = mlx_new_image(mlx, 200, 200);

	for (int i = 0; i < 20; i++)
	{
		une_ligne(u);
		u->x++;
	}

	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
