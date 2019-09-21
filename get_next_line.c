/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:12:01 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/21 20:45:17 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	t_list *begin;

	begin = list_b;
	while (list_b)
	{
		*line = ft_strjoin((const char *)(*line), (const char *)(list_b->content));
		if (!(*line))
		{
			free(*line);
			line = NULL;
			return (ft_lstdel(begin, del));
		}
		list_b = list_b->next;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	t_list *list_b;
	int a;

	if (!fd || !line)
		return (-1);
	while ((a = read(fd, buf, BUFF_SIZE)))
	{
		buf[a] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			break;
		}
		else
		{
			if (!(lst_pushback(&list_b, buf, len_str_n(buf))))
				return (ft_lstdel(&list_b, del));
		}
	}
	return (fill_line(line, list_b));
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