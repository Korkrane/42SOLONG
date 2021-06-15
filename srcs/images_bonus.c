/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:19:50 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/11 01:49:53 by bahaas           ###   ########.fr       */
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
	img->wid = 0;
	img->hei = 0;
}

void	free_img(t_cub *cub)
{
	mlx_destroy_image(cub->win.mlx_p, cub->win.img.img);
	cub->win.img.img = NULL;
	cub->win.img.addr = NULL;
}

void	load_img(t_win *win)
{
	printf("test\n");
	win->wid = 1920;
	win->hei = 1080;
	printf("win->mlx_p : %s\n", (char *)win->mlx_p);
	printf("win->wid : %d\n", win->wid);
	printf("win->wid : %d\n", win->hei);
	win->img.img = mlx_new_image(win->mlx_p, win->wid, win->hei);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel,
			&win->img.line_length, &win->img.endian);
	win->img.wid = win->wid;
	win->img.hei = win->hei;
}
