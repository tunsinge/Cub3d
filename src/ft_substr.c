/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:05:45 by mdoumi            #+#    #+#             */
/*   Updated: 2023/05/01 23:13:12 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*rep;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		len = len + start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start < len)
		rep = malloc(sizeof(char) * (len - start + 1));
	else
		rep = malloc(sizeof(char));
	if (rep == NULL)
		return (NULL);
	i = start;
	while (i < len && s[i] != '\0')
	{
		rep[i - start] = s[i];
		i++;
	}
	rep[i - start] = '\0';
	return (rep);
}
