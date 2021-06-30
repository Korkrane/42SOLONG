/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:27:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/30 19:17:46 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

/*
** KEY EVENTS
** to find keycode of each key, execute 'xev' in terminal and press key wanted
*/

# define KEY_Z		122
# define KEY_A		97
# define KEY_W		119
# define KEY_Q		113
# define KEY_S		115
# define KEY_D		100
# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_DOWN	65364
# define KEY_RIGHT	65363
# define KEY_ESC	65307

# define WHITE	0x00FFFFFF
# define BLUE	0x000000FF

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	int			lateral_d;
	int			walk_d;
	t_pos		pos;
	t_pos		old_pos;
	int			orientation;
}				t_player;

typedef struct s_img
{
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*addr;
	void		*img;
	int			wid;
	int			hei;
}				t_img;

typedef struct s_win
{
	void		*mlx_p;
	void		*win_p;
	char		*name;
	t_img		img;
	int			hei;
	int			wid;
}				t_win;

typedef struct s_text
{
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*name;
	char			*data;
	void			*ptr;
	int				wid;
	int				hei;
}				t_text;

typedef struct s_data
{
	int				grid_flag;
	int				txtr_err;
	int				cols;
	int				rows;
	int				res;
	int				collect_number;
	int				exit_number;
}				t_data;

/*
typedef struct s_sprt
{
	int			visibility;
	int			texture;
	int			top_px;
	int			bot_px;
	float		dist;
	t_pos		pos;
	float		ang;
	float		hei;
	int			id;
	float		pos_x;
}				t_sprt;
*/

typedef struct s_cub
{
	t_text		text[8];
	t_player	player;
	t_player	ennemy;
	char		**grid;
	t_data		data;
	t_win		win;
	int			mlx_load;
	int			total_action;
	int			ennemy_limit_move;
	int			ennemy_limit_index;
//	void		*img_d;
//	void		*win_d;
	int			image_width;
	int			image_height;
	char		*player_text;
	char		*ennemy_text;
}				t_cub;

int				key_pressed(int key, t_cub *cub);
int				key_released(int key, t_player *player);
t_pos			init_pos(float a, float b);
int				fill_list_grid(t_cub *cub, char *line, t_list **list);
int				line_data(t_cub *cub, char *line, t_list **list);
int				last_load(t_cub *cub);
int				check_missing(t_cub *cub);
int				parsing(t_cub *cub, char *map_file, t_list **list);
int				render(t_cub *cub);
void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
int				grid_is_wall(int x, int y, t_cub *cub);
void			init_grid(t_cub *cub);
void			free_grid(t_cub *cub);
int				fill_grid(t_cub *cub, t_list *list);
int				grid_alloc(t_cub *cub, t_list *list);
int				grid_parsing(t_cub *cub, t_list *list);
int				check_surrounding(char **grid, int x, int y);
int				is_grid(t_cub *cub, int rows, int y, int len);
int				check_grid(t_cub *cub);
void			init_player(t_player *player);
void			update(t_cub *cub, t_player *player);
void			pos_player(t_player *player, int x, int y);
int				check_player(t_cub *cub);
int				count_cols(t_list *list);
int				is_num(char *num);
int				free_split(char ***split, int ret);
int				is_error(char *str);
int				cub_ext(char *map_file);
void			init_texture(t_cub *cub);
void			free_texture(t_cub *cub);
int				load_texture(t_cub *cub);
int				is_texture(char **line_data, t_cub *cub);
int				fill_texture(t_cub *cub, char **line_data);
int				check_format(char *line, int total, char **colors, t_cub *cub);
void			check_res(t_cub *cub);
int				num_args(char **data, int i, int tot);
int				fill_res(t_cub *cub, char **data);
void			init_img(t_img *img);
void			load_img(t_win *win);
void			free_img(t_cub *cub);
void			init_win(t_win *win);
void			load_win(t_win *win);
void			free_win(t_cub *cub);
void			init_cub(t_cub *cub, char *map);
void			load_cub(t_cub *cub, char *map);
void			run_cub(t_cub *cub);
int				end_cub(t_cub *cub);
int				render_lol(t_cub *cub);
int				check_ennemy(t_cub *cub);
void			set_old_position(t_cub *cub, t_player *player);
#endif
