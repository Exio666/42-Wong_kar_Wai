/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:02:34 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 15:24:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*s2;

	s2 = (char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
