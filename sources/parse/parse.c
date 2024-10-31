/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:11:49 by mapale            #+#    #+#             */
/*   Updated: 2024/10/31 14:01:13 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_maze(t_p_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->map_h)
	{
		x = w_isspace(map->map[y]);
		if (!is_maze_open(map, map->map[y], y, x))
			free_all_and_exit(ERR_MAZE_OPEN, map, -1);
		while ((size_t)x < (ft_strlen(map->map[y]) - 1) && map->map[y][x])
		{
			if ((map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y] \
			[x] == 'W' || map->map[y][x] == 'E') && map->player.spawn == '.')
			{
				map->player.spawn = map->map[y][x];
				map->player.y = y;
				map->player.x = x;
			}
			else if (map->map[y][x] != '0' && map->map[y][x] != '1' \
			&& !(BONUS && map->map[y][x] == 'D') && !ft_isspace(map->map[y][x]))
				free_all_and_exit(ERR_MAZE_INVALID_CHARAC, map, -1);
			x++;
		}
	}
}

bool	is_line_empty(t_p_map *map, char *line, int fd, size_t index)
{
	if ((size_t)w_isspace(line) != ft_strlen(line) && (int)index >= map->map_h)
		return (free(line), free_map(map, index, ERR_MAP), false);
	if (*line == '\0' || (size_t)w_isspace(line) == ft_strlen(line))
	{
		while (line && (*line == '\0' \
			|| (size_t)w_isspace(line) == ft_strlen(line)))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (line && *line != '\0')
			return (free(line), free_map(map, index, ERR_MAP), false);
		if (!line)
			return (false);
	}
	return (true);
}

void	create_map(t_p_map *map)
{
	size_t	i;
	char	*line;
	int		start;

	i = 0;
	start = -1;
	map->fd = safe_open(map->path, map, 0);
	line = get_next_line(map->fd);
	while (line)
	{
		while (line && ++start < map->map_start)
		{
			free(line);
			line = get_next_line(map->fd);
		}
		if (!is_line_empty(map, line, map->fd, i))
			break ;
		map->map[i] = _strdup_map(line, map, i);
		if (!map->map[i])
			return (free(line), free_map(map, i, ERR_MAP));
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	safe_close(map->fd);
}

bool	are_all_textures_valid(t_p_textures *textures)
{
	if (!is_this_texture_valid(&textures->ea_path))
		return (false);
	if (!is_this_texture_valid(&textures->w_path))
		return (false);
	if (!is_this_texture_valid(&textures->s_path))
		return (false);
	if (!is_this_texture_valid(&textures->n_path))
		return (false);
	return (true);
}

bool	parse(t_p_map *map, char *path)
{
	ft_bzero(map, sizeof(*map));
	map->fd = -1;
	if (!is_input_valid(path))
		return (err_msg(ERR_INPUT_INVALID));
	if (!are_values_initialized(map, path))
		return (false);
	create_map(map);
	are_textures_valid(map);
	if (!map->txtrs_pths.c_color || !map->txtrs_pths.f_color \
		|| !are_all_textures_valid(&map->txtrs_pths))
		free_all_and_exit(ERR_M_TEXTURE, map, -1);
	check_maze(map);
	if (map->player.spawn == '.')
		free_all_and_exit(ERR_PLAYER, map, -1);
	if (!can_u_play(map, map->player.y, map->player.x))
		free_all_and_exit(ERR_MAP, map, -1);
	safe_close(map->fd);
	return (true);
}
