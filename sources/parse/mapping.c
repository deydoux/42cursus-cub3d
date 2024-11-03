/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:49:01 by mapale            #+#    #+#             */
/*   Updated: 2024/11/03 14:02:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*_strdup_map(char *s, t_p_map *map, size_t h)
{
	int		i;
	size_t	size;
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
	if (ft_strncmp(line, "NO", 2) != 0 && ft_strncmp(line, "SO", 2) != 0
		&& ft_strncmp(line, "WE", 2) != 0 && ft_strncmp(line, "EA", 2) != 0
		&& ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0
		&& ft_strlen(line) != w_isspace(line))
		return (true);
	return (false);
}

int	get_map_height(t_p_map *map)
{
	size_t	i;
	size_t	count;
	char	*line;

	map->fd = safe_open(map->path, map, -1);
	line = get_next_line(map->fd);
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
		line = get_next_line(map->fd);
		count++;
	}
	return (free(line), close(map->fd));
}

int	get_map_width(t_p_map *map)
{
	int		i;
	size_t	tmp;
	char	*line;

	i = -1;
	map->fd = safe_open(map->path, map, -1);
	line = get_next_line(map->fd);
	map->map_w = 0;
	while (line)
	{
		while (line && ++i < map->map_start)
		{
			free(line);
			line = get_next_line(map->fd);
		}
		tmp = ft_strlen(line);
		if ((int)tmp > map->map_w)
			map->map_w = tmp;
		free(line);
		line = get_next_line(map->fd);
	}
	return (free(line), close(map->fd));
}
