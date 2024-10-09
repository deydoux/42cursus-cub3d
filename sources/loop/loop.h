/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 16:31:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "common.h"

# define EPSILON	1e-8

typedef double	(*t_ray_calc)(double pos, double d);

typedef struct s_ray
{
	double		d;
	double		dx;
	double		dy;
	t_pos		fix;
	t_pos		pos;
	t_ray_calc	dx_calc;
	t_ray_calc	dy_calc;
}	t_ray;

typedef struct s_pol_vec
{
	double	a;
	double	dx;
	double	dy;
}	t_pol_vec;

t_pol_vec	null_pol_vec(void);
t_pol_vec	pol_vec(double a);
void		copy_img(t_img src, t_img dst, int x, int y);
void		move(t_cub *cub);
void		raycasts(t_cub cub);

#endif
