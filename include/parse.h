/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:17:36 by mapale            #+#    #+#             */
/*   Updated: 2024/09/30 09:39:29 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

# define ERR_TEXTURES "Error\nWrong Texture given\n"

/* typedef	enum e_textures
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}; */

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
	int			map_w;
	int			map_start;
	char		player_spawn; /* initialized value is '.' */
	t_texture	textures_paths;
} t_map;

/*parse_map*/
void	create_map(t_map *map);
int	get_map_height(t_map *map);
int	get_map_width(t_map *map);

/*error*/
void	free_map_and_exit(char* msg, t_map *map);

//TODELETE
void	print_map(t_map *map);

#endif