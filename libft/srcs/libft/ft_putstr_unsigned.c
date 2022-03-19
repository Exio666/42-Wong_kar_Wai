/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/06 12:39:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_unsigned_fd(unsigned char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_unsigned_fd(unsigned char *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		ft_putchar_unsigned_fd((unsigned char)s[i], fd);
		i++;
	}
	return (i);
}
