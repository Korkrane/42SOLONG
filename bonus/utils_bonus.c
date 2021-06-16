/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:18:48 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 13:45:11 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** Check if [y,x] position is a wall or not.
*/

int	grid_is_wall(int x, int y, t_cub *cub)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x > cub->win.wid || y < 0 || y > cub->win.hei)
		return (1);
	grid_x = floor(x);
	grid_y = floor(y);
	if (grid_x >= cub->data.cols || grid_y >= cub->data.rows)
		return (1);
	if (cub->grid[grid_y][grid_x] == '1')
		return (1);
	else
		return (0);
}
