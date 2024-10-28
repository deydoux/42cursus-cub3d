/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:09:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/25 13:17:55 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	bool	status;
	t_cub	cub;

	if (argc != 2)
		return (err_msg(ERR_NO_INPUT));
	if (!parse(&cub.parsed_map, argv))
		return (EXIT_FAILURE);
	status = init(&cub);
	if (!status)
		init_loop(&cub);
	destroy(cub);
	return (status);
}
