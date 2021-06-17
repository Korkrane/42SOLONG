/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/17 19:10:22 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	put_image(t_cub *cub, int j, int i, char *texture)
{
	cub->img_d = mlx_xpm_file_to_image(cub->win.mlx_p, texture,
			&cub->image_width, &cub->image_height);
	mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p,
		cub->img_d, j * (cub->win.wid / cub->data.cols),
		i * (cub->win.hei / cub->data.rows));
	mlx_destroy_image(cub->win.mlx_p, cub->img_d);
}

void	render_sprites(t_cub *cub, int j, int i)
{
	if (cub->grid[i][j] == '1')
		put_image(cub, j, i, cub->text[3].name);
	else if (cub->grid[i][j] == 'E')
		put_image(cub, j, i, cub->text[2].name);
	else if (cub->grid[i][j] == 'C')
		put_image(cub, j, i, cub->text[1].name);
	else if (cub->grid[i][j] == '0')
		put_image(cub, j, i, cub->text[4].name);
	else if (cub->grid[i][j] == 'P')
		put_image(cub, cub->player.pos.x, cub->player.pos.y, cub->player_text);
}

void	select_active_texture(t_cub *cub)
{
	if (cub->player.orientation == 0)
		cub->player_text = cub->text[0].name;
	else
		cub->player_text = cub->text[5].name;
}

int	render_lol(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	select_active_texture(cub);
	while (i < cub->data.rows)
	{
		j = 0;
		while (j < cub->data.cols)
		{
			render_sprites(cub, j, i);
			j++;
		}
		i++;
	}
	return (1);
}
