/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:11:15 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/09 23:21:41 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ch_s;

	i = 0;
	ch_s = (char *)s;
	while (i < n)
	{
		if (ch_s[i] == (char)c)
			return (&ch_s[i]);
		i++;
	}
	return (NULL);
}
