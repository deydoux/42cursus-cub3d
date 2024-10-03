/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 12:45:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "common.h"

# define CUB_1_SIZE	(1.0 / CUB_SIZE)

typedef struct s_cub_ray
{
	double	a;
	double	dx;
	double	dy;
	double	x;
	double	y;
}	t_cub_ray;

void	clear_img(t_img img);
void	copy_img(t_img src, t_img dst, int x, int y);
void	draw_line(int x0, int y0, int x1, int y1, int color, t_img img);
void	raycast(t_cub cub);

#endif
