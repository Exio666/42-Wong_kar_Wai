/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:50:36 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/21 13:50:38 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(int len, int with, bool zero)
{
	int	count;

	count = 0;
	with -= len;
	while (with > 0 && zero == FALSE)
	{
		write(1, " ", 1);
		with--;
		count++;
	}
	while (with > 0 && zero == TRUE)
	{
		write(1, "0", 1);
		with--;
		count++;
	}
	return (count);
}

void	ft_flush_info(t_info *info)
{	
	info->hastag = FALSE;
	info->plus = FALSE;
	info->space = FALSE;
	info->zero = FALSE;
	info->minus = FALSE;
	info->negative = FALSE;
	info->width = -1;
	if (info->hastag == FALSE)
		info->precision = -1;
}

int	ft_first_flag(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (ft_strchr("# +0-", (int)str[i]))
	{
		if (str[i] == '#' && info->hastag == FALSE)
			info->hastag = TRUE;
		if (str[i] == ' ')
			info->space = TRUE;
		if (str[i] == '+')
			info->plus = TRUE;
		if (str[i] == '0')
			info->zero = TRUE;
		if (str[i] == '-')
			info->minus = TRUE;
		i++;
	}
	return (i);
}

void	ft_feed_info(t_info *info, va_list arg, char *str)
{
	int	i;

	i = 1;
	i += ft_first_flag(&str[i], info);
	if ((!ft_strchr("cspdiuxX%", str[i])) && str[i] != '.')
	{
		if (str[i] != '*')
			info->width = ft_atoi(&str[i]);
		else
			info->width = va_arg(arg, int);
		while (ft_isdigit(str[i]) == 1)
			i++;
	}
	if (str[i] == '.')
	{
		if (str[++i] != '*')
			info->precision = ft_atoi(&str[i]);
		else
			info->precision = va_arg(arg, int);
		while (ft_isdigit(str[i]) == 1)
			i++;
		info->zero = FALSE;
	}
	info->conversion = str[i];
	info->index = info->index + i + 1;
}
