/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/07 18:28:17 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_dlist	*ft_dlistnew(void *content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->back = NULL;
	return (new);
}
