/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 02:27:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "common.h"

# define EPSILON_DIST	1e14
# define EPSILON_RAY	1e-8

typedef double	(*t_ray_calc)(double pos, double d);

typedef struct s_vec
{
	double	angle;
	double	dx;
	double	dy;
	double	len;
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
void	copy_img(t_img src, t_img dst, int x, int y);
void	draw_wall(int frame_x, int wall_h, t_ray ray, t_cub cub);
void	move(t_cub *cub);
void	raycasts(t_cub cub);

#endif
