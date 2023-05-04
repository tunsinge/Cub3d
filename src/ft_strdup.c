/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:26:38 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/04/13 15:11:45 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}

char	**ft_strrdup(char **s1)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (ft_strrlen(s1) + 1));
	i = 0;
	while (s1[i])
	{
		res[i] = ft_strdup(s1[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_strrldup(char **s1, int l)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (l + 1));
	i = -1;
	while (s1[++i])
		res[i] = ft_strdup(s1[i]);
	i--;
	while (++i < l)
		res[i] = NULL;
	res[i] = NULL;
	return (res);
}

char	*ft_strdupnonl(char *s1)
{
	char	*s2;
	int		len;

	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	len = 0;
	while (s1[len] && s1[len] != '\n')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}

char	*ft_strldup(char *s1, int l)
{
	char	*s2;
	int		len;

	len = 0;
	while (s1[len] && len < l)
		len++;
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	len = 0;
	while (s1[len] && len < l)
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
