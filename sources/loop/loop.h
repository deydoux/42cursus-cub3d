/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/29 14:39:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "common.h"

# define COLLISION		"1d"
# define COLOR_MASK_A	0xff000000
# define EPSILON_DIST	1e8
# define EPSILON_RAY	1e-8

typedef double	(*t_ray_calc)(double pos, double d);

typedef struct s_vec
{
	double	angle;
	double	dx;
	double	dy;
}	t_vec;

typedef struct s_ray
{
	double		d;
	double		dx;
	double		dy;
	t_pos		fix;
	t_pos		pos;
	t_vec		vec;
	t_ray_calc	dx_calc;
	t_ray_calc	dy_calc;
}	t_ray;

t_vec	pol_vec(double a);
void	clear_frame(t_cub cub);
void	copy_img(t_img src, t_img dst, int x, int y);
void	copy_minimap(t_img src, t_img dst);
void	draw_wall(size_t frame_x, int wall_h, t_ray ray, t_cub cub);
void	mouse_rot(t_cub *cub);
void	move(t_cub *cub);
void	raycasts(t_cub cub);
void	render_minimap(t_cub cub);
void	render_ray(t_ray ray, t_cub cub);

#endif
