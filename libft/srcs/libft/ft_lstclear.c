/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:43 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/07 18:09:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp, del);
	}
}

void	ft_dlistclear(t_dlist **lst, void (*del)(void*))
{
	t_dlist	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_dlistdelone(tmp, del);
	}
}
