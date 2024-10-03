/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:09:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 12:59:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	bool	status;
	t_cub	cub;
	double	e = M_PI / 180;

	(void)e;
	status = init(&cub);
	if (!status)
		init_loop(&cub);
	destroy(cub);
	return (status);
	(void)argc;
	(void)argv;
}
