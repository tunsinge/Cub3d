/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:26 by ^@^ Foxan ^       #+#    #+#             */
/*   Updated: 2023/05/26 10:39:48 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	t_store			*store;
	char			*line;
	int				n;
	int				e;
	char			*ret;

	store = get_store(fd);
	if (store == NULL)
		return (NULL);
	line = NULL;
	n = reset_buffer(store);
	if (n == 0 || n == -1)
		return (NULL);
	store->start = store->pos;
	while (store->buff[store->pos] != '\n' && store->max)
	{
		store->pos++;
		ret = verify(&line, n, &e, store);
		if (e == 1)
			return (ret);
	}
	store->end = store->pos;
	line = save_line(store, line);
	store->pos += (line != NULL);
	return (line);
}

int	reset_buffer(t_store *store)
{
	if (store->pos >= store->max)
	{
		store->pos = 0;
		store->max = read(store->fd, &store->buff, BUFFER_SIZE);
		if (store->max == 0)
			return (0);
		if (store->max == -1)
			return (-1);
	}
	return (store->max);
}

char	*save_line(t_store *st, char *line)
{
	char	*tmp;
	int		len;

	if (line == NULL)
	{
		len = st->end - st->start + (st->pos < st->max);
		tmp = malloc((len + 1) * sizeof(char));
		if (tmp == NULL)
			return (NULL);
		ft_strlcpy(&(st->buff[st->start]), tmp, len);
	}
	else
	{
		len = ft_strlen(line) + st->end - st->start + (st->pos < st->max);
		tmp = malloc((len + 1) * sizeof(char));
		if (tmp == NULL)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(line, tmp, ft_strlen(line));
		ft_strlcat(&(st->buff[st->start]), tmp, len + 1);
		free(line);
	}
	return (tmp);
}

char	*verify(char **line, int n, int *e, t_store *store)
{
	*e = 0;
	if (store->pos >= store->max)
	{
		store->end = store->pos;
		*line = save_line(store, *line);
		n = reset_buffer(store);
		if (*line == NULL)
		{
			*e = 1;
			return (NULL);
		}
		if (n == 0)
		{
			*e = 1;
			return (*line);
		}
		if (n == -1)
		{
			*e = 1;
			free(*line);
			return (NULL);
		}
		store->start = store->pos;
	}
	return (NULL);
}

t_store	*get_store(int fd)
{
	static t_store	stores[4096] = {};

	if (!(0 <= fd && fd < 4096))
		return (NULL);
	if (stores[fd].fd != 0 && fd != 0)
		return (&stores[fd]);
	else if (fd == 0 && stores[fd].pos != BUFFER_SIZE)
		return (&stores[fd]);
	else
	{
		stores[fd].fd = fd;
		stores[fd].pos = BUFFER_SIZE;
		stores[fd].max = BUFFER_SIZE;
		stores[fd].start = 0;
		stores[fd].end = 0;
		return (&stores[fd]);
	}
}
