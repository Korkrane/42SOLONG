/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:21:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/15 16:18:56 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_texture(t_cub *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		cub->text[i].ptr = NULL;
		cub->text[i].data = NULL;
		cub->text[i].name = NULL;
		cub->text[i].bits_per_pixel = 0;
		cub->text[i].line_length = 0;
		cub->text[i].endian = 0;
		cub->text[i].wid = 0;
		cub->text[i].hei = 0;
		i++;
	}
}

void	free_texture(t_cub *cub)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		if (cub->text[i].name)
		{
			free(cub->text[i].name);
			cub->text[i].name = NULL;
		}
		if (cub->text[i].ptr)
		{
			mlx_destroy_image(cub->win.mlx_p, cub->text[i].ptr);
			cub->text[i].ptr = NULL;
			cub->text[i].data = NULL;
		}
	}
}

int		new_fill_texture(t_cub *cub)
{
	cub->text[0].name = ft_strdup("./textures/player.xpm");
	cub->text[1].name = ft_strdup("./textures/collect.xpm");
	cub->text[2].name = ft_strdup("./textures/Nouveau-projet-_1_.xpm");
	cub->text[3].name = ft_strdup("./textures/pillar.xpm");
	cub->text[4].name = ft_strdup("./textures/empty.xpm");
	return (1);
}

int		load_texture(t_cub *cub)
{
	int i;

	i = -1;
	new_fill_texture(cub);
	while (++i < 5)
	{
		if (cub->text[i].name)
		{
			cub->text[i].ptr = mlx_xpm_file_to_image(cub->win.mlx_p,
				cub->text[i].name, &cub->text[i].wid, &cub->text[i].hei);
			if (!cub->text[i].ptr)
				return (is_error("Bad texture content"));
			cub->text[i].data = mlx_get_data_addr(cub->text[i].ptr,
				&cub->text[i].bits_per_pixel, &cub->text[i].line_length,
				&cub->text[i].endian);
		}
	}
	return (1);
}
