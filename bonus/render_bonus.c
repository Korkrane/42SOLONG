/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/30 19:26:31 by bahaas           ###   ########.fr       */
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
	int k;
	float top_px;
	float bot_px;
	float sprt_hei;
	float sprt_wid;
	float pos_x;

	sprt_hei = cub->win.hei / cub->data.rows;
	sprt_wid = cub->win.wid / cub->data.cols;
	top_px = i * sprt_hei;
	bot_px = (i + 1) * sprt_hei;
	pos_x = j * (cub->win.wid / cub->data.cols);
		printf("pillar[%d][%d] :\n", j, i);
		printf("sprt_hei : %f\n", sprt_hei);
		printf("sprt_wid : %f\n", sprt_wid);
		printf("bot_px : %f\n", bot_px);
		printf("top_px : %f\n", top_px);
		printf("pos_x : %f\n", pos_x);
	float text_x;
	float text_y;
	float screen_x;
	float screen_y;

	screen_x = -1;
	while(pos_x + screen_x < 0)
		screen_x++;
	while (++screen_x <= sprt_wid)
	{
		text_x = screen_x * cub->text[text_id].wid / sprt_wid;
		screen_y = top_px - 1;
		while(++screen_y < bot_px)
		{
			text_y = screen_y * cub->text[text_id].hei / sprt_hei;
			if (text_y < 0)
				text_y = 0;
			int		color;
			int		background;
			color = grep_color(cub->text[text_id], text_x, text_y);
			background = grep_color(cub->text[text_id], 0, 0);
			if (color != background)
			{
				printf("draw one..\n");
				my_mlx_pixel_put(&cub->win, pos_x + screen_x, screen_y, color);
			}
		}
		printf("screen_y : %f\n", screen_y);
	}
}

void	put_image(t_cub *cub, int j, int i, char *texture, int text_id)
{
	/*
	   cub->img_d = mlx_xpm_file_to_image(cub->win.mlx_p, texture,
	   &cub->image_width, &cub->image_height);
	   mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p,
	   cub->img_d, j * (cub->win.wid / cub->data.cols),
	   i * (cub->win.hei / cub->data.rows));
	   mlx_destroy_image(cub->win.mlx_p, cub->img_d);
	   */
	fill_sprt_data(cub, j, i, texture, text_id);
	/*
	int k = 0;
	int wid = cub->win.wid / cub->data.cols;
	while (++k < 800)
	{
		my_mlx_pixel_put(&cub->win, wid, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*2, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*3, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*4, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*5, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*6, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*7, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*8, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*9, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*10, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*11, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*12, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*13, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*14, k, BLUE);
		my_mlx_pixel_put(&cub->win, wid*15, k, BLUE);
	}
	k = 0;
	wid = cub->win.hei / cub->data.rows;
	while (++k < 800)
	{
		my_mlx_pixel_put(&cub->win, k, wid, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*2, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*3, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*4, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*5, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*6, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*7, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*8, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*9, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*10, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*11, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*12, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*13, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*14, BLUE);
		my_mlx_pixel_put(&cub->win, k, wid*15, BLUE);
	}
	*/
	mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, cub->win.img.img, 0, 0);
	
	/*
	mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p,
	   cub->win.img.img, j * (cub->win.wid / cub->data.cols),
	   i * (cub->win.hei / cub->data.rows));
	*/
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
	return (1);
}
