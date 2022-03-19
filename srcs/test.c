/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:01:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 12:03:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <all_lib.h>

#define D_ESCAPE 27
#define D_NCURS_SIGINT 3
#define HEIGHT 35
#define WIDTH 100

int render(int board[4][4]);

int g_resize = 0;

void handler_size_term(int signal)
{
	g_resize = 1;
}

int main()
{
	int board[4][4];
	ft_bzero(&board, sizeof(int) * 16);
	int i;
	void *win;
	int	y;
	int	x;
	i = 0;
	win = initscr();
	keypad(win, TRUE);
	raw();
	nodelay(win, TRUE);
	noecho();
	//box(stdscr, 0, 0);
	signal(28, handler_size_term);
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
			ft_printf("Left\n\r");
		else if (i == KEY_RIGHT)
			ft_printf("Right\n\r");
		else if (i == KEY_UP)
			ft_printf("up\n\r");
		else if (i == KEY_DOWN)
			ft_printf("Down\n\r");
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
