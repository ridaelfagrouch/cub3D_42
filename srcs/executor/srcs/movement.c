/* ************************************************************************** */
/*                                a                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/05 16:43:06 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int routine(t_graph *lst)
{
    mlx_hook(lst->wind, 2, 0L, deal_key, lst);
	mlx_hook(lst->wind, 3, 0L, reset, lst);
	mlx_destroy_image(lst->mlx, lst->map.img);
	mlx_clear_window(lst->mlx, lst->wind);
	lst->map.img = mlx_new_image(lst->mlx, lst->map.width, lst->map.height);
    lst->map.addr = mlx_get_data_addr(lst->map.img, &lst->map.bpp, &lst->map.size_line, &lst->map.endian);
	draw_floor_ceilling(lst);
	// draw_map(lst->map.map, lst);
    draw_walls(lst);
	mlx_put_image_to_window(lst->mlx, lst->wind, lst->map.img, 0, 0);
	return (0);
}

int	reset(int key, t_graph *var)
{
	if (key == 124)
		var->plyr.rotatedirection = 0;
	if (key == 123)
		var->plyr.rotatedirection = 0;
	if (key == 13)
		var->plyr.walkdirection = 0;
	if (key == 1)
		var->plyr.walkdirection = 0;
	if (key == 2)
		var->plyr.walkdirection = 0;
	if (key == 0)
		var->plyr.walkdirection = 0;
	return (0);
}

int	check_wall(t_graph *lst, int x, int y)
{
	int i;
	int	pos1;
	int	pos2;

	i = 0;
	pos1 = x / lst->map.unit;
	pos2 = y / lst->map.unit;
	if ((pos1 >= 0 && pos1 < lst->x) && (pos2 >= 0 && pos2 < lst->y))
	{
		if (lst->map.map[pos2] && lst->map.map[pos2][pos1] && lst->map.map[pos2][pos1] == '1')
			return (1);
	}
	return (0);
}

int	check_wall_movement(t_graph *lst, int x, int y, int x1, int y1)
{
	int	posPx;
	int	posPy;
	int	posDx;
	int	posDy;

	posPx = x / lst->map.unit;
	posPy = y / lst->map.unit;
	posDx = x1 / lst->map.unit;
	posDy = y1 / lst->map.unit;

	// if ((pos1 >= 0 && pos1 < lst->x) && (pos2 >= 0 && pos2 < lst->y))
	// {
	// 	if ((lst->map.map[pos2] && lst->map.map[pos2][pos1] && lst->map.map[pos2][pos1] == '1') || lst->map.map[pos2][pos1] == ' ')
	// 		return (1);
	// 	if (lst->map.map[y1][x1] == 'V' && lst->map.map[pos2][pos1] == 'L')
	// 		return (1);
	// 	if (lst->map.map[y1][x1] == 'L' && lst->map.map[pos2][pos1] == 'V')
	// 		return (1);
	// }
	if ((posPx >= 0 && posPx < lst->x) && (posPy >= 0 && posPy < lst->y))
	{
		if (lst->map.map[posPy][posPx] == '1' || lst->map.map[posPy][posPx] == ' ')
			return (1);
		if (!((posPx == posDx) && (posPy == posDy)))
		{
			if (lst->map.map[posPy][posPx] == 'V' && lst->map.map[posDy][posDx] == 'V')
				return (1);
		}
	}
	return (0);
}

int	deal_key(int key, t_graph *var)
{
	if (key == 124)
		var->plyr.rotatedirection = 1;
	if (key == 123)
		var->plyr.rotatedirection = -1;
	if (key == 13)
	{
		var->first_time = 1;
		var->plyr.walkdirection = 1;
	}
	if (key == 1)
	{
		var->first_time = 1;
		var->plyr.walkdirection = -1;
	}
	if (key == 2)
	{
		var->first_time = 1;
		var->plyr.walkdirection = 2;
	}
	if (key == 0)
	{
		var->first_time = 1;
		var->plyr.walkdirection = 3;
	}
	if (key == 53)
		exit(0);
	return (0);
}