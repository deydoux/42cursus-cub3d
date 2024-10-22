/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/21 17:09:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	placeholder_parsing(t_cub *cub)
{
	cub->angle = -M_PI_2;
	cub->ceiling.raw = 0x59c0e3;
	cub->floor.raw = 0x449c36;
	cub->map.buf = malloc(sizeof(*cub->map.buf) * 15);
	cub->map.buf[0] = ft_strdup("        1111111111111111111111111");
	cub->map.buf[1] = ft_strdup("        1000000000110000000000001");
	cub->map.buf[2] = ft_strdup("        1011000001110000000000001");
	cub->map.buf[3] = ft_strdup("        1001000000000000000000001");
	cub->map.buf[4] = ft_strdup("111111111011000001110000000000001");
	cub->map.buf[5] = ft_strdup("10000000001100000111011111D111111");
	cub->map.buf[6] = ft_strdup("11110111111111011100000010001");
	cub->map.buf[7] = ft_strdup("11110111111111011101010010001");
	cub->map.buf[8] = ft_strdup("11000000110101011100000010001");
	cub->map.buf[9] = ft_strdup("10000000000000001100000010001");
	cub->map.buf[10] = ft_strdup("10000000000000001101010010001");
	cub->map.buf[11] = ft_strdup("11000001110101011111011110N0111");
	cub->map.buf[12] = ft_strdup("11110111 1110101 101111010001");
	cub->map.buf[13] = ft_strdup("11111111 1111111 111111111111");
	cub->map.buf[14] = NULL;
	cub->map.h = 14;
	cub->map.w = 33;
	cub->pos.x = 26.5;
	cub->pos.y = 11.5;
	cub->spr.n_size = 32;
	cub->spr.s_size = 32;
	cub->spr.w_size = 1;
	cub->spr.e_size = 1;
	open_img("assets/mc/nether_portal/00.xpm", cub->mlx, &cub->spr.n[0]);
	open_img("assets/mc/nether_portal/01.xpm", cub->mlx, &cub->spr.n[1]);
	open_img("assets/mc/nether_portal/02.xpm", cub->mlx, &cub->spr.n[2]);
	open_img("assets/mc/nether_portal/03.xpm", cub->mlx, &cub->spr.n[3]);
	open_img("assets/mc/nether_portal/04.xpm", cub->mlx, &cub->spr.n[4]);
	open_img("assets/mc/nether_portal/05.xpm", cub->mlx, &cub->spr.n[5]);
	open_img("assets/mc/nether_portal/06.xpm", cub->mlx, &cub->spr.n[6]);
	open_img("assets/mc/nether_portal/07.xpm", cub->mlx, &cub->spr.n[7]);
	open_img("assets/mc/nether_portal/08.xpm", cub->mlx, &cub->spr.n[8]);
	open_img("assets/mc/nether_portal/09.xpm", cub->mlx, &cub->spr.n[9]);
	open_img("assets/mc/nether_portal/10.xpm", cub->mlx, &cub->spr.n[10]);
	open_img("assets/mc/nether_portal/11.xpm", cub->mlx, &cub->spr.n[11]);
	open_img("assets/mc/nether_portal/12.xpm", cub->mlx, &cub->spr.n[12]);
	open_img("assets/mc/nether_portal/13.xpm", cub->mlx, &cub->spr.n[13]);
	open_img("assets/mc/nether_portal/14.xpm", cub->mlx, &cub->spr.n[14]);
	open_img("assets/mc/nether_portal/15.xpm", cub->mlx, &cub->spr.n[15]);
	open_img("assets/mc/nether_portal/16.xpm", cub->mlx, &cub->spr.n[16]);
	open_img("assets/mc/nether_portal/17.xpm", cub->mlx, &cub->spr.n[17]);
	open_img("assets/mc/nether_portal/18.xpm", cub->mlx, &cub->spr.n[18]);
	open_img("assets/mc/nether_portal/19.xpm", cub->mlx, &cub->spr.n[19]);
	open_img("assets/mc/nether_portal/20.xpm", cub->mlx, &cub->spr.n[20]);
	open_img("assets/mc/nether_portal/21.xpm", cub->mlx, &cub->spr.n[21]);
	open_img("assets/mc/nether_portal/22.xpm", cub->mlx, &cub->spr.n[22]);
	open_img("assets/mc/nether_portal/23.xpm", cub->mlx, &cub->spr.n[23]);
	open_img("assets/mc/nether_portal/24.xpm", cub->mlx, &cub->spr.n[24]);
	open_img("assets/mc/nether_portal/25.xpm", cub->mlx, &cub->spr.n[25]);
	open_img("assets/mc/nether_portal/26.xpm", cub->mlx, &cub->spr.n[26]);
	open_img("assets/mc/nether_portal/27.xpm", cub->mlx, &cub->spr.n[27]);
	open_img("assets/mc/nether_portal/28.xpm", cub->mlx, &cub->spr.n[28]);
	open_img("assets/mc/nether_portal/29.xpm", cub->mlx, &cub->spr.n[29]);
	open_img("assets/mc/nether_portal/30.xpm", cub->mlx, &cub->spr.n[30]);
	open_img("assets/mc/nether_portal/31.xpm", cub->mlx, &cub->spr.n[31]);
	open_img("assets/mc/nether_portal/00.xpm", cub->mlx, &cub->spr.s[0]);
	open_img("assets/mc/nether_portal/01.xpm", cub->mlx, &cub->spr.s[1]);
	open_img("assets/mc/nether_portal/02.xpm", cub->mlx, &cub->spr.s[2]);
	open_img("assets/mc/nether_portal/03.xpm", cub->mlx, &cub->spr.s[3]);
	open_img("assets/mc/nether_portal/04.xpm", cub->mlx, &cub->spr.s[4]);
	open_img("assets/mc/nether_portal/05.xpm", cub->mlx, &cub->spr.s[5]);
	open_img("assets/mc/nether_portal/06.xpm", cub->mlx, &cub->spr.s[6]);
	open_img("assets/mc/nether_portal/07.xpm", cub->mlx, &cub->spr.s[7]);
	open_img("assets/mc/nether_portal/08.xpm", cub->mlx, &cub->spr.s[8]);
	open_img("assets/mc/nether_portal/09.xpm", cub->mlx, &cub->spr.s[9]);
	open_img("assets/mc/nether_portal/10.xpm", cub->mlx, &cub->spr.s[10]);
	open_img("assets/mc/nether_portal/11.xpm", cub->mlx, &cub->spr.s[11]);
	open_img("assets/mc/nether_portal/12.xpm", cub->mlx, &cub->spr.s[12]);
	open_img("assets/mc/nether_portal/13.xpm", cub->mlx, &cub->spr.s[13]);
	open_img("assets/mc/nether_portal/14.xpm", cub->mlx, &cub->spr.s[14]);
	open_img("assets/mc/nether_portal/15.xpm", cub->mlx, &cub->spr.s[15]);
	open_img("assets/mc/nether_portal/16.xpm", cub->mlx, &cub->spr.s[16]);
	open_img("assets/mc/nether_portal/17.xpm", cub->mlx, &cub->spr.s[17]);
	open_img("assets/mc/nether_portal/18.xpm", cub->mlx, &cub->spr.s[18]);
	open_img("assets/mc/nether_portal/19.xpm", cub->mlx, &cub->spr.s[19]);
	open_img("assets/mc/nether_portal/20.xpm", cub->mlx, &cub->spr.s[20]);
	open_img("assets/mc/nether_portal/21.xpm", cub->mlx, &cub->spr.s[21]);
	open_img("assets/mc/nether_portal/22.xpm", cub->mlx, &cub->spr.s[22]);
	open_img("assets/mc/nether_portal/23.xpm", cub->mlx, &cub->spr.s[23]);
	open_img("assets/mc/nether_portal/24.xpm", cub->mlx, &cub->spr.s[24]);
	open_img("assets/mc/nether_portal/25.xpm", cub->mlx, &cub->spr.s[25]);
	open_img("assets/mc/nether_portal/26.xpm", cub->mlx, &cub->spr.s[26]);
	open_img("assets/mc/nether_portal/27.xpm", cub->mlx, &cub->spr.s[27]);
	open_img("assets/mc/nether_portal/28.xpm", cub->mlx, &cub->spr.s[28]);
	open_img("assets/mc/nether_portal/29.xpm", cub->mlx, &cub->spr.s[29]);
	open_img("assets/mc/nether_portal/30.xpm", cub->mlx, &cub->spr.s[30]);
	open_img("assets/mc/nether_portal/31.xpm", cub->mlx, &cub->spr.s[31]);
	open_img("assets/mc/obsidian.xpm", cub->mlx, &cub->spr.w[0]);
	open_img("assets/mc/obsidian.xpm", cub->mlx, &cub->spr.e[0]);
	return (false);
}

static bool	init_mlx(void **mlx)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd(ERR MLX_INIT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	init_win(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WIN_W, WIN_H, "placeholder: map file");
	if (!*win)
	{
		ft_putstr_fd(ERR WIN_INIT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	init(t_cub *cub)
{
	ft_bzero(cub, sizeof(*cub));
	if (init_mlx(&cub->mlx) || new_img(MAP_H, MAP_W, cub->mlx, &cub->minimap))
		return (true);
	fill_img(MAP_COLOR_WALL, cub->minimap);
	return (placeholder_parsing(cub)
		|| new_img(WIN_H, WIN_W, cub->mlx, &cub->frame)
		|| init_map_img(cub) || init_win(cub->mlx, &cub->win));
}
