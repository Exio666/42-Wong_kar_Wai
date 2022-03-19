/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:11:20 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 13:00:36 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_is_trim(s1[i], set))
		i++;
	if ((size_t)i == ft_strlen(s1))
	{
		dest = malloc(sizeof(char) * 1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	while (ft_is_trim(s1[j], set))
		j--;
	dest = ft_substr(s1, i, (j - i + 1));
	return (dest);
}
