/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/30 00:14:21 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnlnew(int fd)
{
	t_gnl	*list;
	int		len;

	len = 0;
	if (!(list = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	list->str = (char *)malloc(sizeof(char));
	list->str = "\0";
	list->fd = fd;
//	}
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
		gnl = gnlnew(fd);
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
	if (!chr)
		len = 0;
	else
		len = ft_strlen(chr);
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
	int len;

	if (!(ft_strchr(s, '\n')))
		len = 0;
	else
		len = ft_strlen(ft_strchr(s, '\n'));
	*line = ft_strsub(s, 0, ft_strlen(s) - len);
	return ;
}

int				get_next_line(const int fd, char **line)
{
	int		len;
	char	*tmp;
	char	*buff;
	t_gnl	*gnl;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	gnl = find_fd(fd);
	if (!gnl)
		return (0);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		tmp = gnl->str;
		gnl->str = ft_strjoin(gnl->str, buff);
		ft_strdel(&tmp);
		if (ft_strchr(buff, '\n'))
			break;
		ft_strdel(&buff);
		if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (0);
	}
	ft_strdel(&buff);
	if (!ft_strlen(gnl->str))
		return (0);
	tmp = gnl->str;
	add_line(line, gnl->str);
	gnl->str = str_slice(gnl->str);
	ft_strdel(&tmp);
	return (1);
}

//int				get_next_line(const int fd, char **line)
//{
//	int		len;
//	char	**buff[BUFF_SIZE + 1];
//	t_gnl	*gnl;
//	//char	*tmp;
//
//	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
//		return (-1);
//	gnl = find_fd(fd);
//	if (!gnl)
//		return (0);
//	while (!(ft_strchr(gnl->str, '\n')))
//	{
//		//add_line(line, gnl->str);
//		if (!(*line))
//			*line = ft_strdup(gnl->str);
//		else
//			*line = ft_strjoin(*line, gnl->str);
//		ft_memdel((void **)&(gnl->str));
//		if ((gnl->str = ft_strnew(BUFF_SIZE)))
//		{
//			if (!(len = read(fd, gnl->str, BUFF_SIZE)))
//				return (1);
//			gnl->str[len] = '\0';
//		}
//	}
//	if (!(ft_strlen(gnl->str)))
//		return (0);
//	add_line(line, gnl->str);
//	//tmp = gnl->str;
//	gnl->str = str_slice(gnl->str);
//	//ft_strdel(&tmp);
//	//gnl->str = str_slice(gnl->str);
//	return (1);
//}


//static void		add_line(char **line, char *s)
//{
//	char *tmp;
//	int len;
//
//	if (!(ft_strlen(ft_strchr(s, '\n'))))
//		len = 0;
//	else
//		len = ft_strlen(ft_strchr(s, '\n'));
//	tmp = *line;
//
//	if (!(*line))
//		*line = ft_strsub(s, 0, ft_strlen(s) - len);
//	else
////		if (!(ft_strchr(s, '\n')))
////			*line = ft_strjoin(*line, s);
////		else
//		*line = ft_strjoin(*line, ft_strsub(s, 0, ft_strlen(s) - len));
////	ft_strdel(&tmp);
////		free(tmp);
//	return ;
//}