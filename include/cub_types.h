/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:57:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/12 18:41:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TYPES_H
# define CUB_TYPES_H
# include <stdint.h>

typedef struct s_img
{
	int			height;
	int			width;
	int			size_line;
	uint32_t	*buffer;
	void		*ptr;
}	t_img;

typedef enum e_orient
{
	e,
	n,
	w,
	s
}	t_orient;

typedef struct s_cub
{
	char	**map;
	double	dir;
	double	x;
	double	y;
	t_img	frame;
	void	*mlx;
	void	*win;
}	t_cub;

#endif
