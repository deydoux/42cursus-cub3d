/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:09:12 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 14:23:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	bool	status;
	t_cub	cub;

	status = init(argc, argv, &cub);
	if (!status)
		init_loop(&cub);
	destroy(cub);
	return (status);
}
