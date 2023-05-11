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
