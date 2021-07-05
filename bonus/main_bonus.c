/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:50:20 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/01 16:23:19 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

/*
** Init all of our ressources and then start the game.
*/

void	init_sl(t_sl *sl, char *map)
{
	init_win(&sl->win);
	init_img(&sl->win.img);
	init_grid(sl);
	init_player(&sl->player);
	init_player(&sl->ennemy);
	init_texture(sl);
	sl->mlx_load = 0;
	sl->data.txtr_err = 0;
	sl->data.exit_number = 0;
	sl->total_action = 0;
	sl->data.collect_number = 0;
	load_sl(sl, map);
}

/*
** Free all of our ressources.
*/

int	end_sl(t_sl *sl)
{
	free_texture(sl);
	if (sl->data.rows)
		free_grid(sl);
	if (sl->win.img.img)
		free_img(sl);
	free_win(sl);
	exit(0);
}

/*
** If we have a valid map, load the game.
*/

void	load_sl(t_sl *sl, char *map)
{
	t_list	*list;

	list = NULL;
	sl->win.mlx_p = mlx_init();
	if (parsing(sl, map, &list))
	{
		if (!grid_parsing(sl, list) || !check_missing(sl)
			|| !load_texture(sl))
			end_sl(sl);
		sl->ennemy_limit_move = 4;
		sl->ennemy.orientation = 0;
		sl->player.old_pos.x = sl->player.pos.x;
		sl->player.old_pos.y = sl->player.pos.y;
		printf("You enter in a new dimension, take all the food before");
		printf("the Weird Wizard finds you and escape !\n");
		run_sl(sl);
	}
	else
	{
		ft_lstclear(&list, &ft_free);
		end_sl(sl);
	}
}

/*
** If save arg true, then just copy the 1st image. Otherwise, loop the render.
*/

void	run_sl(t_sl *sl)
{
	load_img(&sl->win);
	load_win(&sl->win);
	mlx_hook(sl->win.win_p, 3, 1L << 1, key_released, &sl->player);
	mlx_hook(sl->win.win_p, 2, 1L << 0, key_pressed, sl);
	mlx_loop_hook(sl->win.mlx_p, render, sl);
	mlx_hook(sl->win.win_p, 33, 1L << 17, &end_sl, sl);
	mlx_loop(sl->win.mlx_p);
}

int	main(int ac, char **av)
{
	t_sl	sl;

	if (ac == 2)
	{
		if (sl_ext(av[1]))
			init_sl(&sl, av[1]);
		return (0);
	}
	else
		return (is_error("Wrong numbers of arguments"));
	return (0);
}
