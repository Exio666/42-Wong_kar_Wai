/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:01:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 17:32:47 by bsavinel         ###   ########.fr       */
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
	i = 0;
	win = initscr();
	srand(time(NULL));
	keypad(win, TRUE);
	raw();
	nodelay(win, TRUE);
	noecho();
	signal(28, handler_size_term);
	init_tab(board);
	render(board);
	while (1)
	{
		i = getch();      
		if (g_resize == 1)
		{
			g_resize = 0;
			endwin();
			win = initscr();
			keypad(win, TRUE);
			raw();
			nodelay(win, TRUE);
			noecho();
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
			ft_printf("You won !!!\nYour max bloc is : %i\n", get_max(board));
			exit(0);
		}
		if (i == D_ESCAPE || i == D_NCURS_SIGINT || !playable(board))
		{
			endwin();
			delscreen(win);
			if (player_won(board))
				ft_printf("You won !!!\n");
			else 
				ft_printf("You lose !!!\n");
			ft_printf("Your max bloc is : %i\n", get_max(board));
			exit(0);
		}
		if (i != -1)
			render(board);
		refresh();
	}
	endwin();
}
