/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:51:19 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/28 21:10:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_walls(t_graph *lst)
{
	rotate_player(lst);
	player_movement(lst);
	cast_rays(lst);
}

void	my_mlx_pixel_put(t_graph *lst, int x, int y, int color)
{
	char	*test;

	if ((x >= 0 && x < lst->map.width) && (y >= 0 && y < lst->map.height))
	{
		test = &lst->map.addr[(y * lst->map.size_line) + \
		(x * lst->map.bpp / 8)];
		*(unsigned int *)test = color;
	}
}
