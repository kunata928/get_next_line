/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:41:35 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 17:35:24 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_blank(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	while (if_blank(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while (if_blank(s[len]) && len > 0)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
