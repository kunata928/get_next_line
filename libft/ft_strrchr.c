/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:16:44 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/07 22:45:51 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	cc;
	int		i;

	last = NULL;
	i = 0;
	cc = (char)c;
	if (!c)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s[i])
	{
		if (s[i] == cc)
			last = (char *)&(s[i]);
		i++;
	}
	if (s[i] == cc)
		last = (char *)&(s[i]);
	return (last);
}
