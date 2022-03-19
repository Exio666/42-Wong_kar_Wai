/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:47:18 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/21 15:12:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_positive_nb(long int nb, t_info *info)
{
	if ((int)nb < 0)
	{
		info->negative = TRUE;
		nb = -nb;
	}
	return (nb);
}

static char	ft_signe(t_info *info)
{
	if (info->negative == TRUE)
		return ('-');
	else if (info->plus == TRUE)
		return ('+');
	else
		return (' ');
}

static char	*ft_first_zero2(char *str, t_info *info, int size, int len)
{
	str[size] = '\0';
	while ((info->zero == TRUE && info->precision == -1 && len < info->width
			&& info-> minus == FALSE) || len < info->precision)
	{
		str[--size] = '0';
		len++;
	}
	if (info->negative == TRUE || info->plus == TRUE || info->space == TRUE)
	{
		str[--size] = ft_signe(info);
		len++;
	}
	while (info->width >= len++ && size >= 1)
	{
		str[--size] = ' ';
	}
	return (str);
}

char	*ft_first_zero(int len, t_info *info)
{
	char	*str;
	int		size;

	size = -1;
	if ((info->negative == TRUE || info->plus == TRUE || info->space == TRUE)
		&& info->minus == FALSE)
		info->width--;
	if (info->minus == FALSE)
		size = info->width - len;
	if (size < info->precision - len)
		size = info->precision - len;
	if (size < 0)
		size = 0;
	if (info->negative == TRUE || info->plus == TRUE || info->space == TRUE)
		size++;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	return (ft_first_zero2(str, info, size, len));
}

int	ft_format_d(long int nb, t_info *info)
{
	char	*str1;
	char	*str3;
	int		len;

	len = 0;
	nb = ft_positive_nb(nb, info);
	if (!(nb == 0 && info->precision == 0))
		str1 = ft_itoa(nb);
	else
	{
		str1 = malloc(1);
		if (!str1)
			return (0);
		str1[0] = '\0';
	}
	str3 = ft_make_strd(str1, info);
	len += ft_putstr_fd(str3, 1);
	free(str3);
	if (info->minus == TRUE)
		len += ft_width(len, info->width, FALSE);
	return (len);
}
