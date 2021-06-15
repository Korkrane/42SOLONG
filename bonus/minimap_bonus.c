/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:58:31 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/11 12:46:49 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	render_mini_map(t_cub *cub)
{
	int		i;
	int		j;
	t_pos	pos;
	t_pos	next_pos;

	i = -1;
	while (++i < cub->data.rows)
	{
		j = -1;
		while (cub->grid[i][++j])
		{
			pos.x = cub->win.wid / cub->data.cols * j;
			pos.y = cub->win.hei / cub->data.rows * i;
			next_pos.x = cub->win.wid / cub->data.cols * (j + 1);
			next_pos.y = cub->win.hei / cub->data.rows * (i + 1);
			if (cub->grid[i][j] == '0' || cub->grid[i][j] == 'P')
				//square(pos, 50, cub, GRAY);
				rect(cub, pos, next_pos, GRAY);
			else if (cub->grid[i][j] == 'C')
				rect(cub, pos, next_pos, GREEN);
			else if (cub->grid[i][j] == 'E')
				rect(cub, pos, next_pos, V_GRAY);
			else
				rect(cub, pos, next_pos, BLUE);
				//square(pos, 50, cub, GREEN);
		}
	}
}

void	rect_player(t_cub *cub, t_pos a, t_pos b, int color)
{
	int	i;
	int	j;

	i = -1;
	while (a.x + ++i < b.x)
	{
		j = -1;
		while (a.y + ++j < b.y)
			my_mlx_pixel_put(&cub->win, a.x + i, a.y + j, color);
	}
}

void	render_mini_player(t_cub *cub)
{
	
	t_line	tmp;
	t_line	central;
	int		i;

	i = -1;
	/*
	central.start.x = cub->rays[cub->win.wid / 2].line.start.x;
	central.start.y = cub->rays[cub->win.wid / 2].line.start.y;
	central.end.x = cub->rays[cub->win.wid / 2].line.end.x;
	central.end.y = cub->rays[cub->win.wid / 2].line.end.y;
	*/
	t_pos actual_pos;
	t_pos next_pos;
	actual_pos.x = cub->player.pos.x * (cub->win.wid / cub->data.cols);
	actual_pos.y = cub->player.pos.y * (cub->win.hei / cub->data.rows);
	next_pos.x = (cub->player.pos.x + 1) * (cub->win.wid / cub->data.cols);
	next_pos.y = (cub->player.pos.y + 1) * (cub->win.hei / cub->data.rows);
	
	rect_player(cub, actual_pos, next_pos, WHITE);
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
	//render_line(&central, cub, WHITE);
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
