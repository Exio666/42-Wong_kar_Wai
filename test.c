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

#define D_ESCAPE 27
#define D_NCURS_SIGINT 3
#define HEIGHT 35
#define WIDTH 100

int g_resize = 0;

void handler_size_term(int signal)
{
	g_resize = 1;
}



int main()
{
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
	while (1)
	{
		i = getch();      
       
		if (g_resize == 1)
		{
			printf("Resize\n\r");
			g_resize = 0;
		}
		if (i == KEY_LEFT)
			printf("Left\n\r");
		else if (i == KEY_RIGHT)
			printf("Right\n\r");
		else if (i == KEY_UP)
			printf("up\n\r");
		else if (i == KEY_DOWN)
			printf("Down\n\r");
		else if (i == D_ESCAPE || i == D_NCURS_SIGINT)
		{
			printf("Esc\n\r");
			endwin();
			delscreen(win);
			exit(0);
		}
		/*else
			printf("getch %i\n\r",i );*/
	}
	endwin();
}