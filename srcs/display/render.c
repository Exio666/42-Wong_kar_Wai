/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:01:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/20 10:47:33 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

static void print_divider_row(int box_w)
{
	ft_putstr_fd("+", 1);
	for (int i = 0; i < 4; ++i)
	{
		for (int col = 0; col < box_w; ++col)
		{
			ft_putstr_fd("-", 1);
		}
		ft_putstr_fd("+", 1);
	}
	ft_putstr_fd("\r\n", 1);
}

static int digits_in_int(int n)
{
	int i = 0;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

int render(int board[4][4])
{
	clear();
	refresh();
	int win_h, win_w;
	int box_h, box_w;
	int center_y, center_x;
	getmaxyx(stdscr, win_h, win_w);
	box_h = (win_h - 6) / 4;
	box_w = (win_w - 5) / 4;
	center_y = box_h / 2;
	center_x = box_w / 2;

	ft_putstr_fd("\r\n", 1);
	print_divider_row(box_w);
	
	for (int row = 0; row < 4; ++row)
	{
		for (int box_row = 0; box_row < box_h; ++box_row)
		{
			ft_putstr_fd("|", 1);
			for (int col = 0; col < 4; ++col)
			{
				for (int i = 0; i < box_w; ++i)
				{
					if (box_row == center_y && i == center_x - digits_in_int(board[row][col]) / 2 && board[row][col] != 0)
					{
						i += digits_in_int(board[row][col]);
						ft_putnbr_fd(board[row][col], 1);
						--i;
					}
					else
					{
						ft_putstr_fd(" ", 1);						
					}					
				}
				ft_putstr_fd("|", 1);
			}
			ft_putstr_fd("\r\n", 1);
		}
		print_divider_row(box_w);
	}
	refresh();
	return (0);
}
