/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:21 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 14:40:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	put_usage(char *program, int status)
{
	ft_dprintf(STDERR_FILENO, USAGE, program);
	exit(status);
}

static char	*get_filename(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len < 4 || ft_strcmp(arg + len - 4, ".cub"))
		put_usage(arg, EXIT_FAILURE);
	return (arg);
}

char	*handle_args(int argc, char **argv, t_cub *cub)
{
	char	*map_path;
	int		i;

	map_path = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-h")
			|| !ft_strcmp(argv[i], "--help"))
			put_usage(argv[0], EXIT_SUCCESS);
		else if (!ft_strcmp(argv[i], "-k")
			|| !ft_strcmp(argv[i], "--keys"))
		{
			if (++i >= argc || ft_strlen(argv[i]) != 4)
				put_usage(argv[0], EXIT_FAILURE);
			ft_memcpy(cub->key.bind, argv[i], 4);
		}
		else
			map_path = get_filename(argv[i]);
		i++;
	}
	if (!map_path)
		put_usage(argv[0], EXIT_FAILURE);
	return (map_path);
}
