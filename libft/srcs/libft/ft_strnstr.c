/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:17:40 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 11:47:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	a;
	size_t	b;

	i = 0;
	x = 0;
	if (!little[i])
		return ((char *)&big[x]);
	while (big[x] && little[i] && x < len)
	{
		a = x;
		b = i;
		while (big [a] == little [b] && big[a] && a < len)
		{
			if (little[b + 1] == '\0')
				return ((char *)&big[x]);
			a++;
			b++;
		}
		i = 0;
		x++;
	}
	return (NULL);
}
