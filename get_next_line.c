/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/10/02 00:17:11 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*gnl_new(int fd)
{
	t_gnl	*list;

	if (!(list = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	list->str = "\0";
	list->fd = fd;
	list->next = NULL;
	return (list);
}

static t_gnl	*find_fd(int fd)
{
	t_gnl			*list;
	static t_gnl	*gnl = NULL;

	list = gnl;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (!list)
		list = gnl_new(fd);
	list->next = gnl;
	gnl = list;
	return (list);
}

static char		*str_slice(char *str)
{
	size_t	len;
	char	*res;
	size_t 	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(ft_strchr(str, '\n')))
		len = 0;
	else
		len = ft_strlen(ft_strchr(str, '\n'));
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = ft_strchr(str, '\n')[i + 1];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char		*add_line(char **line, char *s)
{
	int len;

	if (!(ft_strchr(s, '\n')))
		len = 0;
	else
		len = ft_strlen(ft_strchr(s, '\n'));
	*line = ft_strsub(s, 0, ft_strlen(s) - len);
	return (str_slice(s));
}

int				get_next_line(const int fd, char **line)
{
	int		len;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	t_gnl	*gnl;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	gnl = find_fd(fd);
	*line = NULL;
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		tmp = gnl->str;
		gnl->str = ft_strjoin(gnl->str, buff);
		ft_strdel(&tmp);
		if (ft_strchr(buff, '\n'))
			break;
	}
	tmp = gnl->str;
	if (!ft_strlen(gnl->str))
	{
		ft_strdel(&tmp);
		return (0);
	}
	gnl->str = add_line(line, gnl->str);
	ft_strdel(&tmp);
	return (1);
}