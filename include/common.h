/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:08:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/25 13:18:22 by mapale           ###   ########.fr       */
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
#  undef SPR_MAX
#  define SPR_MAX	1
# endif

# define DEG_RAD	0.017453292519943295
# define ERR		"\e[31mError\e[0m\n"

typedef struct s_p_path
{
	char	*pths[SPR_MAX];
	int		size;
}	t_p_path;

typedef struct s_p_textures
{
	t_p_path	n_path;
	t_p_path	s_path;
	t_p_path	w_path;
	t_p_path	ea_path;
	char		*c_color;
	char		*f_color;
}	t_p_textures;

typedef struct s_player
{
	char	spawn; /* initialized value is '.' */
	int		x	;
	int		y;
}	t_player;

typedef struct s_p_map
{
	char			**map;
	char			*path;
	int				map_h;
	int				map_w;
	int				map_start;
	t_player		player;
	t_p_textures	txtrs_pths;
	int				color_count;
}	t_p_map;

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
	t_p_map	parsed_map;
	t_map	map;
	t_pos	pos;
	t_spr	spr;
	void	*mlx;
	void	*win;
}	t_cub;

t_color	*read_img(t_img img, size_t x, size_t y);
void	draw_map_square(size_t x, size_t y, uint32_t raw_color, t_img img);
void	destroy(t_cub cub);

#endif
