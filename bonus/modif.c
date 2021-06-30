/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:23:58 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/30 15:30:30 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

/*
** Render pixel on the image.
*/

/*
void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= win->wid && y >= 0 && y <= win->hei)
	{
		dst = win->img.addr + (y * win->img.line_length + x *
				(win->img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
*/

/*
** Grep pixel color of text pos and check if it's part of the txt or not.
** Display it if it's the case.
*/

/*
void	sprt_color(t_cub *cub, t_pos text, t_pos pos, int i)
{
	int		color;
	int		background;

	color = grep_color(cub->text[4], text.x, text.y);
	background = grep_color(cub->text[4], 0, 0);
	if (color != background)
		my_mlx_pixel_put(&cub->win, cub->sprt[i].pos_x + pos.x, pos.y, color);
}
*/

/*
** pos is screen pos
** text is text pos
** If ray_dist > sprt dist allows us to check if the sprt is behind or in front
** of a wall. Then, we loop to render.
*/

/*
void	sprt_display(t_cub *cub, int i)
{
	t_pos	text;
	t_pos	pos;
	float	dist;

	pos.x = -1;
	while (cub->sprt[i].pos_x + pos.x < 0)
		pos.x++;
	while (++pos.x < cub->sprt[i].hei &&
			cub->sprt[i].pos_x + pos.x < cub->win.wid)
	{
		dist = cub->rays[(int)(cub->sprt[i].pos_x + pos.x)].dist;
		if (dist > cub->sprt[i].dist)
		{
			text.x = pos.x * cub->text[4].wid / cub->sprt[i].hei;
			pos.y = cub->sprt[i].top_px - 1;
			while (++pos.y < cub->sprt[i].bot_px)
			{
				text.y = (pos.y + (cub->sprt[i].hei / 2) -
					(cub->win.hei / 2)) * (cub->text[4].hei / cub->sprt[i].hei);
				if (text.y < 0)
					text.y = 0;
				sprt_color(cub, text, pos, i);
			}
		}
	}
}
*/

/*
** In the case where our sprite is visible. Just like walls render we need to
** determine his top + bot pixel & height. Then we'll display it to the screen.
** pos_x, determine where we should render the sprite on x axis.
*/

/*
void	fill_sprt_data(t_cub *cub)
{
	int		i;
	int		top_px;
	int		bot_px;

	i = -1;
	while (++i < cub->data.num_sprt)
	{
		if (cub->sprt[i].visibility)
		{
			cub->sprt[i].hei = cub->data.dist_pplane /
				(cos(cub->sprt[i].ang) * cub->sprt[i].dist);
			top_px = (cub->win.hei / 2) - (cub->sprt[i].hei / 2);
			bot_px = (cub->win.hei / 2) + (cub->sprt[i].hei / 2);
			if (top_px < 0)
				top_px = 0;
			if (bot_px > cub->win.hei)
				bot_px = cub->win.hei;
			cub->sprt[i].bot_px = bot_px;
			cub->sprt[i].top_px = top_px;
			cub->sprt[i].pos_x = cub->data.dist_pplane *
				tan(cub->sprt[i].ang) + (cub->win.wid / 2) -
				(cub->sprt[i].hei / 2);
			sprt_display(cub, i);
		}
	}
}
*/
