/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:26:38 by mapale            #+#    #+#             */
/*   Updated: 2024/10/21 16:24:05 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	err_msg(char *msg)
{
	printf("%s", msg);
	return (EXIT_FAILURE);
}

void	free_a_texture(char *textrs)
{
	if (textrs)
		free(textrs);
}

void	free_textures(t_p_map *map)
{
	size_t	i;

	free_a_texture(map->txtrs_paths.f_color);
	free_a_texture(map->txtrs_paths.c_color);
	i = 0;
	while (i < SPR_MAX)
	{
		free_a_texture(&map->txtrs_paths.ea_path.paths[i]);
		free_a_texture(&map->txtrs_paths.w_path.paths[i]);
		free_a_texture(&map->txtrs_paths.n_path.paths[i]);
		free_a_texture(&map->txtrs_paths.s_path.paths[i]);
	}
}

void	free_map(t_p_map *map, int size, char *msg)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	free(map->map);
	if (msg)
	{
		printf("%s", msg);
		exit(1);
	}
}

void	free_all_and_exit(char *msg, t_p_map *map, int size)
{
	if (size == -1)
		size = map->map_h;
	free_map(map, size, NULL);
	free_textures(map);
	if (msg)
	{
		printf("%s", msg);
		exit(1);
	}
}
