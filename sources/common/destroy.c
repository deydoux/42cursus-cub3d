/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/02 15:43:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	destroy(t_cub cub)
{
	if (!cub.mlx)
		return ;
	if (cub.frame.ptr)
		mlx_destroy_image(cub.mlx, cub.frame.ptr);
	if (cub.map.img.ptr)
		mlx_destroy_image(cub.mlx, cub.map.img.ptr);
	mlx_destroy_display(cub.mlx);
	free(cub.mlx);
}
