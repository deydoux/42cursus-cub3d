/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:17:36 by mapale            #+#    #+#             */
/*   Updated: 2024/09/19 16:43:29 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct s_points
{
	int	x;
	int	y;
} t_points;

typedef struct s_map
{
	char	**map;
	char	*path;
	int		map_h;
	bool	t_no;
	bool	t_so;
	bool	t_we;
	bool	t_ea;
} t_map;

#endif