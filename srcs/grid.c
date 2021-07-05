/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:19:13 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 16:33:59 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_grid(t_sl *sl)
{
	sl->data.rows = 0;
	sl->data.cols = 0;
	sl->data.grid_flag = 0;
}

void	free_grid(t_sl *sl)
{
	int	i;

	i = -1;
	while (++i < sl->data.rows)
	{
		free(sl->grid[i]);
		sl->grid[i] = NULL;
	}
	free(sl->grid);
}

/*
** Duplicate the content of my list in my sl structure.
*/

int	fill_grid(t_sl *sl, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		sl->grid[i] = ft_strdup(list->content);
		i++;
		list = list->next;
	}
	return (1);
}

/*
** Find number of rows and cols of the map. Malloc the required space to save
** the map parameter then fill it in my sl structure.
*/

int	grid_alloc(t_sl *sl, t_list *list)
{
	int	cols;
	int	rows;

	cols = count_cols(list);
	rows = ft_lstsize(list);
	if (!cols || !rows)
		return (is_error("Map has 0 cols or 0 rows"));
	sl->grid = malloc(sizeof(char *) * rows + 1);
	sl->data.cols = cols;
	sl->data.rows = rows;
	if (!sl->grid)
		return (is_error("Not enough memory to malloc the map"));
	fill_grid(sl, list);
	return (1);
}

/*
** Malloc and fill my map. Then check if it's a valid map.
*/

int	grid_parsing(t_sl *sl, t_list *list)
{
	if (!grid_alloc(sl, list))
	{
		ft_lstclear(&list, &ft_free);
		return (0);
	}
	ft_lstclear(&list, &ft_free);
	if (!check_player(sl) || !check_grid(sl))
		return (0);
	return (1);
}
