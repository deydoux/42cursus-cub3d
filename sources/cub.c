/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:09:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/30 12:31:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	bool	status;
	t_cub	cub;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, USAGE, argv[0]);
		return (EXIT_FAILURE);
	}
	status = init(argv[1], &cub);
	if (false && !status)
		init_loop(&cub);
	destroy(cub);
	return (status);
}
