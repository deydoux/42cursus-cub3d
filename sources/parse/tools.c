/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:18 by mapale            #+#    #+#             */
/*   Updated: 2024/10/21 16:28:10 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	w_isspace(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i);
}

char	*ft_strdup_range(const char *s, int start, int stop)
{
	int		i;
	int		size;
	char	*tab;

	i = 0;
	size = (stop - start) + 1;
	tab = (char *)malloc(sizeof(char) * (size));
	if (!tab)
		return ((char *) NULL);
	while (start < stop)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

bool	valid_txtrs_condition(t_p_map *map, char *line, int index, int condition)
{
	if (condition == 1 && \
		line && index < map->map_start \
		&& (size_t)w_isspace(line) == ft_strlen(line))
		return (true);
	if (condition == 2 && \
		!check_textures(map, line) && line[0] != '\0' \
		&& index >= map->map_start)
		return (true);
	return (false);
}

bool	is_maze_open(t_p_map *map, char *line, int y, int x)
{
	if (y == map->map_h - 1 || y == 0)
	{
		while (line[x] && (y == map->map_h - 1 || line[x] != '\n' ))
		{
			if (line[x] != '1' && line[x] != ' ')
				return (false);
			x++;
		}
	}
	else
	{
		if (map->map[y][x] != '1' \
		&& map->map[y][ft_strlen(map->map[y]) - 1] != '1')
			return (false);
	}
	return (true);
}

bool	is_this_texture_valid(t_p_path *txtr)
{
	int	i;

	i = 0;
	if (txtr->nb_paths == 0)
		return (false);
	while (i < txtr)
	{
		if (!txtr->paths[i])
			return (false);
		i++;
	}
	return (true);
}
