/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:07 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/17 17:26:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long long int nbr, char *base)
{
	int				renv;
	long long int	type;

	renv = ft_len_nbr(nbr, base);
	type = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nbr;
	}
	if (nbr >= type)
	{
		ft_putnbr_base(nbr / type, base);
		nbr = nbr % type;
	}
	if (nbr < type)
		ft_putchar_fd(base[nbr], 1);
	return (renv);
}

int	ft_putnbr_unsign_base(unsigned long long int nbr, char *base)
{
	int						renv;
	unsigned long long int	type;

	renv = ft_len_nbr_unsign(nbr, base);
	type = ft_strlen(base);
	if (nbr >= type)
	{
		ft_putnbr_unsign_base(nbr / type, base);
		nbr = nbr % type;
	}
	if (nbr < type)
		ft_putchar_fd(base[nbr], 1);
	return (renv);
}

int	ft_len_nbr(long long int n, char *base)
{
	int				i;
	long long int	type;

	i = 1;
	type = ft_strlen(base);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > type - 1)
	{
		n = n / type;
		i++;
	}
	return (i);
}

int	ft_len_nbr_unsign(unsigned long long int n, char *base)
{
	int						i;
	unsigned long long int	type;

	i = 1;
	type = ft_strlen(base);
	while (n > type - 1)
	{
		n = n / type;
		i++;
	}
	return (i);
}
