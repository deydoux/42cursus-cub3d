/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:26:38 by mapale            #+#    #+#             */
/*   Updated: 2024/10/17 17:15:10 by mapale           ###   ########.fr       */
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

void	free_textures(t_map *map)
{
	free_a_texture(map->txtrs_paths.f_color);
	free_a_texture(map->txtrs_paths.c_color);
	free_a_texture(map->txtrs_paths.ea_path);
	free_a_texture(map->txtrs_paths.w_path);
	free_a_texture(map->txtrs_paths.n_path);
	free_a_texture(map->txtrs_paths.s_path);
}

void	free_map(t_map *map, int size, char *msg)
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

void	free_all_and_exit(char *msg, t_map *map, int size)
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
