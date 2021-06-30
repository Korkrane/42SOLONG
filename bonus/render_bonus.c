/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/30 21:03:52 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

//800/800

int		grep_color(t_text text, int x, int y)
{
	char *dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > text.wid)
		x = text.wid;
	if (y > text.hei)
		y = text.hei;
	dst = text.data + (y * text.line_length + x * text.bits_per_pixel / 8);
	return (*(unsigned int*)dst);
}

void	fill_sprt_data(t_cub *cub, int j, int i, char *texture, int text_id)
{
	float top_px;
	float bot_px;
	float sprt_hei;
	float sprt_wid;
	float pos_x;

	sprt_hei = cub->win.hei / cub->data.rows;
	sprt_wid = cub->win.wid / cub->data.cols;
	float right_px = sprt_wid;
	top_px = i * sprt_hei;
	bot_px = (i + 1) * sprt_hei;
	pos_x = j * (cub->win.wid / cub->data.cols);
	/*
		printf("pillar[%d][%d] :\n", j, i);
		printf("sprt_hei : %f\n", sprt_hei);
		printf("sprt_wid : %f\n", sprt_wid);
		printf("bot_px : %f\n", bot_px);
		printf("top_px : %f\n", top_px);
		printf("right_px : %f\n", right_px);
		printf("pos_x : %f\n", pos_x);
	*/
	float text_x;
	float text_y;
	float screen_x;
	float screen_y;

	//static int print2 = 0;
	screen_x = -1;
	int o;
	while(pos_x + screen_x < 0)
		screen_x++;
	while (++screen_x <= right_px)
	{
		text_x = screen_x * (cub->text[text_id].wid / sprt_wid);
		screen_y = top_px - 1;
		o = -1;
		while(++screen_y < bot_px)
		{
			++o;
			text_y = (o * (cub->text[text_id].hei / sprt_hei));
			//if(i != 0)
			//	text_y = text_y - 6.4 * i;
			//text_y = (screen_y) + (cub->text[text_id].hei / 2) - (cub->win.hei / 2) * (cub->text[text_id].hei / sprt_hei);
			//text_y = (screen_y + (cub->text[text_id].hei / 2) - (cub->win.hei / 2)) * (cub->text[text_id].hei / sprt_hei);
		//	if(print2 <= i + 2 && i != 0)
		//	{
		//		printf("\tTEXT_Y: %f\n", text_y);
		//		print2++;
		//	}
			if (text_y < 0)
				text_y = 0;
			int		color;
			int		background;
			color = grep_color(cub->text[text_id], text_x, text_y);
			background = grep_color(cub->text[text_id], 0, 0);
			if (color != background)
				my_mlx_pixel_put(&cub->win, pos_x + screen_x, screen_y, color);
		}
	}
	//printf("\n");
}

void	put_image(t_cub *cub, int j, int i, char *texture, int text_id)
{
	fill_sprt_data(cub, j, i, texture, text_id);
}

void	render_sprites(t_cub *cub, int j, int i)
{
	char	*action;

	if (cub->grid[i][j] == '1')
	{
		/*
		action = ft_itoa(cub->total_action);
		mlx_string_put(cub->win.mlx_p, cub->win.win_p, 50, 50,
		WHITE, action);
		free(action);
		*/
		put_image(cub, j, i, cub->text[3].name, 3);
	}
	else if (cub->grid[i][j] == 'E')
		put_image(cub, j, i, cub->text[2].name, 2);
	else if (cub->grid[i][j] == 'C')
		put_image(cub, j, i, cub->text[1].name, 1);
	else if (cub->grid[i][j] == '0')
		put_image(cub, j, i, cub->text[4].name, 4);
	else if (cub->grid[i][j] == 'X')
		put_image(cub, j, i, cub->ennemy_text, 6);
	else if (cub->grid[i][j] == 'P')
		put_image(cub, cub->player.pos.x, cub->player.pos.y, cub->player_text, 0);
}

void	select_active_texture(t_cub *cub)
{
	if (cub->ennemy.orientation == 0)
		cub->ennemy_text = cub->text[7].name;
	else
		cub->ennemy_text = cub->text[6].name;
	if (cub->player.orientation == 0)
		cub->player_text = cub->text[0].name;
	else
		cub->player_text = cub->text[5].name;
}

int	render_lol(t_cub *cub)
{
	int		i;
	int		j;

	i = -1;
	select_active_texture(cub);
	while (++i < cub->data.rows)
	{
		j = -1;
		while (++j < cub->data.cols)
			render_sprites(cub, j, i);
	}
	mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, cub->win.img.img, 0, 0);
	return (1);
}
