/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:13:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 13:51:55 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->turn_d = 0;
	player->walk_d = 0;
	player->lateral_d = 0;
	player->rot_ang = 0;
	player->mov_speed = 1;
	player->rot_speed = 0;
}

/*
** After each movement. Determine the new position of our player.
** Knowing our player rotation angle and lenght of his step. We can find x & y
** with cos and sin.
*/

int		check_ennemy(t_cub *cub)
{
	int x;
	int y;
	int num_position;

	y = -1;
	while (++y < cub->data.rows)
	{
		x = -1;
		while (cub->grid[y][++x])
		{
			if (ft_strchr("X", cub->grid[y][x]))
			{
				pos_player(&cub->ennemy, x, y, cub->grid[y][x]);
			}
		}
	}
	return (1);
}


void	iprint_map(t_cub *cub)
{
	int i = 0;
	int j = 0;
	while(i < cub->data.rows)
	{
		j = 0;
		while(j < cub->data.cols)
		{
			printf("%c", cub->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}


void	update(t_cub *cub, t_player *player)
{
	int new_x;
	int new_y;

	player->old_pos.x = player->pos.x;
	player->old_pos.y = player->pos.y;
	cub->ennemy.old_pos.x = cub->ennemy.pos.x;
	cub->ennemy.old_pos.y = cub->ennemy.pos.y;
	new_x = player->pos.x +  player->lateral_d;
	new_y = player->pos.y - player->walk_d;
	if (!grid_is_wall(new_x, new_y, cub))
	{
		cub->total_action++;
		if(cub->grid[new_y][new_x] == 'E')
		{
			printf("END: You left in another dimension\n");
			end_cub(cub);
		}
		cub->grid[(int)player->pos.y][(int)player->pos.x] = '0';
		cub->grid[new_y][new_x] = 'P';
		cub->player.pos.x = new_x;
		cub->player.pos.y = new_y;
	}
	check_ennemy(cub);
	if(cub->ennemy_limit_move == 0)
		cub->ennemy_limit_move = 4;
	if (cub->ennemy_limit_move == 4)
		cub->ennemy.orientation = rand()%(5-1);
	if(cub->ennemy.orientation == 0 && cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x - 1] == '0')
	{
		cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x - 1] = 'X';
		if(cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] != 'P')
			cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.x -= 1;
	}
	else if(cub->ennemy.orientation == 1 && cub->grid[cub->ennemy.pos.y + 1][cub->ennemy.pos.x] == '0')
	{
		cub->grid[cub->ennemy.pos.y + 1][cub->ennemy.pos.x] = 'X';
		if( cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] != 'P')
			cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.y += 1;
	}
	else if(cub->ennemy.orientation == 2 && cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x + 1] == '0')
	{
		cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x + 1] = 'X';
		if(cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] != 'P')
			cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.x += 1;
	}
	else if(cub->ennemy.orientation == 3 && cub->grid[cub->ennemy.pos.y - 1][cub->ennemy.pos.x] == '0')
	{
		cub->grid[cub->ennemy.pos.y - 1][cub->ennemy.pos.x] = 'X';
		if(cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] != 'P')
			cub->grid[cub->ennemy.pos.y][cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.y -= 1;
	}
	cub->ennemy_limit_move--;
	if((new_x == cub->ennemy.old_pos.x && new_y == cub->ennemy.old_pos.y) && (cub->ennemy.pos.x == player->old_pos.x && cub->ennemy.pos.y == player->old_pos.y))
	{
		printf("GAME OVER: The Weird Wizard found you\n");
		end_cub(cub);
	}
	//printf("Total action : %d", cub->total_action);
}

/*
** Save player pos & orientation in our structure
*/

void	pos_player(t_player *player, int x, int y, char orientation)
{
	if (player->pos.x == -1 && player->pos.y == -1)
	{
		player->pos.x = x;
		player->pos.y = y;
		if (orientation == 'N')
			player->rot_ang = 1.5 * M_PI;
		else if (orientation == 'S')
			player->rot_ang = M_PI / 2;
		else if (orientation == 'E')
			player->rot_ang = 0;
		else if (orientation == 'W')
			player->rot_ang = M_PI;
		player->rot_ang = 0;
	}
}

/*
** After filling the map. We are looking at if there is only one player pos
** & find his orientation.
*/

int		check_player(t_cub *cub)
{
	int x;
	int y;
	int num_position;

	y = -1;
	num_position = 0;
	while (++y < cub->data.rows)
	{
		x = -1;
		while (cub->grid[y][++x])
		{
			if (ft_strchr("P", cub->grid[y][x]))
			{
				pos_player(&cub->player, x, y, cub->grid[y][x]);
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
