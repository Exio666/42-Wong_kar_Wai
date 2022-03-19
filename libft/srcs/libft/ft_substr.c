/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:11:24 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 16:19:15 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_len_inf(void)
{
	char	*dest;

	dest = malloc(sizeof(char) * 1);
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	if (ft_strlen(s) < start)
		return (ft_len_inf());
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len && s[start])
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
