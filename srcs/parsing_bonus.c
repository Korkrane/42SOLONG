/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:31:08 by bahaas            #+#    #+#             */
/*   Updated: 2021/06/11 15:41:51 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** Each line of the map is saved into a list element and added at the end
** to have it in the good order.
*/

int		fill_list_grid(t_cub *cub, char *line, t_list **list)
{
	t_list	*new_elem;

	cub->data.grid_flag = 1;
	new_elem = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_elem);
	return (1);
}

/*
** Help us to determine the content of the line then save the data to our
** cub3d parameter. grid_flag is here to know when we reached map parameter.
*/

int		line_data(t_cub *cub, char *line, t_list **list)
{
	cub->data.res = fill_list_grid(cub, line, list);
	return (cub->data.res);
}


void	print_map(t_cub *cub)
{
	int i = 0;
	int j = 0;
	while(i < cub->data.rows)
	{
		j = 0;
		while(j < cub->data.cols)
		{
			printf("%c", cub->grid[i][j]);
			j++;
		}	
		printf("\n");
		i++;
	}
}

/*
int valid_border(t_cub *cub)
{
	int i = 0;
	int j = 0;
	while(i < cub->data.rows)
	{
		if(cub->grid[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}
*/

int valid_map_format(t_cub *cub)
{
	
	int i = 0;
	int line_len = ft_strlen(cub->grid[i]);
	while(i < cub->data.rows)
	{
		line_len = ft_strlen(cub->grid[i]);
		if(line_len != cub->data.cols)
			return (0);
		i++;
	}
	printf("test i value : %d\n", i);
	return (1);
}

/*
** Check if we have all the required parameters to load the game.
*/

int		check_missing(t_cub *cub)
{
	if (!cub->data.exit_number)
		return (is_error("There is 0 exit"));
	if (!cub->data.collect_number)
		return (is_error("There is 0 collectible"));
	if(!valid_map_format(cub))
		return (is_error("Map hasn't a valid format"));
	printf("check missing return 1\n");
	print_map(cub);
	return (1);
}

/*
** Read the .cub file and analyse it line by line.
*/

int		parsing(t_cub *cub, char *map_file, t_list **list)
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
			valid = line_data(cub, line, list);
		free(line);
		if (valid == 0)
			return (0);
	}
	close(fd);
	return (1);
}
