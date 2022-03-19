/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:40 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*first;

	first = *alst;
	new->next = first;
	*alst = new;
}

void	ft_dlistadd_front(t_dlist **alst, t_dlist *new)
{
	t_dlist	*first;

	first = *alst;
	new->next = first;
	first->back = new;
	*alst = new;
}
