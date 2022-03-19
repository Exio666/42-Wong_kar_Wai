/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:52:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/15 14:41:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_porcent(t_info *info)
{
	int	count;

	count = 1;
	if (info->minus == FALSE)
		count += ft_width(1, info->width, info->zero);
	ft_putchar_fd('%', 1);
	if (info->minus == TRUE)
		count += ft_width(1, info->width, FALSE);
	return (count);
}

int	ft_select_format(char *str, va_list arg, t_info *info)
{
	ft_flush_info(info);
	ft_feed_info(info, arg, str);
	if (info->conversion == 'c')
		return (ft_format_c(va_arg(arg, int), info));
	else if (info->conversion == 's')
		return (ft_format_s(va_arg(arg, char *), info));
	else if (info->conversion == 'p')
		return (ft_format_p(va_arg(arg, void *), info));
	else if (info->conversion == 'd' || info->conversion == 'i')
		return (ft_format_d(va_arg(arg, long int), info));
	else if (info->conversion == 'u')
		return (ft_format_u(va_arg(arg, unsigned int), info));
	else if (info->conversion == 'x')
		return (ft_format_x(va_arg(arg, unsigned int), info));
	else if (info->conversion == 'X')
		return (ft_format_xup(va_arg(arg, unsigned int), info));
	else if (info->conversion == '%')
		return (ft_format_porcent(info));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_info	*info;
	int		counter;

	va_start (arg, str);
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->index = 0;
	counter = 0;
	while (str[info->index])
	{
		if (str[info->index] == '%')
			counter += ft_select_format((char *)&str[info->index], arg, info);
		else
		{
			ft_putchar_fd(str[info->index], 1);
			info->index++;
			counter++;
		}
	}
	va_end(arg);
	free(info);
	return (counter);
}
