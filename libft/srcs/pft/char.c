/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:53:15 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/21 13:51:34 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_null(t_info *info)
{
	int	count;
	int	len;

	count = 0;
	len = 6;
	if (info->precision < 6 && info->precision != -1)
		len = 0;
	if (info->minus == FALSE)
		count += ft_width(len, info->width, FALSE);
	if (len == 6)
	{
		count += ft_putstr_fd("(null)", 1);
	}
	if (info->minus == TRUE)
		count += ft_width(len, info->width, FALSE);
	return (count);
}

int	ft_format_c(char c, t_info *info)
{
	int	count;

	count = 1;
	if (info->minus == FALSE)
		count += ft_width(1, info->width, FALSE);
	write(1, &c, 1);
	if (info->minus == TRUE)
		count += ft_width(1, info->width, FALSE);
	return (count);
}

int	ft_format_s(char *str, t_info *info)
{
	int	i;
	int	len;
	int	count;

	if (!str)
		return (ft_putstr_null(info));
	i = 0;
	count = 0;
	len = ft_strlen(str);
	if (len > info->precision && info->precision != -1)
		len = info->precision;
	if (info->minus == FALSE)
		count += ft_width(len, info->width, FALSE);
	while (str[i] && (i < len || len == -1))
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (info->minus == TRUE)
		count += ft_width(len, info->width, FALSE);
	return (i + count);
}
