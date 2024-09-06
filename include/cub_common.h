/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:08:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/06 18:24:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_COMMON_H
# define CUB_COMMON_H
# define _GNU_SOURCE
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>

# define CUB_ERROR			"\e[31mError\e[0m\n"
# define CUB_KEY_UP			'w'
# define CUB_KEY_LEFT		'a'
# define CUB_KEY_DOWN		's'
# define CUB_KEY_RIGHT		'd'
# define CUB_PLACEHOLDER	"CUB PLACE HOLDER:"
# define CUB_SIZE			128
# define CUB_WINDOW_HEIGH	720
# define CUB_WINDOW_WIDTH	1280
# define DEG_RAD			(M_PI / 180)

typedef struct s_img
{
	int			height;
	int			width;
	int			size_line;
	uint32_t	*buffer;
	void		*ptr;
}	t_img;

typedef struct s_cub
{
	char	**map;
	double	dir;
	double	x;
	double	y;
	size_t	map_height;
	size_t	map_width;
	t_img	frame;
	t_img	minimap;
	void	*mlx;
	void	*win;
}	t_cub;

void	cub_destroy(t_cub cub);

#endif
