/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/07/07 19:14:44 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_valid_pixel(t_sl *sl, int text_id)
{
	int	color;
	int	background;

	color = grep_color(sl->text[text_id], sl->data.text.x, sl->data.text.y);
	background = grep_color(sl->text[text_id], 0, 0);
	if (color != background)
		my_mlx_pixel_put(&sl->win, sl->data.pos_x + sl->data.screen.x,
			sl->data.screen.y, color);
}

void	render_texture(t_sl *sl, int j, int i, int text_id)
{
	int	size;

	fill_ratio_data(sl, i, j);
	while (sl->data.pos_x + sl->data.screen.x < 0)
		sl->data.screen.x++;
	while (++sl->data.screen.x <= sl->data.right_px)
	{
		sl->data.text.x = sl->data.screen.x
			* (sl->text[text_id].wid / sl->data.sprt_wid);
		sl->data.screen.y = sl->data.top_px - 1;
		size = -1;
		while (++sl->data.screen.y < sl->data.bot_px)
		{
			++size;
			sl->data.text.y = (size
					* (sl->text[text_id].hei / sl->data.sprt_hei));
			if (sl->data.text.y < 0)
				sl->data.text.y = 0;
			render_valid_pixel(sl, text_id);
		}
	}
}

void	select_texture_to_render(t_sl *sl, int j, int i)
{
	if (sl->grid[i][j] == '1')
		render_texture(sl, j, i, 3);
	else if (sl->grid[i][j] == 'E')
		render_texture(sl, j, i, 2);
	else if (sl->grid[i][j] == 'C')
		render_texture(sl, j, i, 1);
	else if (sl->grid[i][j] == '0')
		render_texture(sl, j, i, 4);
	else if (sl->grid[i][j] == 'P')
		render_texture(sl, sl->player.pos.x, sl->player.pos.y,
			sl->player_text_id);
}

void	select_active_texture(t_sl *sl)
{
	if (sl->player.orientation == 0)
		sl->player_text_id = 0;
}

int	render(t_sl *sl)
{
	int		i;
	int		j;

	i = -1;
	select_active_texture(sl);
	while (++i < sl->data.rows)
	{
		j = -1;
		while (++j < sl->data.cols)
			select_texture_to_render(sl, j, i);
	}
	mlx_put_image_to_window(sl->win.mlx_p, sl->win.win_p,
		sl->win.img.img, 0, 0);
	return (1);
}
