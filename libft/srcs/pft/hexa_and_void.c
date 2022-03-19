/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_and_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:01:42 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/21 14:32:16 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_start(unsigned int nb, char *hash, t_info *info)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	if (!(nb == 0 && info->precision == 0))
		len = ft_len_nbr_unsign(nb, "0123456789ABCDEF");
	if (len < info->precision)
		len = info->precision;
	if (nb != 0 && info->hastag == TRUE)
		len += 2;
	if (info->minus == FALSE && info->precision == -1 && info->zero == FALSE)
		count += ft_width(len, info->width, info->zero);
	else if (info->minus == FALSE && info->zero == FALSE)
		count += ft_width(len, info->width, FALSE);
	if (nb != 0 && info->hastag == TRUE)
		count += ft_putstr_fd(hash, 1);
	if (info->minus == FALSE && info->precision == -1 && info->zero == TRUE)
		count += ft_width(len, info->width, info->zero);
	len = ft_len_nbr_unsign(nb, "0123456789ABCDEF");
	while (len++ < info->precision)
		count += ft_putchar_fd('0', 1);
	return (count);
}

int	ft_format_xup(unsigned int nb, t_info *info)
{
	int	count;

	count = ft_print_start(nb, "0X", info);
	if (!(nb == 0 && info->precision == 0))
		count += ft_putnbr_unsign_base(nb, "0123456789ABCDEF");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}

int	ft_format_x(unsigned int nb, t_info *info)
{
	int	count;

	count = ft_print_start(nb, "0x", info);
	if (!(nb == 0 && info->precision == 0))
		count += ft_putnbr_unsign_base(nb, "0123456789abcdef");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}

static int	ft_putstr_null_address(t_info *info)
{
	int	count;

	count = 3;
	if (info->minus == FALSE)
		count += ft_width(count, info->width, FALSE);
	ft_putstr_fd("0x0", 1);
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}

int	ft_format_p(void *ad, t_info *info)
{
	int						count;
	unsigned long long int	nb;

	if (!ad)
		return (ft_putstr_null_address(info));
	nb = (unsigned long long int)ad;
	count = ft_len_nbr_unsign(nb, "0123456789abcdef") + 2;
	if (info->minus == FALSE)
		count += ft_width(count, info->width, FALSE);
	ft_putstr_fd("0x", 1);
	ft_putnbr_unsign_base(nb, "0123456789abcdef");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}
