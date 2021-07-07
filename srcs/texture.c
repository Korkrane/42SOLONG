/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:21:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/07 19:28:55 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_texture(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		sl->text[i].ptr = NULL;
		sl->text[i].data = NULL;
		sl->text[i].name = NULL;
		sl->text[i].bits_per_pixel = 0;
		sl->text[i].line_length = 0;
		sl->text[i].endian = 0;
		sl->text[i].wid = 0;
		sl->text[i].hei = 0;
		i++;
	}
}

void	free_texture(t_sl *sl)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (sl->text[i].name)
		{
			free(sl->text[i].name);
			sl->text[i].name = NULL;
		}
		if (sl->text[i].ptr)
		{
			mlx_destroy_image(sl->win.mlx_p, sl->text[i].ptr);
			sl->text[i].ptr = NULL;
			sl->text[i].data = NULL;
		}
	}
}

int	new_fill_texture(t_sl *sl)
{
	sl->text[0].name = ft_strdup("./textures/player.xpm");
	sl->text[1].name = ft_strdup("./textures/collect.xpm");
	sl->text[2].name = ft_strdup("./textures/exit.xpm");
	sl->text[3].name = ft_strdup("./textures/pillar.xpm");
	sl->text[4].name = ft_strdup("./textures/empty.xpm");
	sl->text[5].name = ft_strdup("./textures/player_left.xpm");
	sl->text[6].name = ft_strdup("./textures/evil.xpm");
	sl->text[7].name = ft_strdup("./textures/evil_left.xpm");
	return (1);
}

int	load_texture(t_sl *sl)
{
	int	i;

	i = -1;
	new_fill_texture(sl);
	while (++i < 8)
	{
		if (sl->text[i].name)
		{
			sl->text[i].ptr = mlx_xpm_file_to_image(sl->win.mlx_p,
					sl->text[i].name, &sl->text[i].wid, &sl->text[i].hei);
			if (!sl->text[i].ptr)
				return (is_error("Bad texture content"));
			sl->text[i].data = mlx_get_data_addr(sl->text[i].ptr,
					&sl->text[i].bits_per_pixel, &sl->text[i].line_length,
					&sl->text[i].endian);
		}
	}
	return (1);
}
