/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:56:45 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 15:22:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = ft_strlen(s);
	while (i != -1)
	{
		if (s2[i] == (unsigned char)c)
			return (&s2[i]);
		i--;
	}
	return (NULL);
}
