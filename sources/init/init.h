/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:21 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 14:28:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "common.h"

# define MAX_IMG_DIM	32767
# define MAX_IMG_PIXEL	536107716
# define MLX_INIT_ERR	"Failed to initialize MLX\n"
# define NEW_IMG_ERR	"Failed to init images\n"
# define OPEN_IMG_ERR	"Failed to open %s image\n"
# define WIN_INIT_ERR	"Failed to initialize window\n"

# define USAGE "Usage: %s [options]... [map].cub\n\
  -h, --help\t\tDisplay this help message\n\
  -k, --keys <keys>\tSet keybindings (Default: wasd)\n"

bool	init_map_img(t_cub *cub);
bool	init_mlx(void **mlx);
bool	new_img(int height, int width, void *mlx, t_img *img);
bool	open_img(char *path, void *mlx, t_img *img);
bool	parse(t_p_map *map, char *path);
bool	use_parse(char *map_path, t_cub *cub);
char	*handle_args(int argc, char **argv, t_cub *cub);
void	fill_img(uint32_t raw_color, t_img img);
void	init_img(t_img *img);

#endif
