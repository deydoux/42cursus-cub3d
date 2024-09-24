/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:17:36 by mapale            #+#    #+#             */
/*   Updated: 2024/09/24 16:47:55 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

typedef	enum e_textures
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
};

typedef struct s_texture
{
	char *north_path;
	char *south_path;
	char *west_path;
	char *east_path;
} t_texture;

typedef struct s_points
{
	int	x;
	int	y;
} t_points;

typedef struct s_map
{
	char		**map;
	char		*path;
	int			map_h;
	t_texture	textures_paths;
	
} t_map;

#endif