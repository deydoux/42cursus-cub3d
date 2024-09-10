/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/10 20:14:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LOOP_H
# define CUB_LOOP_H
# include "cub_common.h"

# define CUB_1_SIZE	(1. / CUB_SIZE)

typedef enum e_cub_key
{
	cub_key_up,
	cub_key_left,
	cub_key_down,
	cub_key_right
}	t_cub_key;

typedef struct s_cub_ray
{
	double	a;
	double	dx;
	double	dy;
	double	x;
	double	y;
}	t_cub_ray;


#endif
