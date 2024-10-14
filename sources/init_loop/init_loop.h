/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:23 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 12:39:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LOOP_H
# define INIT_LOOP_H

# include "common.h"

enum e_event
{
	key_press_event = 2,
	key_release_event = 3,
	focus_in_event = 9,
	focus_out_event = 10,
	destroy_notify_event = 17
};

enum e_mask
{
	key_press_mask = (1L<<0),
	key_release_mask = (1L<<1),
	structure_notify_mask = (1L<<17),
	focus_change_mask = (1L<<21)
};

int	loop(t_cub *cub);

#endif
