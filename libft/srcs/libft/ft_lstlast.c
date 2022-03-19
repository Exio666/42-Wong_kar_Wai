/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:51 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_dlist	*ft_dlistlast(t_dlist *lst)
{
	t_dlist	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
