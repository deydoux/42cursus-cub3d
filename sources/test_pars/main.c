/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:11:49 by mapale            #+#    #+#             */
/*   Updated: 2024/09/19 16:51:50 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "cub.h"

int	check_input(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i <= 4)
		return (0);
	if (s[i - 1] == 'b' && s[i - 2] == 'u' && s[i - 3] == 'c' \
	&& s[i - 4] == '.')
		return (1);
	return (0);
}

bool	init(t_parse *map, char *path)
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

bool	map_check(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		return (fd);
	line = get_next_line(fd);
	while (line)
	{
		check_input();
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
	if (!check_input(av[1]))
		return (1);//err msg type
	//free map->map;
}