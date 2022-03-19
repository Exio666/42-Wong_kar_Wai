/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:54:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/19 16:56:20 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

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