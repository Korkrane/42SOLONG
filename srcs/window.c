/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:15:43 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/30 15:22:32 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_win(t_win *win)
{
	win->mlx_p = NULL;
	win->win_p = NULL;
	win->wid = -1;
	win->hei = -1;
}

void	free_win(t_sl *sl)
{
	if (sl->win.mlx_p)
	{
		if (sl->win.win_p)
			mlx_destroy_window(sl->win.mlx_p, sl->win.win_p);
		mlx_destroy_display(sl->win.mlx_p);
		free(sl->win.mlx_p);
	}
	sl->win.mlx_p = NULL;
}

void	load_win(t_win *win)
{
	win->wid = 800;
	win->hei = 800;
	win->win_p = mlx_new_window(win->mlx_p, win->wid, win->hei, "so_long");
}
