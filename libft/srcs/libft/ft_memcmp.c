/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:06:13 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/26 08:39:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	if (n <= 0)
		return (0);
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (src1[i] == src2[i] && i < n - 1)
		i++;
	return (src1[i] - src2[i]);
}
