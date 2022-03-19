/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:00 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 14:54:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	temp;
	size_t	i;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	temp = len_dest;
	if (size <= len_dest)
		return (len_src + size);
	while (src[i] != '\0' && temp < size - 1)
	{
		dst[temp] = src[i];
		i++;
		temp++;
	}
	dst[temp] = '\0';
	return (len_dest + len_src);
}
