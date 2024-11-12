/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:18 by mapale            #+#    #+#             */
/*   Updated: 2024/11/12 11:54:35 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	w_isspace(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i);
}

char	*ft_strdup_range(const char *s, int start, int stop)
{
	int		i;
	int		size;
	char	*tab;

	i = 0;
	size = (stop - start) + 1;
	tab = (char *)malloc(sizeof(char) * (size));
	if (!tab)
		return ((char *) NULL);
	while (start < stop)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

bool	valid_txtrs_condition(t_p_map *map, char *line, size_t index,
	int condition)
{
	if (condition == 1 && line && (int)index < map->map_start
		&& w_isspace(line) == ft_strlen(line))
		return (true);
	if (condition == 2 && !check_textures(map, line) && line[0] != '\0'
		&& (int)index >= map->map_start)
		return (true);
	return (false);
}

bool	is_this_texture_valid(t_p_path *txtr)
{
	int	i;

	i = 0;
	if (txtr->size == 0)
		return (false);
	while (i < txtr->size)
	{
		if (!txtr->pths[i])
			return (false);
		i++;
	}
	return (true);
}
