/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:07:33 by mapale            #+#    #+#             */
/*   Updated: 2024/10/23 15:08:38 by mapale           ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < SPR_MAX)
	{
		path->pths[i] = NULL;
		i++;
	}
	path->size = 0;
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
	path_nullifing(&map->txtrs_pths.n_path);
	path_nullifing(&map->txtrs_pths.s_path);
	path_nullifing(&map->txtrs_pths.w_path);
	path_nullifing(&map->txtrs_pths.ea_path);
	map->txtrs_pths.c_color = NULL;
	map->txtrs_pths.f_color = NULL;
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
