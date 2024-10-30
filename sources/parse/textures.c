/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:08 by mapale            #+#    #+#             */
/*   Updated: 2024/10/30 18:06:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	last_textures_check(t_p_map *map, t_p_path *txtr, char *str, int i)
{
	while ((size_t)i < ft_strlen(str) && ft_isspace(str[i]))
		i++;
	if (txtr->size == SPR_MAX && (size_t)i == ft_strlen(str))
		return (free(str), free_all_and_exit(ERR_TEXTURE, map, -1));
	return (true);
}

bool	fill_texture(t_p_map *map, t_p_path *pths, char *str, int index)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			i = w_isspace(str + i);
			if (str[i] != '\0')
				free_all_and_exit(ERR_NO_BONUS, map, -1);
		}
		i++;
	}
	pths->pths[pths->size] = ft_strtrim(str + (index + 2), " \n");
	if (!pths->pths[pths->size])
		return (free(str), free_all_and_exit(ERR_MALLOC, map, -1));
	if ((*pths->pths[pths->size] == '\0' \
		|| *pths->pths[pths->size] == '\n'))
		return (free(str), free(pths->pths[pths->size]),
			free_all_and_exit(ERR, map, -1));
	pths->size = 1;
	return (true);
}

bool	fill_textures(t_p_map *map, t_p_path *txtr, char *str, size_t idx)
{
	size_t	i;
	size_t	end;
	size_t	bgn;

	i = idx + 2;
	end = 0;
	if (txtr->size != 0)
		return (free(str), free_all_and_exit(ERR_DBL_TEXTURE, map, -1));
	if (SPR_MAX == 1)
		return (fill_texture(map, txtr, str, idx));
	while ((size_t)i < ft_strlen(str) && SPR_MAX != 1 && txtr->size <= SPR_MAX)
	{
		bgn = i;
		while (str[i] && str[i] != '\t' )
			i++;
		end = i;
		txtr->pths[txtr->size++] = \
		s_cust_strtrim(map, str + bgn, " \t\n", end - bgn);
		if ((*txtr->pths[txtr->size - 1] == '\0' \
			|| *txtr->pths[txtr->size - 1] == '\n'))
			return (free(str), free_all_and_exit(ERR_TEXTURE, map, -1));
		i++;
	}
	return (last_textures_check(map, txtr, str, i));
}

bool	check_textures(t_p_map *map, char *line)
{
	size_t	i;

	i = w_isspace(line);
	if (ft_strncmp(line + i, "NO", 2) == 0)
		return (fill_textures(map, &map->txtrs_pths.n_path, line, i));
	if (ft_strncmp(line + i, "SO", 2) == 0)
		return (fill_textures(map, &map->txtrs_pths.s_path, line, i));
	if (ft_strncmp(line + i, "WE", 2) == 0)
		return (fill_textures(map, &map->txtrs_pths.w_path, line, i));
	if (ft_strncmp(line + i, "EA", 2) == 0)
		return (fill_textures(map, &map->txtrs_pths.ea_path, line, i));
	if (ft_strncmp(line + i, "F ", 2) == 0)
		if (check_color(line + (i + 2), map, 0) && map->color_count == 3)
			return (map->color_count = 0, get_color_values(map, \
			&map->txtrs_pths.f_color, line + (i + 2)));
	if (ft_strncmp(line + i, "C ", 2) == 0)
		if (check_color(line + (i + 2), map, 0) && map->color_count == 3)
			return (map->color_count = 0, get_color_values(map, \
			&map->txtrs_pths.c_color, line + (i + 2)));
	return (false);
}

bool	are_textures_valid(t_p_map *map)
{
	size_t	i;
	int		fd;
	char	*line;

	i = 0;
	fd = safe_open(map->path, map, -2);
	line = get_next_line(fd);
	while (line && (int)i < map->map_start)
	{
		while (valid_txtrs_condition(map, line, i, 1))
		{
			free(line);
			line = get_next_line(fd);
			i++;
		}
		if (!line || (int)i >= map->map_start)
			break ;
		if (valid_txtrs_condition(map, line, i, 2))
			return (free(line), free_all_and_exit(ERR_TEXTURE, map, -1));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (close(fd), true);
}
