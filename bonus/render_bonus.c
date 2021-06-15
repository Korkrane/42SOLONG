/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:37:21 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/11 18:24:42 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
 ** Render floor from bot pixel to window height.
 */
/*
   void	render_floor(t_cub *cub, t_ray rays, int i)
   {
   int j;

   j = rays.bot_px;
   while (j < cub->win.hei)
   {
   my_mlx_pixel_put(&cub->win, i, j, cub->data.floor);
   j++;
   }
   }
   */
/*
 ** Render ceil from 0 to top pixel position.
 */
/*
   void	render_ceil(t_cub *cub, t_ray rays, int i)
   {
   int j;

   j = -1;
   while (++j < rays.top_px)
   my_mlx_pixel_put(&cub->win, i, j, cub->data.ceil);
   }
   */
/*
 ** Render wall from top pixel to bot pixel. We calculate the corresponding
 ** pixel position of our texture then save the texture color to render it.
 */
/*
   void	render_wall(t_cub *cub, int i, float wall_hei)
   {
   float	text_x;
   float	text_y;
   int		color;
   int		j;

   if (cub->rays[i].was_vt_hit)
   text_x = fmod(cub->rays[i].wall_hit_y, 1) *
   cub->text[cub->rays[i].id].wid;
   else
   text_x = fmod(cub->rays[i].wall_hit_x, 1) *
   cub->text[cub->rays[i].id].wid;
   j = cub->rays[i].top_px - 1;
   while (++j < cub->rays[i].bot_px)
   {
   text_y = (j + (wall_hei / 2) - (cub->win.hei / 2)) *
   ((float)cub->text[cub->rays[i].id].hei / wall_hei);
   color = grep_color(cub->text[cub->rays[i].id], text_x, text_y);
   my_mlx_pixel_put(&cub->win, i, j, color);
   }
   }
   */
/*
 ** For each ray, we will calculate the distance between player and the wall &
 ** his height, then determine the top and bottom pos. We can start rendering
 ** pixels columns by columns.
 */

int	render_lol(t_cub *cub)
{
	/*
	   float			wall_dist;
	   float			wall_hei;
	   */
	int				top_px;
	int				bot_px;
	int				i;
	/*
	   i = -1;
	   while (++i < cub->win.wid)
	   {
	   wall_dist = cub->rays[i].dist * cos(cub->rays[i].ray_ang -
	   cub->player.rot_ang);
	   wall_hei = cub->data.dist_pplane / wall_dist;
	   top_px = (cub->win.hei / 2) - (wall_hei / 2);
	   bot_px = (cub->win.hei / 2) + (wall_hei / 2);
	   if (top_px < 0)
	   top_px = 0;
	   if (bot_px > cub->win.hei)
	   bot_px = cub->win.hei;
	   cub->rays[i].top_px = top_px;
	   cub->rays[i].bot_px = bot_px;
	   render_ceil(cub, cub->rays[i], i);
	   render_floor(cub, cub->rays[i], i);
	   render_wall(cub, i, wall_hei);
	   }
	   */

	void *img;
	void *win;
	int image_width;
	int image_height;
	img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[0].name, &image_width, &image_height);
    mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, cub->player.pos.x * (cub->win.wid / cub->data.cols), cub->player.pos.y * (cub->win.hei / cub->data.rows));
	i = 0;
	int j = 0;
	while(i < cub->data.rows)
	{
		j = 0;
		while(j < cub->data.cols)
		{
			if(cub->grid[i][j] == '1')
			{
/*
	img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[3].name, &image_width, &image_height);
    mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
*/
	}
			else if (cub->grid[i][j] == 'P')
			{

	img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[0].name, &image_width, &image_height);
    mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, cub->player.pos.x * (cub->win.wid / cub->data.cols), cub->player.pos.y * (cub->win.hei / cub->data.rows));
			}
			else if (cub->grid[i][j] == 'E')
			{
/*
	img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[2].name, &image_width, &image_height);
    mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
*/
	}
			else if (cub->grid[i][j] == 'C')
			{
/*
			img = mlx_xpm_file_to_image(cub->win.mlx_p, cub->text[1].name, &image_width, &image_height);
    mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p, img, j * (cub->win.wid / cub->data.cols), i * (cub->win.hei / cub->data.rows));
*/
	}
			j++;
		}
		i++;
	}
	/*
	if(cub->grid[0][0])
	{
		printf("test\n");
		float	text_x;
		float	text_y;
		int		color;
		int		j = 0;

		top_px = cub->win.hei / cub->data.rows * j;
		bot_px = cub->win.hei / cub->data.rows * (j + 1);
		cub->sprt[0].hei = bot_px - top_px;
		cub->sprt[0].top_px = top_px;
		cub->sprt[0].bot_px = bot_px;
		cub->sprt[0].pos_x = 0.5;
		text_x = 25;
		//text_x = fmod(cub->rays[i].wall_hit_x, 1) * cub->text[0].wid;
		i = 100;
		j = 0;
		while(++i < cub->win.wid)
		{
		while (++j < bot_px)
		{
			text_y = j;
			color = grep_color(cub->text[0], text_x, text_y);
			my_mlx_pixel_put(&cub->win, i, j, color);
		}
		}
	}
	*/
	return (1);
}

int		render(t_cub *cub)
{
	//cast_all_rays(cub);
	//render_3d(cub);
	render_mini_map(cub);
	render_mini_player(cub);
	//render_lol(cub);
	//render_sprt(cub);
	//render_mini_sprt(cub);
	//render_healthbar(cub);
	if (!cub->save)
	{
		mlx_put_image_to_window(cub->win.mlx_p, cub->win.win_p,
				cub->win.img.img, 0, 0);
		mlx_string_put(cub->win.mlx_p, cub->win.win_p, 50, 50, WHITE, ft_itoa(cub->total_action));
	}
	return (1);
}
