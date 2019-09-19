/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:27:23 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/15 18:31:25 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wlen(const char *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static int		cw(const char *s, char c)
{
	int count;
	int word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (word == 1 && *s == c)
			word = 0;
		if (word == 0 && *s != c)
		{
			word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char		**ft_free(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_strdel(&(arr[i++]));
	free(arr);
	arr = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		w;

	i = 0;
	w = 0;
	if (!s || !(res = (char **)malloc(sizeof(char *) * (cw(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!(res[w] = (char *)malloc((ft_wlen(s + i, c) + 1))))
				return (ft_free(res, w));
			res[w] = ft_strncpy(res[w], s + i, (size_t)ft_wlen(s + i, c));
			res[w++][ft_wlen(s + i, c)] = '\0';
			i += ft_wlen(s + i, c);
		}
	}
	res[w] = 0;
	return (res);
}
