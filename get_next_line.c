/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/22 22:11:45 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_slice(char **str);

//static int 	read_buf()
//{
//	int i;
//
//	i = 0;
//	return (i);
//}

static size_t 	len_str_n(const char *str)
{
	int len;

	len = 0;
	while (str[len] && (str[len] != '\n'))
		len++;
	return (len);
}

static int		lst_pushback(t_listn **list_b, char *buf, size_t size)
{
	if (!(*list_b = ft_lstnew(buf, len_str_n(buf))))
		return (0);
	return (1);
}

int		fill_line(char **line, t_list *list_b)
{

	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char 	*str_buf;
	int 			a;

	if (!fd || !line)
		return (-1);
	if (*str_buf)
	{
		*line = ft_strsub(str_buf, 0, ft_strlen(str_buf) - ft_strlen(ft_strchr(buf, '\n')));
		str_buf = str_slice(&str_buf);
	}
	while ((a = read(fd, buf, BUFF_SIZE)))
	{
		buf[a] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strjoin(*line, ft_strsub(buf, 0, BUFF_SIZE + 1 - ft_strlen(ft_strchr(buf, '\n'))));
			str_buf = str_slice(&buf);
		}
		else
			*line = ft_strjoin(*line, buf);
	}
	return ();
}

char	*str_slice(char **str)
{
	size_t	len;
	char	*res;

	if (!str)
		return (NULL);
	if (!(len = ft_strlen(ft_strchr(*str, '\n'))))
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, ft_strchr(*str, '\n') + 1);
}

int		main(int ac, char **av)
{

	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}
		close(fd);
	}

}