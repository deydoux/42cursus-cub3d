/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:07:33 by mapale            #+#    #+#             */
/*   Updated: 2024/11/03 14:02:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_input_valid(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	if (i <= 4)
		return (false);
	if (s[i - 1] == 'b' && s[i - 2] == 'u' && s[i - 3] == 'c'
		&& s[i - 4] == '.')
		return (true);
	return (false);
}

void	path_nullifing(t_p_path *path)
{
	size_t	i;

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
	if (map->map_h <= 0 || map->map_w <= 0 || map->map_h > 200
		|| map->map_w > 200)
		return (ft_putstr_fd(ERR ERR_DIMENSION, STDERR_FILENO), false);
	map->map = ft_calloc(map->map_h + 1, sizeof(char *));
	if (!map->map)
		return (ft_putstr_fd(ERR ERR_MALLOC, STDERR_FILENO), false);
	return (true);
}
