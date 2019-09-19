/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:57:10 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 16:40:24 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	cc;
	size_t			i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	cc = (unsigned char)c;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if (cc == s[i])
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
