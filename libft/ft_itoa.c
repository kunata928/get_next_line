/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:48:42 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/13 23:43:46 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(long int n)
{
	return ((n < 0) ? -n : n);
}

char			*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			sign;
	long int	nn;

	nn = (long int)n;
	sign = (n < 0) ? -1 : 1;
	len = ft_numlen(nn);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = (ft_abs(nn)) % 10 + '0';
		nn = (ft_abs(nn)) / 10;
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
