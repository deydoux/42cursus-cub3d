/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:21 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/02 15:27:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_INIT_H
# define CUB_INIT_H

# include "cub_common.h"

# define MAX_IMG_DIM	32767
# define MAX_IMG_PIXEL	536107716
# define MLX_INIT_ERR	ERR "Failed to initialize MLX\n"
# define WIN_INIT_ERR	ERR "Failed to initialize window\n"

bool	init_map_img(t_cub *cub);
bool	new_img(int height, int width, void *mlx, t_img *img);

#endif
