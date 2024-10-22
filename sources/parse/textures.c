/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:08 by mapale            #+#    #+#             */
/*   Updated: 2024/10/22 13:10:45 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/* bool	fill_textures(t_p_map *map, char **path, char *str, int index)
{
	int	fd;

	fd = 0;
	if (*path)
		free_all_and_exit(ERR_DBL_TEXTURE, map, -1);
	*path = ft_strtrim(str + (index + 2), " ");
	if (!(*path))
	{
		free(str);
		free_all_and_exit(ERR_MALLOC, map, -1);
	}
	if (*(*path) == '\0' || *(*path) == '\n')
	{
		free(str);
		free_all_and_exit(ERR_TEXTURE, map, -1);
	}
	return (true);
} */

bool	fill_textures(t_p_map *map, t_p_path *paths, char *str, int index)
{
	int	i;
	int	fd;
	int	stop;
	int	start;

	i = index + 2;
	fd = 0;
	stop = 0;
	start = 0;
	if (paths->nb_paths != 0)
		free_all_and_exit(ERR_DBL_TEXTURE, map, -1);
	while (paths->nb_paths != SPR_MAX)
	{
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		stop = i;
		paths->paths[paths->nb_paths] = ft_strtrim(str + (index + 2), " ");
	}
	if (!(*path) || (*(*path) == '\0' || *(*path) == '\n'))
		return (free(str), free_all_and_exit(ERR_TEXTURE, map, -1), false);
	return (true);
}

bool	check_textures(t_p_map *map, char *line)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0)
		return (fill_textures(map, &map->txtrs_paths.n_path, line, i));
	if (ft_strncmp(line + i, "SO", 2) == 0)
		return (fill_textures(map, &map->txtrs_paths.s_path, line, i));
	if (ft_strncmp(line + i, "WE", 2) == 0)
		return (fill_textures(map, &map->txtrs_paths.w_path, line, i));
	if (ft_strncmp(line + i, "EA", 2) == 0)
		return (fill_textures(map, &map->txtrs_paths.ea_path, line, i));
	if (ft_strncmp(line + i, "F ", 2) == 0)
		if (check_color(line + (i + 2), map, 0) && map->color_count == 3)
			return (map->color_count = 0, get_color_values(map, \
			&map->txtrs_paths.f_color, line + (i + 2)));
	if (ft_strncmp(line + i, "C ", 2) == 0)
		if (check_color(line + (i + 2), map, 0) && map->color_count == 3)
			return (map->color_count = 0, get_color_values(map, \
			&map->txtrs_paths.c_color, line + (i + 2)));
	return (false);
}

bool	are_textures_valid(t_p_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = safe_open(map->path, map, -2);
	line = get_next_line(fd);
	while (line && i < map->map_start)
	{
		while (valid_txtrs_condition(map, line, i, 1))
		{
			free(line);
			line = get_next_line(fd);
			i++;
		}
		if (!line || i >= map->map_start)
			break ;
		if (valid_txtrs_condition(map, line, i, 2))
			return (free(line), free_all_and_exit(ERR_TEXTURE, map, -1), NULL);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (close(fd), true);
}
