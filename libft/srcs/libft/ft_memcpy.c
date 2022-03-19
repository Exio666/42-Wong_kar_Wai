/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:13:55 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 11:25:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*bd;
	unsigned char	*bs;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	bd = (unsigned char *)dest;
	bs = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		bd[i] = bs[i];
		i++;
	}
	return (dest);
}
