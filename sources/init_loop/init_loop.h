/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:23 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/01 14:44:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LOOP_INIT_H
# define CUB_LOOP_INIT_H
# include "cub_common.h"

typedef enum e_mlx_event
{
	key_press_event = 2,
	key_release_event = 3,
	destroy_notify_event = 17
}	t_mlx_event;

typedef enum e_key
{
	key_esc = 65307
}	t_key;

typedef enum e_mask
{
	key_press_mask = (1L<<0),
	key_release_mask = (1L<<1),
	structure_notify_mask = (1L<<17)
}	t_mask;

int	loop(t_cub *cub);

#endif