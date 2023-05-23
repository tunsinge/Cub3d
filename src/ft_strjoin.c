/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:28:06 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/03/23 06:04:00 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	lenstr(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoinn(char *s1, char **str2)
{
	int		i;
	char	*final;
	char	*tmp;

	i = 1;
	final = ft_strjoin(s1, " ");
	tmp = ft_strjoin(final, str2[0]);
	free(final);
	while (str2[i])
	{
		final = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = ft_strjoin(final, str2[i]);
		free(final);
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc((lenstr(s1) + lenstr(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i] != 0)
	{
		res[lenstr(s1) + i] = s2[i];
		i++;
	}
	res[lenstr(s1) + lenstr(s2)] = 0;
	return (res);
}

char	*ft_strjoinfree(char **s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc((lenstr(*s1) + lenstr(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s1 && (*s1)[i] != 0)
	{
		res[i] = (*s1)[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i] != 0)
	{
		res[lenstr(*s1) + i] = s2[i];
		i++;
	}
	res[lenstr(*s1) + lenstr(s2)] = 0;
	free(*s1);
	*s1 = res;
	return (res);
}

char	*ft_strjoinnfree(char **s1, char **str2, char *sep)
{
	int		i;
	char	*final;

	i = 1;
	final = ft_strjoinfree(s1, sep);
	ft_strjoinfree(&final, str2[0]);
	if (!final)
		return (NULL);
	while (str2[i])
	{
		ft_strjoinfree(&final, sep);
		ft_strjoinfree(&final, str2[i]);
		i++;
	}
	return (final);
}

static int	lenstr(const char *str)
{
	int	len;

	len = 0;
	while (str && str[len] != 0)
		len++;
	return (len);
}
