/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:16:49 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/16 15:30:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl
{
	char	*str;
	int		len_read;
	int		place_newline;
}	t_gnl;

/*
 *	get_next_line.c
 */

void	replace(char *buffer);
char	*get_line(char *buffer, int fd);
char	*ft_up_line(char *line, char *buffer);
char	*get_next_line(int fd);

/*
 *	get_next_line_utils.c
 */

int		sizeline(char *str);
int		no_newline(char *str);
char	*bug_malloc(char *line);

#endif