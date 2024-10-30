/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:18:16 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/30 16:32:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	copy_parsed_player(t_player player, t_cub *cub)
{
	if (player.spawn == 'N')
		cub->angle = -M_PI_2;
	else if (player.spawn == 'S')
		cub->angle = M_PI_2;
	else if (player.spawn == 'W')
		cub->angle = M_PI;
	else if (player.spawn == 'E')
		cub->angle = 0;
	cub->pos = (t_pos){.x = player.x + .5, .y = player.y + .5};
}

static bool	open_textures(t_p_textures txtr, t_cub *cub)
{
	size_t	i;

	cub->spr.n_size = txtr.n_path.size;
	cub->spr.s_size = txtr.s_path.size;
	cub->spr.w_size = txtr.w_path.size;
	cub->spr.e_size = txtr.ea_path.size;
	i = 0;
	while (i < SPR_MAX)
	{
		if (i < cub->spr.n_size && open_img(txtr.n_path.pths[i], cub->mlx,
				&cub->spr.n[i]))
			return (true);
		if (i < cub->spr.s_size && open_img(txtr.s_path.pths[i], cub->mlx,
				&cub->spr.s[i]))
			return (true);
		if (i < cub->spr.w_size && open_img(txtr.w_path.pths[i], cub->mlx,
				&cub->spr.w[i]))
			return (true);
		if (i < cub->spr.e_size && open_img(txtr.ea_path.pths[i], cub->mlx,
				&cub->spr.e[i]))
			return (true);
		i++;
	}
	return (false);
}

static void	free_txtrs(t_p_textures txtr)
{
	int	i;

	i = 0;
	while (i < SPR_MAX)
	{
		if (i < txtr.n_path.size)
			free(txtr.n_path.pths[i]);
		if (i < txtr.s_path.size)
			free(txtr.s_path.pths[i]);
		if (i < txtr.w_path.size)
			free(txtr.w_path.pths[i]);
		if (i < txtr.ea_path.size)
			free(txtr.ea_path.pths[i]);
		i++;
	}
	free(txtr.c_color);
	free(txtr.f_color);
}

static t_color	parse_color(char *str)
{
	t_color	color;

	color.r = ft_atoi(str);
	str = ft_strchr(str, ',') + 1;
	color.g = ft_atoi(str);
	str = ft_strchr(str, ',') + 1;
	color.b = ft_atoi(str);
	return (color);
}

bool	use_parse(char *map_path, t_cub *cub)
{
	bool	status;
	t_p_map	p_map;

	if (!parse(&p_map, map_path) || init_mlx(&cub->mlx))
		return (true);
	cub->map.buf = p_map.map;
	cub->map.h = p_map.map_h;
	cub->map.w = p_map.map_w;
	cub->ceiling = parse_color(p_map.txtrs_pths.c_color);
	cub->floor = parse_color(p_map.txtrs_pths.f_color);
	copy_parsed_player(p_map.player, cub);
	status = open_textures(p_map.txtrs_pths, cub);
	free_txtrs(p_map.txtrs_pths);
	return (status);
}
