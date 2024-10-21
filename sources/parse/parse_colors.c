/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:27:53 by mapale            #+#    #+#             */
/*   Updated: 2024/10/21 15:32:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	get_color_valid_arg(char *color)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (!ft_isspace(color[i]))
			count++;
		i++;
	}
	return (count);
}

char	*get_color_values(t_p_map *map, char **path, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*path)
		free_all_and_exit(ERR_DBL_TEXTURE, map, -1);
	*path = malloc(sizeof(char) * (get_color_valid_arg(s) + 1));
	if (!*path)
		free_all_and_exit(ERR_MALLOC, map, -1);
	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			(*path)[j] = s[i];
			j++;
		}
		i++;
	}
	(*path)[j] = '\0';
	return (*path);
}


static bool	precheck(char *color)
{
	int	i;

	i = 0;
	if (color[ft_strlen(color) - 2] < '0' || color[ft_strlen(color) - 2] > '9')
		return (false);
	while (ft_isspace(color[i]))
		i++;
	while ((size_t)i < ft_strlen(color) && color[i])
	{
		if ((color[i] < '0' && color[i] > '9') && color[i] != ',')
			return (false);
		i++;
	}
	return (true);
}

bool	check_color(char *color, t_p_map *map, size_t i)
{
	size_t	start;
	int		tmp;
	char	*nbr;

	start = 0;
	tmp = 0;
	if (!precheck(color))
		return (false);
	if (i >= ft_strlen(color))
		return (true);
	while (ft_isspace(color[i]))
		i++;
	start = i;
	while (color[i] >= '0' && color[i] <= '9')
		i++;
	nbr = ft_strdup_range(color, start, i);
	tmp = ft_atoi(nbr);
	if (tmp < 0 || tmp > 255 || (tmp == 0 && color[i - 1] != '0'))
		return (free(nbr), false);
	free(nbr);
	while (ft_isspace(color[i]))
		i++;
	if (i < ft_strlen(color) && color[i + 1] != '\0' && color[i] != ',')
		return (false);
	return (map->color_count += 1, check_color(color, map, i + 1));
}
