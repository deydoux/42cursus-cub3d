/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:49:01 by mapale            #+#    #+#             */
/*   Updated: 2024/10/18 14:26:16 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*_strdup_map(char *s, t_map *map, int h)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = map->map_w;
	dest = safe_malloc((size) * sizeof(char), map, h);
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == '\t')
			free_all_and_exit(ERR_MAP, map, i);
		dest[i] = s[i];
		i++;
	}
	while (i < map->map_w - 1)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

bool	validity(char *line)
{
	if (ft_strncmp(line, "NO", 2) != 0 && ft_strncmp(line, "SO", 2) != 0 \
		&& ft_strncmp(line, "WE", 2) != 0 && ft_strncmp(line, "EA", 2) != 0 \
		&& ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0 \
		&& (int)ft_strlen(line) != w_isspace(line))
		return (true);
	return (false);
}

int	get_map_height(t_map *map)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	fd = safe_open(map->path, map, -1);
	line = get_next_line(fd);
	map->map_start = -1;
	count = 0;
	while (line)
	{
		i = w_isspace(line);
		if (validity(line + i))
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

int	get_map_width(t_map *map)
{
	int		i;
	int		fd;
	int		tmp;
	char	*line;

	i = -1;
	fd = safe_open(map->path, map, -1);
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
