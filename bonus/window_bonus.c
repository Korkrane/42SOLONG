/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:15:43 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/30 15:22:44 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	init_win(t_win *win)
{
	win->mlx_p = NULL;
	win->win_p = NULL;
	win->wid = -1;
	win->hei = -1;
}

void	free_win(t_cub *cub)
{
	if (cub->win.mlx_p)
	{
		if (cub->win.win_p)
			mlx_destroy_window(cub->win.mlx_p, cub->win.win_p);
		mlx_destroy_display(cub->win.mlx_p);
		free(cub->win.mlx_p);
	}
	cub->win.mlx_p = NULL;
}

void	load_win(t_win *win)
{
	win->wid = 800;
	win->hei = 800;
	win->win_p = mlx_new_window(win->mlx_p, win->wid, win->hei, "so_long");
}
