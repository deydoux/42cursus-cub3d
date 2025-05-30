/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:23 by deydoux           #+#    #+#             */
/*   Updated: 2024/11/29 18:57:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LOOP_H
# define INIT_LOOP_H

# include "common.h"

# ifndef HIDE_MOUSE
#  define HIDE_MOUSE	true
# endif

# define MASK_COLOR_A	0xff000000

enum e_event
{
	key_press_event = 2,
	key_release_event = 3,
	button_press_event = 4,
	focus_in_event = 9,
	focus_out_event = 10,
	destroy_notify_event = 17
};

enum e_mask
{
	key_press_mask = (1L << 0),
	key_release_mask = (1L << 1),
	button_press_mask = (1L << 2),
	structure_notify_mask = (1L << 17),
	focus_change_mask = (1L << 21)
};

int	button_press(int button, int x, int y, t_cub *cub);
int	focus_in(t_cub *cub);
int	focus_out(t_cub *cub);
int	key_press(int key, t_cub *cub);
int	key_release(int key, t_cub *cub);
int	loop(t_cub *cub);
int	quit(t_cub *cub);

#endif
