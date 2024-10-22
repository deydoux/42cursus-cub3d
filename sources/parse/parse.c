/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:11:49 by mapale            #+#    #+#             */
/*   Updated: 2024/10/22 15:06:39 by mapale           ###   ########.fr       */
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
			&& (BONUS && map->map[y][x] != 'D') && !ft_isspace(map->map[y][x]))
				free_all_and_exit(ERR_MAZE_INVALID_CHARAC, map, -1);
			x++;
		}
	}
}

bool	is_line_empty(t_p_map *map, char *line, int fd, int index)
{
	if ((size_t)w_isspace(line) != ft_strlen(line) && index >= map->map_h)
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
	int		i;
	int		fd;
	char	*line;
	int		start;

	i = 0;
	start = -1;
	fd = safe_open(map->path, map, 0);
	line = get_next_line(fd);
	while (line)
	{
		while (line && ++start < map->map_start)
		{
			free(line);
			line = get_next_line(fd);
		}
		if (!is_line_empty(map, line, fd, i))
			break ;
		map->map[i] = _strdup_map(line, map, i);
		if (!map->map[i])
			return (free(line), free_map(map, i, ERR_MAP));
		free(line);
		line = get_next_line(fd);
		i++;
	}
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

int	parse(int ac, char **av)
{
	t_p_map	map;

	if (ac != 2)
		return (err_msg(ERR_NO_INPUT));
	if (!is_input_valid(av[1]))
		return (err_msg(ERR_INPUT_INVALID));
	if (!are_values_initialized(&map, av[1]))
		return (1);//err msg type
	///*TPRINTF------------------------------------------*/printf("map->map_start = %d\nmap->map_h = %d\nmap->map_w = %d\n", map.map_start, map.map_h, map.map_w);
	create_map(&map);
	///*TPRINTF--------------------------------*/print_map(&map);
	are_textures_valid(&map);
	///*TPRINTF--------------------------------*/print_textures(&map);
	if (!map.txtrs_paths.c_color || !map.txtrs_paths.f_color \
		|| !are_all_textures_valid(&map.txtrs_paths))
		free_all_and_exit(ERR_M_TEXTURE, &map, -1);
	check_maze(&map);
	if (map.player.spawn == '.')
		free_all_and_exit(ERR_PLAYER, &map, -1);
	///*TPRINTF--------------------------------*/printf("\nplayer's spawn : %c (%d,%d)\n", map.player.spawn, map.player.y, map.player.x);
	if (!can_u_play(&map, map.player.y, map.player.x))
		free_all_and_exit(ERR_MAP, &map, -1);
	free_all_and_exit(NULL, &map, -1);
	return (0);
}
