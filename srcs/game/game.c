/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:00:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 16:01:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int playable(int board[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] == 0)
				return (true);
			for (int k = j; k < 4; ++k)
			{
				if (board[i][j] == board[i][k] || board[i][j] == board[k][j])
					return (true);
			}
		}
	}
	return (false);
}

int is_full(int board[4][4])
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

int player_won(int board[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] >= 2048)
				return (true);
		}
	}
	return (false);
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

void	join_up(int tab[4][4])
{
	int x1;
	int x2;
	int y;
	
	y = 0;
	while (y < 4)
	{
		x1 = 0;
		x2 = 1;
		while (x2 < 4 || x1 < 4)
		{
			while (tab[x1][y] == 0 && x1 < 4)
				x1++;
			x2 = x1 + 1;
			if (x1 >= 4 || x2 >= 4)
				break;
			while (tab[x2][y] == 0 && x2 < 4)
				x2++;
			if (x1 >= 4 || x2 >= 4)
				break;
			if (tab[x2][y] == tab[x1][y] && tab[x2][y] != 0)
			{
				tab[x1][y] = 2 * tab[x1][y];
				tab[x2][y] = 0;
			}
			x1 = x2;
		}
		y++;
	}	
}


void	join_down(int tab[4][4])
{
	int x1;
	int x2;
	int y;
	
	y = 0;
	while (y < 4)
	{
		x1 = 3;
		x2 = 2;
		while (x2 >= 0 || x1 >= 0)
		{
			while (tab[x1][y] == 0 && x1 >= 0)
				x1--;
			x2 = x1 - 1;
			if (x1 < 0 || x2 < 0)
				break;
			while (tab[x2][y] == 0 && x2 >= 0)
				x2--;
			if (x1 < 0 || x2 < 0)
				break;
			if (tab[x2][y] == tab[x1][y] && tab[x2][y] != 0)
			{
				tab[x1][y] = 2 * tab[x1][y];
				tab[x2][y] = 0;
			}
			x1 = x2;
		}
		y++;
	}	
}

void	join_left(int tab[4][4])
{
	int y1;
	int y2;
	int x;
	
	x = 0;
	while (x < 4)
	{
		y1 = 0;
		y2 = 1;
		while (y2 < 4 || y1 < 4)
		{
			while (tab[x][y1] == 0 && y1 < 4)
				y1++;
			y2 = y1 + 1;
			if (y1 >= 4 || y2 >= 4)
				break;
			while (tab[x][y2] == 0 && y2 < 4)
				y2++;
			if (y1 >= 4 || y2 >= 4)
				break;
			if (tab[x][y2] == tab[x][y1] && tab[x][y2] != 0)
			{
				tab[x][y1] = 2 * tab[x][y1];
				tab[x][y2] = 0;
			}
			y1 = y2;
		}
		x++;
	}	
}

void	join_right(int tab[4][4])
{
	int y1;
	int y2;
	int x;
	
	x = 0;
	while (x < 4)
	{
		y1 = 3;
		y2 = 2;
		while (y2 >= 0 || y1 >= 0)
		{
			while (tab[x][y1] == 0 && y1 >= 0)
				y1--;
			y2 =y1 - 1;
			if (y1 < 0 || y2 < 0)
				break;
			while (tab[x][y2] == 0 && y2 >= 0)
				y2--;
			if (y1 < 0 || y2 < 0)
				break;
			if (tab[x][y2] == tab[x][y1] && tab[x][y2] != 0)
			{
				tab[x][y1] = 2 * tab[x][y1];
				tab[x][y2] = 0;
			}
			y1 = y2;
		}
		x++;
	}	
}

void	deplace_down(int tab[4][4])
{
	int stock[4];
	int y;
	int x;
	int i;

	y = 3;
	while (y >= 0)
	{
		ft_bzero(stock, 4 * sizeof(int));
		x = 3;
		i = 3;
		while (x >= 0)
		{
			if (tab[x][y] != 0)
			{
				stock[i] = tab[x][y];
				i--;
			}
			x--;
		}
		x = 3;
		i = 3;
		while (x >= 0)
		{
			tab[x][y] = stock[i];
			i--;
			x--;
		}
		y--;
	}
	
}

void	deplace_right(int tab[4][4])
{
	int stock[4];
	int y;
	int x;
	int i;

	x = 3;
	while (x >= 0)
	{
		ft_bzero(stock, 4 * sizeof(int));
		y = 3;
		i = 3;
		while (y >= 0)
		{
			if (tab[x][y] != 0)
			{
				stock[i] = tab[x][y];
				i--;
			}
			y--;
		}
		y = 3;
		i = 3;
		while (y >= 0)
		{
			tab[x][y] = stock[i];
			i--;
			y--;
		}
		x--;
	}
	
}


void	deplace_up(int tab[4][4])
{
	int stock[4];
	int y;
	int x;
	int i;

	y = 0;
	while (y < 4)
	{
		ft_bzero(stock, 4 * sizeof(int));
		x = 0;
		i = 0;
		while (x < 4)
		{
			if (tab[x][y] != 0)
			{
				stock[i] = tab[x][y];
				i++;
			}
			x++;
		}
		x = 0;
		i = 0;
		while (x < 4)
		{
			tab[x][y] = stock[i];
			i++;
			x++;
		}
		y++;
	}
	
}

void	deplace_left(int tab[4][4])
{
	int stock[4];
	int y;
	int x;
	int i;

	x = 0;
	while (x < 4)
	{
		ft_bzero(stock, 4 * sizeof(int));
		y = 0;
		i = 0;
		while (y < 4)
		{
			if (tab[x][y] != 0)
			{
				stock[i] = tab[x][y];
				i++;
			}
			y++;
		}
		y = 0;
		i = 0;
		while (y < 4)
		{
			tab[x][y] = stock[i];
			i++;
			y++;
		}
		x++;
	}
	
}

void	do_action(int tab[4][4], int action)
{
	int before[4][4];
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
	if (ft_memcmp(before, tab, sizeof(int) * 16))
	{
		// Add new tile
	}
} 
