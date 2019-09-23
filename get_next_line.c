/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/23 21:24:38 by pmelodi          ###   ########.fr       */
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

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int 			a;
	static char 	*str_buf;
	static t_gnl 	*gnl;

	ft_putendl("hello");
	if (!gnl)
		gnl = (t_gnl *)ft_memalloc(sizeof(gnl));
	if (gnl->fd != fd)
	{
		gnl->str = ft_strnew(BUFF_SIZE);
		gnl->str[read(fd, gnl->str, BUFF_SIZE)] = '\0';
	}
	ft_putendl(gnl->str);
	ft_putendl("!");
//	str_buf = NULL;
//	if (!fd)
//		return (-1);
//	if (str_buf)
//	{
//		*line = ft_strsub(str_buf, 0, ft_strlen(str_buf) - ft_strlen(ft_strchr(buf, '\n')));
//		str_buf = str_slice(str_buf);
//	}
//	while ((a = read(fd, buf, BUFF_SIZE)));
//	{
//		buf[BUFF_SIZE] = '\0';
//		if (ft_strchr(buf, '\n'))
//		{
//			*line = ft_strjoin(*line, ft_strsub(buf, 0, BUFF_SIZE + 1 - ft_strlen(ft_strchr(buf, '\n'))));
//			str_buf = str_slice(buf);
//		}
//		else
//			*line = ft_strjoin(*line, buf);
//	}
	return (0);
}

char	*str_slice(char *str)
{
	size_t	len;
	char	*res;

	if (!str)
		return (NULL);
	if (!(len = ft_strlen(ft_strchr(str, '\n'))))
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, ft_strchr(str, '\n') + 1);
	return (str);
}

int		main(int ac, char **av)
{

	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY);
		get_next_line(fd, &line);
		printf("%s\n", line);
		/*while (get_next_line(fd, &line))
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}*/
		close(fd);
	}

}