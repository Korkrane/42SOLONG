/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:19:50 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/15 21:52:41 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->wid = 800;
	img->hei = 800;
}

void	free_img(t_cub *cub)
{
	mlx_destroy_image(cub->win.mlx_p, cub->win.img.img);
	cub->win.img.img = NULL;
	cub->win.img.addr = NULL;
}

void	load_img(t_win *win)
{
	win->wid = 800;
	win->hei = 800;
	win->img.img = mlx_new_image(win->mlx_p, win->wid, win->hei);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel,
			&win->img.line_length, &win->img.endian);
	win->img.wid = win->wid;
	win->img.hei = win->hei;
}
