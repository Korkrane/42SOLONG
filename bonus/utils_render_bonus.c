/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:22:51 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/01 17:21:36 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	fill_ratio_data(t_cub *cub, int i, int j)
{
	cub->data.sprt_hei = cub->win.hei / cub->data.rows;
	cub->data.sprt_wid = cub->win.wid / cub->data.cols;
	cub->data.top_px = i * cub->data.sprt_hei;
	cub->data.bot_px = (i + 1) * cub->data.sprt_hei;
	cub->data.right_px = cub->data.sprt_wid;
	cub->data.pos_x = j * (cub->win.wid / cub->data.cols);
	cub->data.screen.x = -1;
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
