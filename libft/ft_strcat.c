/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:27:58 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 16:53:53 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int d;
	int s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s])
	{
		dest[d + s] = src[s];
		s++;
	}
	dest[d + s] = '\0';
	return (dest);
}
