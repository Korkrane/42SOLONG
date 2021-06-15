/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:13:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/15 18:04:53 by bahaas           ###   ########.fr       */
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
}


void	update(t_cub *cub, t_player *player)
{
	float new_x;
	float new_y;

	iprint_map(cub);
	new_x = player->pos.x +  player->lateral_d;
	new_y = player->pos.y - player->walk_d;
	if (!grid_is_wall(new_x, new_y, cub))
	{
		cub->grid[(int)player->pos.y][(int)player->pos.x] = '0';
		cub->grid[(int)new_y][(int)new_x] = 'P';
		cub->player.pos.x = new_x;
		cub->player.pos.y = new_y;
		cub->total_action++;
	}
	check_ennemy(cub);
	if(cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x - 1] == '0')
	{
		cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x - 1] = 'X';
		cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.x -= 1;
		cub->ennemy.orientation = 0;
	}
	else if(cub->grid[(int)cub->ennemy.pos.y + 1][(int)cub->ennemy.pos.x] == '0')
	{
		cub->grid[(int)cub->ennemy.pos.y + 1][(int)cub->ennemy.pos.x] = 'X';
		cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.y += 1;
		cub->ennemy.orientation = 1;
	}
	else if(cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x + 1] == '0')
	{
		cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x + 1] = 'X';
		cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.x += 1;
		cub->ennemy.orientation = 2;
	}
	else if(cub->grid[(int)cub->ennemy.pos.y - 1][(int)cub->ennemy.pos.x] == '0')
	{
		cub->grid[(int)cub->ennemy.pos.y - 1][(int)cub->ennemy.pos.x] = 'X';
		cub->grid[(int)cub->ennemy.pos.y][(int)cub->ennemy.pos.x] = '0';
		cub->ennemy.pos.y -= 1;
		cub->ennemy.orientation = 3;
	}
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
