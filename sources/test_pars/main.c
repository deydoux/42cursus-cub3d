/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:11:49 by mapale            #+#    #+#             */
/*   Updated: 2024/09/24 17:03:49 by mapale           ###   ########.fr       */
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

bool	are_values_init(t_map *map, char *path)
{
	map->path = path;
	map->map_h = map_size(path);
	if (map->map_h < 0)
		return(false);//empty map msg
	map->map = malloc(sizeof(char *) * map->map_h);
	if (!map->map)
		retrun (false);
	//we'll see;
}

int	map_size(char *path)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (fd);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

bool fill_textures(char **path, char *str)
{
	*path = ft_strtrim(str, " ");
	if (!*path)
		return(false);
}

int	check_type_content(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ((line[i] == 'N' && line[i + 1] == '0'))
		fill_textures(*map->textures_paths.north_path, line + (i + 2));
	if (line[i] == 'S' && line[i + 1] == '0')
		fill_textures(*map->textures_paths.south_path, line + (i + 2));
	if (line[i] == 'W' && line[i + 1] == 'E')
		fill_textures(*map->textures_paths.west_path, line + (i + 2));
	if (line[i] == 'E' && line[i + 1] == 'A')
		fill_textures(*map->textures_paths.east_path, line + (i + 2));
	return (-1);
}

bool	is_content_valid(int type, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ()
	return (false);
}

bool	is_line_valid(t_map *map, char *line)
{
	int	i;
	int	tmp;

	i = 0;
	while (line[i])
	{
		tmp = check_type_content(map, line);
		if (tmp != -1)
			is_content_valid(tmp, line);
		else if (line[i] == 'N' || line[i] == 'S' \
				|| line[i] == 'E' || line[i] == 'W' \
				|| line[i] == '0' || line[i] == '1')
			check_maze(line);
		else
			return (false);//err msg
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
		if (/* map->type_e && */ line[0] != '\0')
			return (false);//error msg
		is_line_valid(line);
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
	//free map->map;
}