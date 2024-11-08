/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:17:36 by mapale            #+#    #+#             */
/*   Updated: 2024/11/08 15:29:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <errno.h>
# include "common.h"

# define ERR_INPUT_INVALID "Wrong map type\n"
# define ERR_TEXTURE "Invalid texture\n"
# define ERR_MAP "Invalid map\n"
# define ERR_M_TEXTURE "Missing texture\n"
# define ERR_DBL_TEXTURE "Double in textures\n"
# define ERR_MALLOC "Malloc fail\n"
# define ERR_DIMENSION "Map dimensions are wrong\n"
# define ERR_FD "Open fail\n"
# define ERR_FILE "No such file exist\n"
# define ERR_MAZE_INVALID_CHARAC "Invalid character in maze\n"
# define ERR_MAZE_OPEN "Maze isn't closed\n"
# define ERR_PLAYER "No player's spawning point\n"
# define ERR_NO_BONUS "Only one texture is allowed per direction\n"

/*custom fctns*/
char	*s_cust_strtrim(t_p_map *map, char const *s1,
			char const *set, size_t end);
int		safe_open(char *path, t_p_map *map, int size);
void	*safe_malloc(size_t size, t_p_map *map, int h);
void	safe_close(int fd);
char	*custom_strtrim(char const *s1, char const *set, size_t end);

/* parse_init */
bool	is_input_valid(char *s);
bool	are_values_initialized(t_p_map *map, char *path);

/*pase_tools*/
size_t	w_isspace(char *s);
char	*ft_strdup_range(const char *s, int start, int stop);
bool	valid_txtrs_condition(t_p_map *map, char *line, size_t index,
			int condition);
bool	is_this_texture_valid(t_p_path *txtr);
bool	is_maze_open(t_p_map *map, char *line, int y, int x);

/*parse_doable*/
bool	can_u_play(t_p_map *map, int y, int x);

/*parse_textures*/
bool	are_textures_valid(t_p_map *map);
bool	check_textures(t_p_map *map, char *line);
char	*custom_strtrim(char const *s1, char const *set, size_t end);

/*parse_colors*/
bool	check_color(char *color, t_p_map *map, size_t i);
char	*get_color_values(t_p_map *map, char **path, char *s, char *line);

/*parse_map*/
void	create_map(t_p_map *map);
int		get_map_width(t_p_map *map);
int		get_map_height(t_p_map *map);
char	*_strdup_map(char *s, t_p_map *map, size_t h);
/*error*/
int		err_msg(char *msg);
void	free_map(t_p_map *map, size_t size, char *msg);
bool	free_all_and_exit(char *msg, t_p_map *map, int size);

//TODELETE
void	print_map(t_p_map *map);
void	print_textures(t_p_map *map);
#endif
