/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:54:53 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 16:55:20 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

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
