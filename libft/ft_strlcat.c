/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:48:24 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 19:15:34 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t s;
	size_t i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (size)
	{
		if (size > d)
			s += d;
		else
			s += size;
		while (src[i] && d < (size - 1))
		{
			dst[d] = src[i];
			d++;
			i++;
		}
		dst[d] = '\0';
	}
	return (s);
}
