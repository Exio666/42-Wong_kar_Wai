/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:46:08 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 14:52:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "all_lib.h"

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