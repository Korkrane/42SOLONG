/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:15:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/23 12:33:36 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

static void	update_ennemy_x(t_sl *sl)
{
	int	x;
	int	y;

	x = sl->ennemy.pos.x;
	y = sl->ennemy.pos.y;
	if (sl->ennemy.orientation == 0
		&& (sl->grid[y][x - 1] == '0' || sl->grid[y][x - 1] == 'P'))
	{
		sl->grid[y][x - 1] = 'X';
		if (sl->grid[y][x] != 'P')
			sl->grid[y][x] = '0';
		sl->ennemy.pos.x -= 1;
	}
	else if (sl->ennemy.orientation == 2
		&& (sl->grid[y][x + 1] == '0' || sl->grid[y][x + 1] == 'P'))
	{
		sl->grid[y][x + 1] = 'X';
		if (sl->grid[y][x] != 'P')
			sl->grid[y][x] = '0';
		sl->ennemy.pos.x += 1;
	}
}

static void	update_ennemy_y(t_sl *sl)
{
	int	x;
	int	y;

	x = sl->ennemy.pos.x;
	y = sl->ennemy.pos.y;
	if (sl->ennemy.orientation == 1
		&& (sl->grid[y + 1][x] == '0' || sl->grid[y + 1][x] == 'P'))
	{
		sl->grid[y + 1][x] = 'X';
		if (sl->grid[y][x] != 'P')
			sl->grid[y][x] = '0';
		sl->ennemy.pos.y += 1;
	}
	else if (sl->ennemy.orientation == 3
		&& (sl->grid[y - 1][x] == '0' || sl->grid[y - 1][x] == 'P'))
	{
		sl->grid[y - 1][x] = 'X';
		if (sl->grid[y][x] != 'P')
			sl->grid[y][x] = '0';
		sl->ennemy.pos.y -= 1;
	}
}

int	check_ennemy(t_sl *sl)
{
	int	x;
	int	y;

	y = -1;
	while (++y < sl->data.rows)
	{
		x = -1;
		while (sl->grid[y][++x])
		{
			if (ft_strchr("X", sl->grid[y][x]))
				pos_player(&sl->ennemy, x, y);
		}
	}
	if (sl->ennemy_limit_move == 0)
		sl->ennemy_limit_move = 4;
	if (sl->ennemy_limit_move == 4)
		sl->ennemy.orientation = rand() % (5 - 1);
	if (sl->ennemy.pos.x != -1)
	{
		update_ennemy_x(sl);
		update_ennemy_y(sl);
	}
	sl->ennemy_limit_move--;
	return (1);
}
