/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/26 20:42:38 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_slice(char *str);

static size_t 	len_str_n(const char *str)
{
	int len;

	len = 0;
	while (str[len] && (str[len] != '\n'))
		len++;
	return (len);
}

static int		free_all(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int 			len;
	static t_gnl 	*gnl;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (!gnl)
		gnl = (t_gnl *)ft_memalloc(sizeof(gnl));
	if (gnl->fd != fd ) //in case new fd
	{
		if ((gnl->str = ft_strnew(BUFF_SIZE)))
		{
			if (!(len = read(fd, gnl->str, BUFF_SIZE)))
				return (free_all(line));
			gnl->str[len] = '\0';
			gnl->fd = fd;
		}
		else
			return (free_all(line));
	}
	while (!(ft_strchr(gnl->str, '\n')) )
	{
		if (!(*line))
			*line = ft_strdup(gnl->str);
		else
			if (!(*line = ft_strjoin(*line, gnl->str)))
				return (-1);
		free(gnl->str);
		if ((gnl->str = ft_strnew(BUFF_SIZE)))
		{
			if (!(len = read(fd, gnl->str, BUFF_SIZE)))
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
	ft_putendl(*line);
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
		//fd = open("/Users/pmelodi/Projects/GetNextLine/war-and-peace.txt", O_RDONLY);
		fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY);
		line = NULL;

		while (get_next_line(fd, &line))
		{
			free(line);
			line = NULL;
		}
		ft_putendl(line);
		close(fd);
	}

}