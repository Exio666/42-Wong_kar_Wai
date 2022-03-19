/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:24 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast(*alst);
	tmp->next = new;
}

void	ft_dlistadd_back(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_dlistlast(*alst);
	tmp->next = new;
	new->back = tmp;
}
