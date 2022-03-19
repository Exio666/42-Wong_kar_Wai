/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:36:10 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 13:45:14 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	if (neg == -1)
		nb = -nb;
	return (nb);
}

long int	ft_atoi_long(const char *nptr)
{
	long int	neg;
	int			i;
	long int	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	if (neg == -1)
		nb = -nb;
	return (nb);
}
