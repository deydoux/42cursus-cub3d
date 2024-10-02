/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/02 15:28:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LOOP_H
# define CUB_LOOP_H

# include "cub_common.h"

# define CUB_1_SIZE	(1.0 / CUB_SIZE)

enum e_cub_key
{
	cub_key_up,
	cub_key_left,
	cub_key_down,
	cub_key_right
};

typedef struct s_cub_ray
{
	double	a;
	double	dx;
	double	dy;
	double	x;
	double	y;
}	t_cub_ray;

void	draw_line(int x0, int y0, int x1, int y1, int color, t_img img);
void	clear_img(t_img img);
void	copy_img(t_img src, t_img dst, int x, int y);
void	raycast(t_cub cub);

#endif
