/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 13:46:57 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_pressed(int key, t_cub *cub)
{
	if (key == KEY_Z || key == KEY_UP || key == KEY_W)
		cub->player.walk_d = 1;
	else if (key == KEY_S || key == KEY_DOWN)
		cub->player.walk_d = -1;
	else if (key == KEY_Q || key == KEY_A || key == KEY_LEFT)
	{
		cub->player.orientation = 1;
		cub->player.lateral_d = -1;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		cub->player.orientation = 0;
		cub->player.lateral_d = 1;
	}
	else if (key == KEY_ESC)
		end_cub(cub);
	update(cub, &cub->player);
	render_lol(cub);
	return (0);
}

int	key_released(int key, t_player *player)
{
	if (key == KEY_Z || key == KEY_S || key == KEY_UP
		|| key == KEY_DOWN || key == KEY_W)
		player->walk_d = 0;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		player->lateral_d = 0;
	else if (key == KEY_Q || key == KEY_D || key == KEY_A)
		player->lateral_d = 0;
	return (0);
}
