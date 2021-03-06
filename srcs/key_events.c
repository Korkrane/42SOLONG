/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/01 17:44:10 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	key_pressed(int key, t_sl *sl)
{
	if (key == KEY_Z || key == KEY_UP || key == KEY_W)
		sl->player.walk_d = 1;
	else if (key == KEY_S || key == KEY_DOWN)
		sl->player.walk_d = -1;
	else if (key == KEY_Q || key == KEY_A || key == KEY_LEFT)
	{
		sl->player.orientation = 1;
		sl->player.lateral_d = -1;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		sl->player.orientation = 0;
		sl->player.lateral_d = 1;
	}
	else if (key == KEY_ESC)
		end_sl(sl);
	update(sl, &sl->player);
	render(sl);
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
