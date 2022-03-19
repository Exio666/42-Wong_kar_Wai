/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:14:14 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 11:40:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*bd;
	unsigned char	*bs;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	bd = (unsigned char *)dest;
	bs = (unsigned char *)src;
	if (((unsigned long int) src) <= ((unsigned long int) dest))
	{
		while (n)
		{
			bd[n - 1] = bs[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			bd[i] = bs[i];
	}
	return (dest);
}
