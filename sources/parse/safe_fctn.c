/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_fctn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:11:01 by mapale            #+#    #+#             */
/*   Updated: 2024/10/21 15:32:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	*safe_malloc(size_t size, t_p_map *map, int i)
{
	void	*res;

	res = malloc(size);
	if (!res)
		free_all_and_exit(ERR_MALLOC, map, i);
	return (res);
}

int	safe_open(char *path, t_p_map *map, int size)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (size == 0)
			return (printf("%s", ERR_FD), free(map), exit(1), 1);
		if (size == -1)
			return (printf("%s", ERR_FD), exit(1), 1);
		return (free_map(map, map->map_h, ERR_FD), 1);
	}
	return (fd);
}
