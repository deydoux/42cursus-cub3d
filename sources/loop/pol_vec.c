/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pol_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:24:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 15:43:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

t_pol_vec	pol_vec(double a)
{
	return ((t_pol_vec){
		.a = a,
		.dx = cos(a),
		.dy = sin(a)
	});
}