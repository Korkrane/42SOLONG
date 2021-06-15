/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:50:20 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/15 17:42:03 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/cub.h"


/*
** Init all of our ressources and then start the game.
*/

void	init_cub(t_cub *cub, char *map)
{
	init_win(&cub->win);
	init_img(&cub->win.img);
	init_grid(cub);
	init_player(&cub->player);
	init_player(&cub->ennemy);
	init_texture(cub);
	cub->ray_load = 0;
	cub->sprt_load = 0;
	cub->mlx_load = 0;
	cub->data.txtr_err = 0;
	cub->total_action = 0;
	load_cub(cub, map);
}

/*
** Free all of our ressources.
*/

int		end_cub(t_cub *cub)
{
	free_texture(cub);
	if (cub->sprt_load == 1)
		free_sprt(cub);
	if (cub->ray_load == 1)
		free(cub->rays);
	if (cub->data.rows)
		free_grid(cub);
	if (cub->win.img.img)
		free_img(cub);
	free_win(cub);
	exit(0);
}

/*
** If we have a valid map, load the game.
*/

void	load_cub(t_cub *cub, char *map)
{
	t_list	*list;

	list = NULL;
	cub->win.mlx_p = mlx_init();
	if (parsing(cub, map, &list))
	{
		if (!grid_parsing(cub, list) || !check_missing(cub) || !load_texture(cub) || !load_sprt(cub))
			end_cub(cub);
		printf("So_long is launching..\n");
		printf("player pos : [%f:%f]\n", cub->player.pos.x, cub->player.pos.y);
		//cub->win.wid = 1920;
		//cub->win.hei = 1080;
		run_cub(cub);
	}
	else
	{
		ft_lstclear(&list, &ft_free);
		end_cub(cub);
	}
}

/*
** If save arg true, then just copy the 1st image. Otherwise, loop the render.
*/

void	run_cub(t_cub *cub)
{
	load_img(&cub->win);
	load_win(&cub->win);
	mlx_hook(cub->win.win_p, 3, 1L << 1, key_released, &cub->player);
	mlx_hook(cub->win.win_p, 2, 1L << 0, key_pressed, cub);
	mlx_loop_hook(cub->win.mlx_p, render_lol, cub);
	mlx_string_put(cub->win.mlx_p, cub->win.win_p, 50, 50, WHITE, ft_itoa(cub->total_action));
	mlx_hook(cub->win.win_p, 33, 1L << 17, &end_cub, cub);
	mlx_loop(cub->win.mlx_p);
}

int		main(int ac, char **av)
{
	t_cub cub;

	if (ac == 2)
	{
		if (cub_ext(av[1]))
		{
			cub.save = 0;
			init_cub(&cub, av[1]);
		}
		return (0);
	}
	else
		return (is_error("Wrong numbers of arguments"));
	return (0);
}
