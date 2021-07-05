/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:18:48 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 16:47:18 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

/*
** Check if [y,x] position is a wall or not.
*/

int	grid_is_wall(int x, int y, t_sl *sl)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x > sl->win.wid || y < 0 || y > sl->win.hei)
		return (1);
	grid_x = floor(x);
	grid_y = floor(y);
	if (grid_x >= sl->data.cols || grid_y >= sl->data.rows)
		return (1);
	if (sl->grid[grid_y][grid_x] == '1')
		return (1);
	else
		return (0);
}

void	set_old_position(t_sl *sl, t_player *player)
{
	player->old_pos.x = player->pos.x;
	player->old_pos.y = player->pos.y;
	sl->ennemy.old_pos.x = sl->ennemy.pos.x;
	sl->ennemy.old_pos.y = sl->ennemy.pos.y;
}
