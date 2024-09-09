/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:08:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/09 13:11:26 by deydoux          ###   ########.fr       */
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

# define CUB_ERR		"\e[31mError\e[0m\n"
# define CUB_KEY_BIND	"zqsd"
# define CUB_KEY_N		4
# define CUB_PH			"CUB PLACE HOLDER:"
# define CUB_SIZE		64
# define CUB_WIN_H		720
# define CUB_WIN_W		1280
# define DEG_RAD		(M_PI / 180)

typedef struct s_cub_img
{
	int			h;
	int			w_size;
	int			w;
	uint32_t	*buf;
	void		*ptr;
}	t_cub_img;

typedef struct s_cub_map
{
	char		**buf;
	size_t		h;
	size_t		w;
	t_cub_img	img;
}	t_cub_map;

typedef struct s_cub
{
	bool		keys[CUB_KEY_N];
	double		a;
	double		dx;
	double		dy;
	double		x;
	double		y;
	t_cub_img	frame;
	t_cub_map	map;
	void		*mlx;
	void		*win;
}	t_cub;

void	cub_destroy(t_cub cub);

#endif
