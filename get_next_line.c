/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/28 00:13:45 by pmelodi          ###   ########.fr       */
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
		if (!(list->str = (void *)ft_memalloc(BUFF_S)))
			return (NULL);
		if (!(len = read(fd, list->str, BUFF_S)))
			return (NULL);
		list->str[len] = '\0';
//		ft_memcpy(list->str, content, BUFF_S);
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

	if (!str)
		return (NULL);
	if (!(len = ft_strlen(ft_strchr(str, '\n'))))
		return ("");
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, ft_strchr(str, '\n') + 1);
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
	ft_strdel(&tmp);
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
		if ((gnl->str = ft_strnew(BUFF_S)))
		{
			if (!(len = read(fd, gnl->str, BUFF_S)))
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

//static int		free_all(char **line)
//{
//	if (*line)
//		ft_memdel((void **)line);
//	*line = NULL;
//	return (0);
//}
//
//static int		new_fd(t_gnl *gnl, int fd, char **line)
//{
//	int len;
//
//	if ((gnl->str = ft_strnew(BUFF_S)))
//	{
//		if (!(len = read(fd, gnl->str, BUFF_S)))
//			return (free_all(line));
//		gnl->str[len]= '\0';
//		gnl->fd = fd;
//	}
//	else
//		return (0);
//	return (1);
//}
//
////}
//
//static t_list searh_list(size_t fd)
//{
//	static t_list fd_list;
//	list;
//	while()
//	{
//		returhb
//	}
//	list = lstnew("", fd);
//	ft_lstadd(&fd_list, list);
//	return (list);
//}
//
//int				get_next_line(const int fd, char **line)
//{
//	int 			len;
//	static t_list 	*gnl;
//
//	fd_list = searh_list(fd)';
//
//	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
//		return (-1);
//	if (!gnl)
//		gnl = (t_gnl *)ft_memalloc(sizeof(gnl));
//	if (gnl->fd != fd )
//	{//in case new fd
//		if ((gnl->content = ft_strnew(BUFF_S)))
//		{
//			if (!(len = read(fd, gnl->content, BUFF_S)))
//				return (free_all(line));
//			gnl->content[len] = '\0';
//			gnl->fd = fd;
//		}
//		else
//			return (0);
//	}//return (new_fd(gnl, fd, line));
//
//	while (!(ft_strchr(gnl->content, '\n')))
//	{
//		if (!(*line))
//			*line = ft_strdup(gnl->content);
//		else
//			if (!(*line = ft_strjoin(*line, gnl->content)))
//				return (free_all(line));
//		ft_memdel((void **)&(gnl->content));
//		if ((gnl->content = ft_strnew(BUFF_S)))
//		{
//			if (!(len = read(fd, gnl->content, BUFF_S)))
//				return (0);
//			gnl->content[len] = '\0';
//		}
//		else
//			return (free_all(line));
//	}
//	if (!(*line))
//		*line = ft_strsub(gnl->str, 0, ft_strlen(gnl->str) - ft_strlen(ft_strchr(gnl->str, '\n')));
//	else
//		*line = ft_strjoin(*line, ft_strsub(gnl->str, 0, ft_strlen(gnl->str) - ft_strlen(ft_strchr(gnl->str, '\n'))));
//	gnl->str = str_slice(gnl->str);
//	return (1);
//}
//
//static char		*str_slice(char *str)
//{
//	size_t	len;
//	char	*res;
//
//	if (!str)
//		return (NULL);
//	if (!(len = ft_strlen(ft_strchr(str, '\n'))))
//		return ("");
//	res = (char *)malloc(sizeof(char) * (len + 1));
//	if (!res)
//		return (NULL);
//	res = ft_strcpy(res, ft_strchr(str, '\n') + 1);
//	return (res);
//}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

//	ft_lstnew()
	if (ac == 2)
	{
		fd = open("/Users/pmelodi/Projects/GetNextLine/war-and-peace.txt", O_RDONLY);
//		fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY);
		line = NULL;

		int count = 0;
		while (get_next_line(fd, &line) && count < 5)
		{
			ft_putendl(line);
			free(line);
			line = NULL;
			count++;
		}

//		fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY);
//		line = NULL;
//
//		while (get_next_line(fd, &line))
//		{
//			ft_putendl(line);
//			free(line);
//			line = NULL;
//		}
//
//		count = 0;
//		fd = open("/Users/pmelodi/Projects/GetNextLine/war-and-peace.txt", O_RDONLY);
//		line = NULL;
//
//		while (get_next_line(fd, &line) && count < 10)
//		{
//			ft_putendl(line);
//			free(line);
//			line = NULL;
//			count++;
//		}
		while (1)
			;
		ft_putendl(line);
		close(fd);
	}
}