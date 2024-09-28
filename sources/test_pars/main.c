/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:11:49 by mapale            #+#    #+#             */
/*   Updated: 2024/09/28 19:14:41 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "cub.h"

bool	is_input_valid(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i <= 4)
		return (false);
	if (s[i - 1] == 'b' && s[i - 2] == 'u' && s[i - 3] == 'c' \
	&& s[i - 4] == '.')
		return (true);
	return (false);
}

bool	are_values_initialized(t_map *map, char *path)
{
	int	i;

	i = 0;
	map->path = path;
	map->map_h = 0;
	map->map_w = 0;
	get_map_height(map, path);
	get_map_width(map, path);
	printf("map->map_start = %d\nmap->map_h = %d\nmap->map_w = %d\n", map->map_start, map->map_h, map->map_w);
	if (map->map_h <= 0 || map->map_w <= 0)
	{
		perror("Error\nMap dimensions are wrong\n");
		exit(1);
	}
	map->map = malloc(sizeof(char *) * map->map_h);
	if (!map->map)
		return (false);
	while (i < map->map_h)
	{
		map->map[i] = malloc(sizeof(char) * (map->map_w + 1));
		if (!map->map[i])
			free_map_and_exit("Error\nMalloc fail : map init)\n", map);
	}
	map->player_spawn = '.';
}

bool fill_textures(t_map *map, char **path, char *str)
{
	if (*path)
		free_map_and_exit("Error\nTexture already filled\n", map, map->map_h);
	*path = ft_strtrim(str, " ");
	if (!*path)
		free_map_and_exit("Error\nMalloc fail (ft_strtrim)\n", map, map->map_h);
	return (true);
}

int	check_textures(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ((line[i] == 'N' && line[i + 1] == '0'))
		fill_textures(map, *map->textures_paths.north_path, line + (i + 2));
	if (line[i] == 'S' && line[i + 1] == '0')
		fill_textures(map, *map->textures_paths.south_path, line + (i + 2));
	if (line[i] == 'W' && line[i + 1] == 'E')
		fill_textures(map, *map->textures_paths.west_path, line + (i + 2));
	if (line[i] == 'E' && line[i + 1] == 'A')
		fill_textures(map, *map->textures_paths.east_path, line + (i + 2));
	return (-1);
}

/* bool	check_maze(t_map *map, int start)
{

	return (false);
} */

bool	is_line_valid(t_map *map, char *line)
{
	int		i;
	int		tmp;
	bool	in_map;

	i = 0;
	in_map = false;
	while (line[i])
	{
		tmp = check_textures(map, line);
		if (tmp != -1)
		{
			while(ft_isspace(line[i]))
				i++;
			if (line[i] == '1')
			{
				if (!map->textures_paths.east_path || !map->textures_paths.west_path \
					|| !map->textures_paths.north_path || !map->textures_paths.south_path)
					return (false);//err msg
				check_maze(map, i);
			}
			return (false);//err msg
		}
		i++;
	}
	return (true);
}

bool	is_map_valid(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		return (fd);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\0')
			return (false);//error msg
		is_line_valid(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_map map;
	if (ac != 2)
		return (0); //errmsg type
	if (!is_input_valid(av[1]))
		return (1);//err msg type
	if (!are_values_initialized(&map, av[1]))
		return (1);//err msg type
	if (!create_map())
		return (1);
	//free map->map;
}
