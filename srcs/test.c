/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:01:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 15:52:48 by bsavinel         ###   ########.fr       */
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
	//box(stdscr, 0, 0);
	signal(28, handler_size_term);
	init_tab(board);
	render(board);
	while (1)
	{
		i = getch();      
		if (g_resize == 1)
		{
			ft_printf("Resize\n\r");
			g_resize = 0;
			// delscreen(win);
			endwin();
			win = initscr();
			keypad(win, TRUE);
			raw();
			nodelay(win, TRUE);
			noecho();
		}
		else if (i == -1)
			continue;
		if (i == KEY_LEFT)
			do_action(board, i);
		else if (i == KEY_RIGHT)
			do_action(board, i);
		else if (i == KEY_UP)
			do_action(board, i);
		else if (i == KEY_DOWN)
			do_action(board, i);
		else if (i == D_ESCAPE || i == D_NCURS_SIGINT)
		{
			ft_printf("Esc\n\r");
			endwin();
			delscreen(win);
			exit(0);
		}
		/*else
			ft_printf("getch %i\n\r",i );*/
		render(board);
		refresh();
	}
	endwin();
}
