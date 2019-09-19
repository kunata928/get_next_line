/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:47:13 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 18:53:18 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *str, size_t n)
{
	size_t len;

	len = 0;
	while (len < n && str[len])
		len++;
	return (len);
}

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2 || ft_len(s1, n) != ft_len(s2, n))
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (0);
		i++;
	}
	return (1);
}
