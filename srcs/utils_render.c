/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:22:51 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/01 17:29:35 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	fill_ratio_data(t_sl *sl, int i, int j)
{
	sl->data.sprt_hei = sl->win.hei / sl->data.rows;
	sl->data.sprt_wid = sl->win.wid / sl->data.cols;
	sl->data.top_px = i * sl->data.sprt_hei;
	sl->data.bot_px = (i + 1) * sl->data.sprt_hei;
	sl->data.right_px = sl->data.sprt_wid;
	sl->data.pos_x = j * (sl->win.wid / sl->data.cols);
	sl->data.screen.x = -1;
}

int	grep_color(t_text text, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > text.wid)
		x = text.wid;
	if (y > text.hei)
		y = text.hei;
	dst = text.data + (y * text.line_length + x * text.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

/*
** Render pixel on the image.
*/

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= win->wid && y >= 0 && y <= win->hei)
	{
		dst = win->img.addr + (y * win->img.line_length + x
				* (win->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
