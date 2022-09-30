/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/30 21:52:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

static int	texturevalid(void)
{
	int	fd;

	fd = open("srcs/textures/door1.xpm", O_RDONLY);
	if (fd < 0)
		return (write(1, "error!! door picture missing file\n", 35), 1);
	close(fd);
	fd = open("srcs/textures/door2.xpm", O_RDONLY);
	if (fd < 0)
		return (write(1, "error!! door picture missing file\n", 35), 1);
	close(fd);
	fd = open("srcs/textures/door3.xpm", O_RDONLY);
	if (fd < 0)
		return (write(1, "error!! door picture missing file\n", 35), 1);
	close(fd);
	fd = open("srcs/textures/door1.xpm", O_RDONLY);
	if (fd < 0)
		return (write(1, "error!! door picture missing file\n", 35), 1);
	close(fd);
	fd = open("srcs/textures/chest.xpm", O_RDONLY);
	if (fd < 0)
		return (write(1, "error!! chest picture missing file\n", 36), 1);
	close(fd);
	return (0);
}

void	executor(t_map_ *data)
{
	t_graph	lst;

	lst.data = data;
	init_map(&lst, data);
	init_player(&lst, data);
	init_raycast(&lst);
	init_everything(&lst, data);
	if (texturevalid())
		return ;
	init_texture(&lst, data);
	init_sprite(&lst);
	init_door(&lst);
	mlx_loop_hook(lst.mlx, routine, &lst);
	mlx_loop(lst.mlx);
}
