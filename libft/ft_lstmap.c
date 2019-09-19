/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:01:12 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/15 16:51:34 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;

	if (!lst || !f)
		return ((t_list *)0);
	tmp = f(lst);
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp)
		{
			free(tmp->next);
			tmp->next = tmp;
		}
		tmp = tmp->next;
	}
	return (new);
}
