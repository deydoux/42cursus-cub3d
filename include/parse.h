/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:17:36 by mapale            #+#    #+#             */
/*   Updated: 2024/10/22 13:14:45 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <errno.h>
# include "common.h"

# define ERR_NO_INPUT "Error\nMap path expected\n"
# define ERR_INPUT_INVALID "Error\nWrong map type\n"
# define ERR_TEXTURE "Error\nInvalid texture\n"
# define ERR_MAP "Error\nInvalid map\n"
# define ERR_M_TEXTURE "Error\nMissing texture\n"
# define ERR_DBL_TEXTURE "Error\nDouble in textures\n"
# define ERR_MALLOC "Error\nMalloc fail\n"
# define ERR_DIMENSION "Error\nMap dimensions are wrong\n"
# define ERR_FD "Error\nOpen fail\n"
# define ERR_FILE "Error\nNo such file exist\n"
# define ERR_MAZE_INVALID_CHARAC "Error\nInvalid character in maze\n"
# define ERR_MAZE_OPEN "Error\nMaze isn't closed\n"
# define ERR_PLAYER "Error\nNo player's spawning point\n"

/*safe fctns*/
int		safe_open(char *path, t_p_map *map, int size);
void	*safe_malloc(size_t size, t_p_map *map, int h);

/* parse_init */
bool	is_input_valid(char *s);
bool	are_values_initialized(t_p_map *map, char *path);

/*pase_tools*/
int		w_isspace(char *s);
char	*ft_strdup_range(const char *s, int start, int stop);
bool	valid_txtrs_condition(t_p_map *map, char *line, int index,
			int condition);
bool	is_this_texture_valid(t_p_path *txtr);


/*parse_tools 2*/
bool	is_maze_open(t_p_map *map, char *line, int y, int x);

/*parse_doable*/
bool	is_it_flooded(t_p_map *map);
bool	can_u_play(t_p_map *map, int y, int x);

/*parse_textures*/
bool	are_textures_valid(t_p_map *map);
bool	check_textures(t_p_map *map, char *line);

/*parse_colors*/
bool	check_color(char *color, t_p_map *map, size_t i);
char	*get_color_values(t_p_map *map, char **path, char *s);

/*parse_map*/
void	create_map(t_p_map *map);
int		get_map_width(t_p_map *map);
int		get_map_height(t_p_map *map);
char	*_strdup_map(char *s, t_p_map *map, int h);
/*error*/
int		err_msg(char *msg);
void	free_map(t_p_map *map, int size, char *msg);
void	free_all_and_exit(char *msg, t_p_map *map, int size);

//TODELETE
void	print_map(t_p_map *map);
void	print_textures(t_p_map *map);
#endif
