/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:08:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/02 15:26:55 by deydoux          ###   ########.fr       */
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

# define CUB_KEY_BIND	"wasd"
# define CUB_KEY_N		4
# define CUB_SIZE		64
# define DEG_RAD		(M_PI / 180)
# define ERR			"\e[31mError\e[0m\n"
# define WIN_H			1080
# define WIN_W			1920

typedef struct s_img
{
	int			h;
	int			w_size;
	int			w;
	uint32_t	*buf;
	void		*ptr;
}	t_img;

typedef struct s_map
{
	char	**buf;
	size_t	h;
	size_t	w;
	t_img	img;
}	t_map;

typedef struct s_cub
{
	bool	keys[CUB_KEY_N];
	double	a;
	double	dx_move;
	double	dx;
	double	dy_move;
	double	dy;
	double	x;
	double	y;
	t_img	frame;
	t_map	map;
	void	*mlx;
	void	*win;
}	t_cub;

void	destroy(t_cub cub);

#endif
