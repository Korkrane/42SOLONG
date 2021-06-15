/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:58:31 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/10 23:47:06 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	render_mini_map(t_cub *cub)
{
	int		i;
	int		j;
	t_pos	pos;

	i = -1;
	while (++i < cub->data.rows)
	{
		j = -1;
		while (cub->grid[i][++j])
		{
			pos.x = MINIMAP_SCALE * j;
			pos.y = MINIMAP_SCALE * i;
			if (cub->grid[i][j] == '0' || cub->grid[i][j] == '2')
				square(pos, MINIMAP_SCALE, cub, GRAY);
			else
				square(pos, MINIMAP_SCALE, cub, GREEN);
		}
	}
}

void	render_mini_player(t_cub *cub)
{
	
	t_line	tmp;
	t_line	central;
	int		i;

	i = -1;
	central.start.x = cub->rays[cub->win.wid / 2].line.start.x;
	central.start.y = cub->rays[cub->win.wid / 2].line.start.y;
	central.end.x = cub->rays[cub->win.wid / 2].line.end.x;
	central.end.y = cub->rays[cub->win.wid / 2].line.end.y;
	
	/*
	while (++i < cub->win.wid)
	{
		tmp.start.x = cub->rays[i].line.start.x + (cub->win.wid * 0.01);
		tmp.start.y = cub->rays[i].line.start.y + (cub->win.hei * 0.03);
		tmp.end.x = cub->rays[i].line.end.x + (cub->win.wid * 0.01);
		tmp.end.y = cub->rays[i].line.end.y + (cub->win.hei * 0.03);
		render_line(&tmp, cub, V_GRAY);
	}
	*/
	render_line(&central, cub, WHITE);
}

void	render_mini_sprt(t_cub *cub)
{
	/*
	int		i;
	int		j;
	t_pos	pos;

	i = -1;
	while (++i < cub->data.rows)
	{
		j = -1;
		while (cub->grid[i][++j])
		{
			pos.x = MINIMAP_SCALE * j;
			pos.y = MINIMAP_SCALE * i;
			if (cub->grid[i][j] == '2')
				square(pos, MINIMAP_SCALE, cub, BLUE);
		}
	}
	*/
}
