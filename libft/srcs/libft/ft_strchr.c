/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:16:53 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 15:21:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	while (s2[i])
	{
		if (s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	if (s2[i] == c)
		return (&s2[i]);
	return (NULL);
}
