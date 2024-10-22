/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:24:05 by mapale            #+#    #+#             */
/*   Updated: 2024/10/21 15:32:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_in_s(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == '\n')
			i++;
		if (c == '\0' || s[i] == c || c == '\n')
			return (false);
		i++;
	}
	return (true);
}

void	transform(char *c)
{
	if ((*c) == '0')
		(*c) = '.';
	if (BONUS && (*c) == 'D')
		(*c) = 'd';
}

bool	can_u_play(t_p_map *map, int y, int x)
{
	if ((x < 0 || y < 0 || x > map->map_w || y > map->map_h - 1))
		return (false);
	if ((x == 0 || y == 0 || x == map->map_w || y == map->map_h) \
		&& map->map[y][x] != '1')
		return (false);
	if (map->map[y][x] == '.' || (BONUS && map->map[y][x] == 'd'))
		return (true);
	if (map->map[y][x] != '1' && map->map[y][x] != map->player.spawn \
		&& map->map[y][x] != '0' && (BONUS && map->map[y][x] != 'D'))
		return (false);
	if (map->map[y][x] == '0' || map->map[y][x] == map->player.spawn \
		|| (BONUS && map->map[y][x] == 'D') \
	)
	{
		transform(&map->map[y][x]);
		if (!can_u_play(map, y + 1, x))
			return (false);
		if (!can_u_play(map, y - 1, x))
			return (false);
		if (!can_u_play(map, y, x + 1))
			return (false);
		if (!can_u_play(map, y, x - 1))
			return (false);
	}
	return (true);
}
