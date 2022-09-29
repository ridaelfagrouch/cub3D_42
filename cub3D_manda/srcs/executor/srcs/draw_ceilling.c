/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:21:14 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/28 21:17:55 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_cub1(int y, int y1, t_graph *lst, int i)
{
	int	j;
	int	x1;

	x1 = lst->map.width;
	while (y < y1)
	{
		j = 0;
		while (j <= x1)
		{
			my_mlx_pixel_put(lst, j, y, i);
			j++;
		}
		y++;
	}
}

void	draw_floor_ceilling(t_graph *lst)
{
	double	i;

	i = (lst->map.height) / 2;
	draw_cub1(0, i, lst, lst->map.player_color);
	draw_cub1(i, lst->map.height, lst, lst->map.floor_color);
}
