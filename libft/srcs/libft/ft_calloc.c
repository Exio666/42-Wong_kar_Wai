/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:31:46 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 10:56:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = malloc(nmemb * size);
	if (!a)
		return (NULL);
	b = (char *)a;
	while (i < (nmemb * size))
	{
		b[i] = 0;
		i++;
	}
	return (a);
}
