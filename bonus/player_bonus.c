/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:13:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/17 20:14:28 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->walk_d = 0;
	player->lateral_d = 0;
	player->orientation = 0;
}

void	valid_move(t_cub *cub, int new_x, int new_y, t_player *player)
{
	if (cub->grid[new_y][new_x] == 'C')
		cub->data.collect_number--;
	if (cub->grid[new_y][new_x] == 'E' && cub->data.collect_number == 0)
	{
		printf("\nEND: You left in another dimension\n");
		end_cub(cub);
	}
	else if (cub->grid[new_y][new_x] == 'E' && cub->data.collect_number > 0)
		printf("\nBro... don't leave without all the food...\n");
	else
	{
		cub->total_action++;
		cub->grid[player->pos.y][player->pos.x] = '0';
		cub->grid[new_y][new_x] = 'P';
		cub->player.pos.x = new_x;
		cub->player.pos.y = new_y;
	}
}

void	update(t_cub *cub, t_player *player)
{
	int	new_x;
	int	new_y;

	set_old_position(cub, player);
	new_x = player->pos.x + player->lateral_d;
	new_y = player->pos.y - player->walk_d;
	if (!grid_is_wall(new_x, new_y, cub))
	{
		valid_move(cub, new_x, new_y, player);
		printf("Moves: %d\n", cub->total_action);
	}
	check_ennemy(cub);
	if (((new_x == cub->ennemy.old_pos.x && new_y == cub->ennemy.old_pos.y)
			&& (cub->ennemy.pos.x == player->old_pos.x
				&& cub->ennemy.pos.y == player->old_pos.y))
		|| (new_x == cub->ennemy.pos.x && new_y == cub->ennemy.pos.y))
	{
		printf("\nGAME OVER: The Weird Wizard found you\n");
		end_cub(cub);
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

int	check_player(t_cub *cub)
{
	int	x;
	int	y;
	int	num_position;

	y = -1;
	num_position = 0;
	while (++y < cub->data.rows)
	{
		x = -1;
		while (cub->grid[y][++x])
		{
			if (ft_strchr("P", cub->grid[y][x]))
			{
				pos_player(&cub->player, x, y);
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
