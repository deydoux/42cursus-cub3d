/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:08:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/18 16:30:07 by deydoux          ###   ########.fr       */
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

# ifndef BONUS
#  define BONUS		false
#  define SPR_MAX	1
# endif

# define DEG_RAD	0.017453292519943295
# define ERR		"\e[31mError\e[0m\n"

typedef union u_color
{
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
	uint32_t	raw;
}	t_color;

typedef struct s_img
{
	int		h;
	int		w_size;
	int		w;
	size_t	size;
	t_color	*buf;
	void	*ptr;
}	t_img;

typedef struct s_key
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
	bool	sprint;
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

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_spr
{
	size_t	n_size;
	size_t	s_size;
	size_t	w_size;
	size_t	e_size;
	t_img	n[SPR_MAX];
	t_img	s[SPR_MAX];
	t_img	w[SPR_MAX];
	t_img	e[SPR_MAX];
}	t_spr;

typedef struct s_cub
{
	bool	focus;
	double	angle;
	size_t	i;
	t_color	ceiling;
	t_color floor;
	t_img	frame;
	t_img	minimap;
	t_key	key;
	t_map	map;
	t_pos	pos;
	t_spr	spr;
	void	*mlx;
	void	*win;
}	t_cub;

t_color	*read_img(t_img img, size_t x, size_t y);
void	destroy(t_cub cub);

#endif
