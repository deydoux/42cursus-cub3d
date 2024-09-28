/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:49:01 by mapale            #+#    #+#             */
/*   Updated: 2024/09/28 19:14:29 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	create_map(t_map *map)
{
	int		i;
	int		fd;
	char*	line;
	int		start;

	i = -1;
	start = 0;
	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		while (line && ++start < map->map_start)
		{
			free(line);
			line = get_next_line(fd);
		}
		if (*line == '\0')
			free_map_and_exit("Error\nInvalid map\n", map);
		map->map[++i] = line;
	}
}

int	get_map_height(t_map *map)
{
	int		fd;
	int 	count;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	map->map_start = -1;
	count = 0;
	while (line)
	{
		while (ft_isspace(*line))
			*line++;
		if (*line == '1')
		{
			if (map->map_start == -1)
				map->map_start = count;
			map->map_h++;
		}
		free(line);
		line = get_next_line(fd);
		count++;
	}
	return (free(line), close(fd));
}

void	get_map_width(t_map *map)
{
	int		i;
	int		fd;
	int		tmp;
	char	*line;

	i = -1;
	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	map->map_w = 0;
	while (line)
	{
		while (line && ++i < map->map_start)
		{
			free(line);
			line = get_next_line(fd);
		}
		tmp = ft_strlen(line);
		if (tmp > map->map_w)
			map->map_w = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd));
}
