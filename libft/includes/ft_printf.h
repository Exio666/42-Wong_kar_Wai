/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:18:18 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/21 15:06:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FALSE 0
# define TRUE 1

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

/*
 *	structure flag
 */

typedef struct s_info
{
	int		index;
	char	conversion;
	bool	hastag;
	bool	plus;
	bool	space;
	bool	zero;
	bool	minus;
	int		width;
	bool	negative;
	int		precision;
}	t_info;

/*
 *	ft_printf.c
 */

int		ft_select_format(char *str, va_list arg, t_info *info);
int		ft_printf(const char *str, ...);

/*
 *	char.c
 */

int		ft_format_c(char c, t_info *info);
int		ft_format_s(char *str, t_info *info);

/*
 *	hexa_and_void.c
 */

int		ft_format_xup(unsigned int nb, t_info *info);
int		ft_format_x(unsigned int nb, t_info *info);
int		ft_format_p(void *ad, t_info *info);

/*
 *	decimal.c
 */

int		ft_format_d(long int nb, t_info *info);
int		ft_format_u(unsigned int nb, t_info *info);

/*
 *	flag.c	
 */

void	ft_flush_info(t_info *info);
int		ft_first_flag(char *str, t_info *info);
void	ft_feed_info(t_info *info, va_list arg, char *str);
int		ft_width(int len, int with, bool zero);
char	*ft_make_strd(char *str1, t_info *info);
char	*ft_first_zero(int len, t_info *info);

#endif