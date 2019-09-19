/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:59:47 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:03:03 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cnt_words(const char *s, char c)
{
	int count;
	int word;

	count = 0;
	word = 0;
	if (!s)
		return (0);
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
