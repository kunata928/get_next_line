/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:12:27 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 16:42:29 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmpd;
	char *tmps;

	tmpd = (char *)dst;
	tmps = (char *)src;
	if (tmps < tmpd)
	{
		while (len--)
			tmpd[len] = tmps[len];
	}
	else
		ft_memcpy(tmpd, tmps, len);
	return (dst);
}
