/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:46:08 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 16:57:47 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "all_lib.h"


/*
	If you won't to continue the game after the win you can take the value to 0
*/

#define CONTINUE_WIN 0

/*
	You can modify the win value
*/

typedef enum e_const
{
	WIN_VALUE = 2048
} t_const;

/*
 * Define
 */

#define D_ESCAPE 27
#define D_NCURS_SIGINT 3
#define HEIGHT 35
#define WIDTH 100

/*
 *	render.c
 */

int render(int board[4][4]);

/*
 *	game.c
 */

void	do_action(int tab[4][4], int action);
void 	init_tab(int tab[4][4]);
bool 	playable(int board[4][4]);
bool	is_full(int board[4][4]);
bool 	player_won(int board[4][4]);
int		get_max(int board[4][4]);

/*
 * join.c
 */

void	join_up(int tab[4][4]);
void	join_down(int tab[4][4]);
void	join_left(int tab[4][4]);
void	join_right(int tab[4][4]);

/*
 *	deplace.c
 */

void	deplace_down(int tab[4][4]);
void	deplace_right(int tab[4][4]);
void	deplace_up(int tab[4][4]);
void	deplace_left(int tab[4][4]);