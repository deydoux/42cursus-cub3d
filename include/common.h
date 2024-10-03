/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:08:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 18:15:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define _GNU_SOURCE
# include "libft.h"
# include "mlx.h"
# include "config.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>

# define CUB_SIZE	64
# define DEG_RAD	0.017453292519943295
# define ERR		"\e[31mError\e[0m\n"

typedef struct s_img
{
	int			h;
	int			w_size;
	int			w;
	uint32_t	*buf;
	void		*ptr;
}	t_img;

typedef struct s_key
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
	bool	rot_left;
	bool	rot_right;
}	t_key;

typedef struct s_map
{
	char	**buf;
	size_t	h;
	size_t	w;
	t_img	img;
}	t_map;

typedef struct s_cub
{
	double	a;
	double	dx;
	double	dy;
	double	x;
	double	y;
	t_key	key;
	t_img	frame;
	t_map	map;
	void	*mlx;
	void	*win;
}	t_cub;

void	destroy(t_cub cub);

#endif
