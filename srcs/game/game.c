/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:00:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 16:56:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

bool playable(int board[4][4])
{
	if (!is_full(board))
		return (true);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i + 1 < 4 && board[i][j] == board[i + 1][j])
				return (true);
			if (j + 1 < 4 && board[i][j] == board[i][j + 1])
				return (true);
		}
	}
	return (false);
}

bool is_full(int board[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] == 0)
				return (false);
		}
	}
	return (true);
}

bool player_won(int board[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] >= WIN_VALUE)
				return (true);
		}
	}
	return (false);
}

int get_max(int board[4][4])
{
	int max;

	max = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (max < board[i][j])
				max = board[i][j];
		}
	}
	return (max);
}

int choose_bloc()
{
	int nbr;
	
	nbr = rand();
	nbr = nbr % 10;
	if (nbr == 0)
		return (4);
	else
		return (2);	
}

int choose_place()
{
	int nbr;
	
	nbr = rand();
	nbr = nbr % 4;
	return (nbr);
}

void init_tab(int tab[4][4])
{
	int x;
	int y;
	int i;
	int x2;
	int y2;
	
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			tab[x][y] = 0;
			y++;
		}
		x++;
	}
	i = 0;
	x = choose_place();
	y = choose_place();
	tab[x][y] = choose_bloc();
	x2 = choose_place();
	y2 = choose_place();
	while (x == x2 && y == y2)
	{
		x2 = choose_place();
		y2 = choose_place();
	}
	tab[x2][y2] = choose_bloc();
}

void	do_action(int tab[4][4], int action)
{
	int before[4][4];
	int y;
	int x;

	ft_memcpy(before, tab, sizeof(int) * 16);
	if (action == KEY_UP)
		join_up(tab);
	else if (action == KEY_DOWN)
		join_down(tab);
	else if (action == KEY_LEFT)
		join_left(tab);
	else if (action == KEY_RIGHT)
		join_right(tab);
	if (action == KEY_UP)
		deplace_up(tab);
	else if (action == KEY_DOWN)
		deplace_down(tab);
	else if (action == KEY_LEFT)
		deplace_left(tab);
	else if (action == KEY_RIGHT)
		deplace_right(tab);
	if (ft_memcmp(before, tab, sizeof(int) * 16) && !is_full(tab))
	{
		x = choose_place();
		y = choose_place();
		while (tab[x][y] != 0)
		{
			x = choose_place();
			y = choose_place();
		}
		tab[x][y] = choose_bloc();
	}
} 
