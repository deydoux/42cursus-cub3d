/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_fctn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:11:01 by mapale            #+#    #+#             */
/*   Updated: 2024/10/25 11:07:18 by mapale           ###   ########.fr       */
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

char	*custom_strtrim(char const *s1, char const *set, size_t end)
{
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

char	*s_cust_strtrim(t_p_map *map, char const *s1,
			char const *set, size_t end)
{
	char	*tmp;

	tmp = custom_strtrim(s1, set, end);
	if (!tmp)
		free_all_and_exit(ERR_DBL_TEXTURE, map, -1);
	return (tmp);
}
