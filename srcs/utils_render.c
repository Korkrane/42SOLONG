/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:22:51 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 13:44:58 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

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
