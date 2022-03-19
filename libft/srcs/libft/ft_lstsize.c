/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:26:00 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:52 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	if (!lst)
		return (0);
	i = 1;
	tmp = lst->next;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_dlistsize(t_dlist *lst)
{
	int		i;
	t_dlist	*tmp;

	if (!lst)
		return (0);
	i = 1;
	tmp = lst->next;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
