/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_pol_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:19:54 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 18:21:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

t_pol_vec	null_pol_vec(void)
{
	return ((t_pol_vec){
		.dx = 0,
		.dy = 0
	});
}