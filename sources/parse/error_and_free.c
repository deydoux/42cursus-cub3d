/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:26:38 by mapale            #+#    #+#             */
/*   Updated: 2024/10/30 17:39:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	err_msg(char *msg)
{
	ft_putstr_fd(ERR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (0);
}

void	free_a_texture(t_p_path *textrs)
{
	int	i;

	i = 0;
	while (i < textrs->size)
	{
		if (textrs->pths[i])
			free(textrs->pths[i]);
		i++;
	}
}

void	free_textures(t_p_map *map)
{
	if (map->txtrs_pths.f_color)
		free(map->txtrs_pths.f_color);
	if (map->txtrs_pths.c_color)
		free(map->txtrs_pths.c_color);
	free_a_texture(&map->txtrs_pths.ea_path);
	free_a_texture(&map->txtrs_pths.w_path);
	free_a_texture(&map->txtrs_pths.n_path);
	free_a_texture(&map->txtrs_pths.s_path);
}

void	free_map(t_p_map *map, size_t size, char *msg)
{
	size_t	i;

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
		ft_putstr_fd(ERR, STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		exit(1);
	}
}

bool	free_all_and_exit(char *msg, t_p_map *map, int size)
{
	if (size == -1)
		size = map->map_h;
	free_map(map, size, NULL);
	free_textures(map);
	if (msg)
	{
		ft_putstr_fd(ERR, STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		exit(1);
	}
	return (false);
}
