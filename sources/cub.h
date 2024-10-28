/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:00:13 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/28 16:17:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "common.h"

# define USAGE "%s [map_path.cub]\n"

bool	init(char *map_path, t_cub *cub);
void	init_loop(t_cub *cub);

#endif
