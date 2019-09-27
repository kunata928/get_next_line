/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/27 16:15:58 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_slice(char *str);
static int		free_all(char **line);


static int		free_all(char **line)
{
	if (*line)
		ft_memdel((void **)line);
	*line = NULL;
	return (0);
}

static int		new_fd(t_gnl **gnl, int fd, char **line)
{
	int len;

	if (((*gnl)->str = ft_strnew(BUFF_S)))
	{
		if (!(len = read(fd, (*gnl)->str, BUFF_S)))
			return (free_all(line));
		(*gnl)->str[len] = '\0';
		(*gnl)->fd = fd;
	}
	else
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int 			len;
	static t_gnl 	*gnl;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (!gnl)
		gnl = (t_gnl *)ft_memalloc(sizeof(gnl));
	if (gnl->fd != fd ) //in case new fd
	{
//		if ((gnl->str = ft_strnew(BUFF_S)))
//		{
//			if (!(len = read(fd, gnl->str, BUFF_S)))
//				return (free_all(line));
//			gnl->str[len] = '\0';
//			gnl->fd = fd;
//		}
//		else
//			return (0);
		return (new_fd(&gnl, fd, line));
	}
	while (!(ft_strchr(gnl->str, '\n')))
	{
		if (!(*line))
			*line = ft_strdup(gnl->str);
		else
			if (!(*line = ft_strjoin(*line, gnl->str)))
				return (-1);
		ft_memdel((void **)&(gnl->str));
		if ((gnl->str = ft_strnew(BUFF_S)))
		{
			if (!(len = read(fd, gnl->str, BUFF_S)))
				return (0);
			gnl->str[len] = '\0';
		}
		else
			return (free_all(line));
	}
	if (!(*line))
		*line = ft_strsub(gnl->str, 0, ft_strlen(gnl->str) - ft_strlen(ft_strchr(gnl->str, '\n')));
	else
		*line = ft_strjoin(*line, ft_strsub(gnl->str, 0, ft_strlen(gnl->str) - ft_strlen(ft_strchr(gnl->str, '\n'))));
	gnl->str = str_slice(gnl->str);
	return (1);
}

char	*str_slice(char *str)
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

int		main(int ac, char **av)
{

	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open("/Users/pmelodi/Projects/GetNextLine/war-and-peace.txt", O_RDONLY);
//		fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY);
		line = NULL;

		while (get_next_line(fd, &line))
		{
			ft_putendl(line);
			free(line);
			line = NULL;
		}
		ft_putendl(line);
		close(fd);
	}

}