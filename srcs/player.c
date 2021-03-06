/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:13:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/07 19:56:04 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->walk_d = 0;
	player->lateral_d = 0;
	player->orientation = 0;
	player->print_move = 0;
}

void	valid_move(t_sl *sl, int new_x, int new_y, t_player *player)
{
	player->print_move = 0;
	if (sl->grid[new_y][new_x] == 'C')
		sl->data.collect_number--;
	if (sl->grid[new_y][new_x] == 'E' && sl->data.collect_number == 0)
	{
		printf("\nEND: You left in another dimension\n");
		end_sl(sl);
	}
	else if (sl->grid[new_y][new_x] == 'E' && sl->data.collect_number > 0)
	{
		player->print_move = 1;
		printf("Bro... don't leave without all the food...\n");
	}
	else
	{
		if ((sl->player.walk_d == 1 || sl->player.walk_d == -1)
			|| (sl->player.lateral_d == 1 || sl->player.lateral_d == -1))
			sl->total_action++;
		sl->grid[player->pos.y][player->pos.x] = '0';
		sl->grid[new_y][new_x] = 'P';
		sl->player.pos.x = new_x;
		sl->player.pos.y = new_y;
	}
}

void	update(t_sl *sl, t_player *player)
{
	int	new_x;
	int	new_y;

	set_old_position(sl, player);
	new_x = player->pos.x + player->lateral_d;
	new_y = player->pos.y - player->walk_d;
	if (!grid_is_wall(new_x, new_y, sl))
	{
		valid_move(sl, new_x, new_y, player);
		if (((sl->player.walk_d == 1 || sl->player.walk_d == -1)
				|| (sl->player.lateral_d == 1 || sl->player.lateral_d == -1))
			&& player->print_move != 1)
			printf("Moves: %d\n", sl->total_action);
	}
}

void	pos_player(t_player *player, int x, int y)
{
	if (player->pos.x == -1 && player->pos.y == -1)
	{
		player->pos.x = x;
		player->pos.y = y;
	}
}

int	check_player(t_sl *sl)
{
	int	x;
	int	y;
	int	num_position;

	y = -1;
	num_position = 0;
	while (++y < sl->data.rows)
	{
		x = -1;
		while (sl->grid[y][++x])
		{
			if (ft_strchr("P", sl->grid[y][x]))
			{
				pos_player(&sl->player, x, y);
				num_position++;
				if (num_position > 1)
					return (is_error("Multiple player position in map"));
			}
		}
	}
	if (num_position == 0)
		return (is_error("No player position in map"));
	return (1);
}
