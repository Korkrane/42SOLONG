/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/01 17:21:41 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	render_valid_pixel(t_cub *cub, int text_id)
{
	int	color;
	int	background;

	color = grep_color(cub->text[text_id], cub->data.text.x, cub->data.text.y);
	background = grep_color(cub->text[text_id], 0, 0);
	if (color != background)
		my_mlx_pixel_put(&cub->win, cub->data.pos_x + cub->data.screen.x,
			cub->data.screen.y, color);
}

void	render_texture(t_cub *cub, int j, int i, int text_id)
{
	int	size;

	fill_ratio_data(cub, i, j);
	while (cub->data.pos_x + cub->data.screen.x < 0)
		cub->data.screen.x++;
	while (++cub->data.screen.x <= cub->data.right_px)
	{
		cub->data.text.x = cub->data.screen.x
			* (cub->text[text_id].wid / cub->data.sprt_wid);
		cub->data.screen.y = cub->data.top_px - 1;
		size = -1;
		while (++cub->data.screen.y < cub->data.bot_px)
		{
			++size;
			cub->data.text.y = (size
					* (cub->text[text_id].hei / cub->data.sprt_hei));
			if (cub->data.text.y < 0)
				cub->data.text.y = 0;
			render_valid_pixel(cub, text_id);
		}
	}
}

void	select_texture_to_render(t_cub *cub, int j, int i)
{
	if (cub->grid[i][j] == '1')
		render_texture(cub, j, i, 3);
	else if (cub->grid[i][j] == 'E')
		render_texture(cub, j, i, 2);
	else if (cub->grid[i][j] == 'C')
		render_texture(cub, j, i, 1);
	else if (cub->grid[i][j] == '0')
		render_texture(cub, j, i, 4);
	else if (cub->grid[i][j] == 'X')
		render_texture(cub, j, i, cub->ennemy_text_id);
	else if (cub->grid[i][j] == 'P')
		render_texture(cub, cub->player.pos.x, cub->player.pos.y,
			cub->player_text_id);
}

void	select_active_texture(t_cub *cub)
{
	if (cub->ennemy.orientation == 0)
		cub->ennemy_text_id = 7;
	else
		cub->ennemy_text_id = 6;
	if (cub->player.orientation == 0)
		cub->player_text_id = 0;
	else
		cub->player_text_id = 5;
}

int	render(t_cub *cub)
{
	int		i;
	int		j;
	char	*action;

	i = -1;
	select_active_texture(cub);
	while (++i < cub->data.rows)
	{
		j = -1;
		while (++j < cub->data.cols)
			select_texture_to_render(cub, j, i);
	}
	mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p,
		cub->win.img.img, 0, 0);
	action = ft_itoa(cub->total_action);
	mlx_string_put(cub->win.mlx_p, cub->win.win_p, 50, 50,
		WHITE, action);
	free(action);
	return (1);
}
