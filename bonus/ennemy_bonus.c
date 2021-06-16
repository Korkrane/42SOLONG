/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:15:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 16:45:06 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	update_ennemy_x(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->ennemy.pos.x;
	y = cub->ennemy.pos.y;
	if (cub->ennemy.orientation == 0
		&& (cub->grid[y][x - 1] == '0' || cub->grid[y][x - 1] == 'P'))
	{
		cub->grid[y][x - 1] = 'X';
		if (cub->grid[y][x] != 'P')
			cub->grid[y][x] = '0';
		cub->ennemy.pos.x -= 1;
	}
	else if (cub->ennemy.orientation == 2
		&& (cub->grid[y][x + 1] == '0' || cub->grid[y][x + 1] == 'P'))
	{
		cub->grid[y][x + 1] = 'X';
		if (cub->grid[y][x] != 'P')
			cub->grid[y][x] = '0';
		cub->ennemy.pos.x += 1;
	}
}

static void	update_ennemy_y(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->ennemy.pos.x;
	y = cub->ennemy.pos.y;
	if (cub->ennemy.orientation == 1
		&& (cub->grid[y + 1][x] == '0' || cub->grid[y + 1][x] == 'P'))
	{
		cub->grid[y + 1][x] = 'X';
		if (cub->grid[y][x] != 'P')
			cub->grid[y][x] = '0';
		cub->ennemy.pos.y += 1;
	}
	else if (cub->ennemy.orientation == 3
		&& (cub->grid[y - 1][x] == '0' || cub->grid[y - 1][x] == 'P'))
	{
		cub->grid[y - 1][x] = 'X';
		if (cub->grid[y][x] != 'P')
			cub->grid[y][x] = '0';
		cub->ennemy.pos.y -= 1;
	}
}

int	check_ennemy(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->data.rows)
	{
		x = -1;
		while (cub->grid[y][++x])
		{
			if (ft_strchr("X", cub->grid[y][x]))
			{
				pos_player(&cub->ennemy, x, y);
			}
		}
	}
	if (cub->ennemy_limit_move == 0)
		cub->ennemy_limit_move = 4;
	if (cub->ennemy_limit_move == 4)
		cub->ennemy.orientation = rand() % (5 - 1);
	update_ennemy_x(cub);
	update_ennemy_y(cub);
	cub->ennemy_limit_move--;
	return (1);
}
