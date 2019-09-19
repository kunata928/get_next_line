/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:08:47 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/14 17:34:39 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_LONG_LONG 9223372036854775807

static int	ft_blank(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t'
			|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long		res;
	int						sign;
	static unsigned long	i;

	res = 0;
	sign = 1;
	i = 0;
	while (*str && (ft_blank(*str)))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (unsigned long long)(res * 10 + (*(str++) - '0'));
		if (res > (long long)MAX_LONG_LONG && sign == 1)
			return (-1);
		if (res > (long long)MAX_LONG_LONG && sign == -1)
			return (0);
		i++;
	}
	return (int)(res * sign);
}
