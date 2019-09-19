/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:05:02 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 16:54:21 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t d;
	size_t s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s] && s < nb)
	{
		dest[d + s] = src[s];
		s++;
	}
	dest[d + s] = '\0';
	return (dest);
}
