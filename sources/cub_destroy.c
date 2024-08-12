/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/12 14:51:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_common.h"

void	cub_destroy(t_cub cub)
{
	if (!cub.mlx)
		return ;
	mlx_destroy_display(cub.mlx);
	free(cub.mlx);
}
