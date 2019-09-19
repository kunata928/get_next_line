/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <pmelodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:11:45 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/19 22:11:45 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "unistd.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);

#endif
