/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:01:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/20 11:21:14 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int g_resize = 0;

void handler_size_term(int signal)
{
	(void)signal;
	g_resize = 1;
}

int main()
{
	int board[4][4];
	int i;
	void *win;
	int 	Err;

	i = 0;
	Err = 1;
	win = initscr();
	if (!win)
		Err = -2;
	srand(time(NULL));
	if (Err == 0 || keypad(win, TRUE) || raw() || nodelay(win, TRUE) || noecho())
		Err = -1;
	signal(28, handler_size_term);
	init_tab(board);
	if (Err == 1)
		render(board);
	while (Err == 1)
	{
		i = getch();      
		if (g_resize == 1)
		{
			g_resize = 0;
			endwin();
			win = initscr();
			if (!win)
			{
				endwin();
				break ;
			}
			if (keypad(win, TRUE) || raw() || nodelay(win, TRUE) || noecho())
			{
				endwin();
				delscreen(win);
				break ;
			}
			render(board);
		}
		if (i == KEY_LEFT)
			do_action(board, i);
		else if (i == KEY_RIGHT)
			do_action(board, i);
		else if (i == KEY_UP)
			do_action(board, i);
		else if (i == KEY_DOWN)
			do_action(board, i);
		if (CONTINUE_WIN == 1 && player_won(board))
		{
			endwin();
			delscreen(win);
			ft_putstr_fd("You won !!!\nYour max bloc is : ", 1);
			ft_putnbr_fd(get_max(board), 1);
			ft_putchar_fd('\n', 1);
			break ;
		}
		if (i == D_ESCAPE || i == D_NCURS_SIGINT || !playable(board))
		{
			endwin();
			delscreen(win);
			if (player_won(board))
				ft_putstr_fd("You won !!!\n", 1);
			else 
				ft_putstr_fd("You lose !!!\n", 1);
			ft_putstr_fd("Your max bloc is : ", 1);
			ft_putnbr_fd(get_max(board), 1);
			ft_putchar_fd('\n', 1);
			break ;
		}
		if (i != -1)
			render(board);
		refresh();
	}
	if (Err == -1)
	{
		endwin();
		delscreen(win);
	}
}
