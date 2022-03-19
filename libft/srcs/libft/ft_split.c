/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2021/11/29 12:53:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	counter;
	int	i;
	int	j;

	j = 0;
	i = 0;
	counter = 1;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			j++;
			counter++;
		}
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (counter);
}

static int	ft_len_word(char const *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (j);
		i++;
		j++;
	}
	return (j);
}

static char	*ft_input_word(char const *str, char c, int *i)
{
	char	*word;
	int		k;

	k = 0;
	word = malloc(sizeof(char) * (ft_len_word(str, c, *i) + 1));
	if (!word)
		return (NULL);
	while (str[*i] && str[*i] != c)
	{
		word[k] = str[*i];
		k++;
		(*i)++;
	}
	word[k] = '\0';
	return (word);
}

static char	**ft_free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**tab_word;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	tab_word = malloc(sizeof(char *) * ft_count_word(str, c));
	if (!tab_word)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			tab_word[j] = ft_input_word(str, c, &i);
		if (!tab_word[j++] && str[i])
			return (ft_free_tab(tab_word, j));
		while (str[i] && str[i] == c)
			i++;
	}
	j = ft_count_word(str, c) - 1;
	tab_word[j] = 0;
	return (tab_word);
}
