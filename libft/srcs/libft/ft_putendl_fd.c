/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:11:45 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/17 17:27:18 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	i = ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (i + 1);
}
