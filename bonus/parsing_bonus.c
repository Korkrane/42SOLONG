/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:31:08 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/16 13:40:20 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

/*
** Each line of the map is saved into a list element and added at the end
** to have it in the good order.
*/

int	fill_list_grid(t_sl *sl, char *line, t_list **list)
{
	t_list	*new_elem;

	sl->data.grid_flag = 1;
	new_elem = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_elem);
	return (1);
}

/*
** Help us to determine the content of the line then save the data to our
** sl3d parameter. grid_flag is here to know when we reached map parameter.
*/

int	line_data(t_sl *sl, char *line, t_list **list)
{
	sl->data.res = fill_list_grid(sl, line, list);
	return (sl->data.res);
}

int	valid_map_format(t_sl *sl)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(sl->grid[i]);
	while (i < sl->data.rows)
	{
		line_len = ft_strlen(sl->grid[i]);
		if (line_len != sl->data.cols)
			return (0);
		i++;
	}
	return (1);
}

/*
** Check if we have all the required parameters to load the game.
*/

int	check_missing(t_sl *sl)
{
	if (!sl->data.exit_number)
		return (is_error("There is 0 exit"));
	if (!sl->data.collect_number)
		return (is_error("There is 0 collectible"));
	if (!valid_map_format(sl))
		return (is_error("Map hasn't a valid format"));
	return (1);
}

/*
** Read the .sl file and analyse it line by line.
*/

int	parsing(t_sl *sl, char *map_file, t_list **list)
{
	int		fd;
	int		valid;
	int		i;
	char	*line;

	i = 1;
	fd = open(map_file, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		return (is_error("Map file isn't valid"));
	if (fd < 0)
		return (is_error("Map file couldn't open"));
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0)
			valid = line_data(sl, line, list);
		free(line);
		if (valid == 0)
			return (0);
	}
	close(fd);
	return (1);
}
