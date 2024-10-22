/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initialise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:07:33 by mapale            #+#    #+#             */
/*   Updated: 2024/10/22 11:14:05 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

void	path_nullifing(t_p_path *path)
{
/* 	int	i;

	i = 0;
	while (i < SPR_MAX)
	{
		path->paths[i] = NULL;
		i++;
	} */
	path->nb_paths = 0;
}

bool	are_values_initialized(t_p_map *map, char *path)
{
	int	i;

	i = 0;
	map->path = path;
	map->map_h = 0;
	map->map_w = 0;
	map->player.spawn = '.';
	map->color_count = 0;
	path_nullifing(&map->txtrs_paths.n_path);
	path_nullifing(&map->txtrs_paths.s_path);
	path_nullifing(&map->txtrs_paths.w_path);
	path_nullifing(&map->txtrs_paths.ea_path);
	map->txtrs_paths.c_color = NULL;
	map->txtrs_paths.f_color = NULL;
	get_map_height(map);
	get_map_width(map);
	if (map->map_h <= 0 || map->map_w <= 0 \
		|| map->map_h > 200 || map->map_w > 200)
		return (printf("%s", ERR_DIMENSION), false);
	map->map = malloc(sizeof(char *) * map->map_h);
	if (!map->map)
		return (printf("%s", ERR_MALLOC), false);
	return (true);
}
