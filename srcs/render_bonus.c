/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/15 17:02:48 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
 ** For each ray, we will calculate the distance between player and the wall &
 ** his height, then determine the top and bottom pos. We can start rendering
 ** pixels columns by columns.
 */

int	render_lol(t_cub *cub)
{
	int				top_px;
	int				bot_px;
	int				i;

	void *img;
	void *win;
	int image_width;
	int image_height;
	char *player_text;
	if(cub->player.orientation == 0)
		player_text = cub->text[0].name;
	else
		player_text = cub->text[5].name;
	i = 0;
	int j = 0;
	while(i < cub->data.rows)
	{
		j = 0;
		while(j < cub->data.cols)
		{
			if(cub->grid[i][j] == '1')
			{
				img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[3].name, &image_width, &image_height);
    			mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
			}
			else if (cub->grid[i][j] == 'P')
			{
				img = mlx_xpm_file_to_image(cub->win.mlx_p, player_text, &image_width, &image_height);
    			mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, cub->player.pos.x * (cub->win.wid / cub->data.cols), cub->player.pos.y * (cub->win.hei / cub->data.rows));
			}
			else if (cub->grid[i][j] == 'E')
			{
				img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[2].name, &image_width, &image_height);
    			mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
			}
			else if (cub->grid[i][j] == 'C')
			{
				img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[1].name, &image_width, &image_height);
    			mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
			}
			else if (cub->grid[i][j] == '0')
			{
				img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[4].name, &image_width, &image_height);
    			mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
			}
			j++;
		}
		i++;
	}
	return (1);
}
