/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop_init.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:23 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/21 16:29:54 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LOOP_INIT_H
# define CUB_LOOP_INIT_H
# include "cub_common.h"

typedef enum e_mlx_event
{
	mlx_key_press_event = 2,
	mlx_key_release_event = 3,
	mlx_destroy_notify_event = 17
}	t_mlx_event;

typedef enum e_mlx_key
{
	mlx_esc_key = 65307
}	t_mlx_key;

typedef enum e_mlx_mask
{
	mlx_key_press_mask = (1L<<0),
	mlx_key_release_mask = (1L<<1),
	mlx_structure_notify_mask = (1L<<17)
}	t_mlx_mask;

int	cub_loop(t_cub *cub);

#endif
