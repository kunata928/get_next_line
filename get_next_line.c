/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/28 16:55:44 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnlnew(char const *content, int fd)
{
	t_gnl	*list;
	int		len;

	len = 0;
	if (!(list = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	if (content)
	{
		if (!(list->str = (void *)ft_memalloc(BUFF_SIZE + 1)))
			return (NULL);
		if (!(len = read(fd, list->str, BUFF_SIZE)))
			return (NULL);
		list->str[len] = '\0';
		list->fd = fd;
	}
	else
	{
		list->str = NULL;
		list->fd = fd;
	}
	list->next = NULL;
	return (list);
}

static t_gnl	*find_fd(int fd)
{
	t_gnl			*begin;
	static t_gnl	*gnl = NULL;

	begin = gnl;
	while (begin)
	{
		if (begin->fd == fd)
			return (begin);
		begin = begin->next;
	}
	if (!begin)
		gnl = gnlnew("", fd);
	gnl->next = begin;
	begin = gnl;
	return (begin);
}

static char		*str_slice(char *str)
{
	size_t	len;
	char	*res;
	size_t 	i;
	char 	*chr;

	chr = ft_strchr(str, '\n');
	i = 0;
	if (!str)
		return (NULL);
	if (!(len = ft_strlen(chr)))
		return ("");
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = chr[i + 1];
		i++;
	}
	res[i] = '\0';
	//res = ft_strcpy(res, ft_strchr(str, '\n') + 1);
	return (res);
}

static void		add_line(char **line, char *s)
{
	char *tmp;

	tmp = *line;
	if (!(*line))
	{
		if (!(ft_strchr(s, '\n')))
			*line = ft_strdup(s);
		else
			*line = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '\n')));
	}
	else
		if (!(ft_strchr(s, '\n')))
			*line = ft_strjoin(*line, s);
		else
			*line = ft_strjoin(*line, ft_strsub(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '\n'))));
	if (*tmp)
		ft_strdel(&tmp);
//		free(tmp);
	return ;
}

int				get_next_line(const int fd, char **line)
{
	int		len;
	t_gnl	*gnl;
	char	*tmp;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	gnl = find_fd(fd);
	while (!(ft_strchr(gnl->str, '\n')))
	{
		add_line(line, gnl->str);
		ft_memdel((void **)&(gnl->str));
		if ((gnl->str = ft_strnew(BUFF_SIZE)))
		{
			if (!(len = read(fd, gnl->str, BUFF_SIZE)))
				return (0);
			gnl->str[len] = '\0';
		}
	}
	add_line(line, gnl->str);
	tmp = gnl->str;
	gnl->str = str_slice(gnl->str);
	ft_strdel(&tmp);
	//gnl->str = str_slice(gnl->str);
	return (1);
}