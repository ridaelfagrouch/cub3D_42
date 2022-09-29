/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:45:02 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 19:12:32 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_walls(t_graph *lst)
{
	rotate_player(lst);
	player_movement(lst);
	checkcollectible(lst);
	cast_rays(lst);
	if (lst->minimap_check % 2)
	{
		draw_minimap_border(lst);
		draw_map(lst->map.map, lst);
		draw_player(lst);
	}
}

void	draw_all_map(char	**map, t_graph *lst, t_graph data)
{
	if (map[data.i][data.j] == '0' || map[data.i][data.j] == 'V')
		draw_cub(data.x, data.y, lst, lst->map.floor_color);
	else if (map[data.i][data.j] == '1')
		draw_cub(data.x, data.y, lst, 0);
	else if (map[data.i][data.j] == 'S' || map[data.i][data.j] == 'W' || \
	map[data.i][data.j] == 'N' || map[data.i][data.j] == 'E')
		draw_cub(data.x, data.y, lst, lst->map.floor_color);
	else if (map[data.i][data.j] == 'C')
		draw_cub(data.x, data.y, lst, 0xFFFF00);
	else if (map[data.i][data.j] == 'B')
		draw_cub(data.x, data.y, lst, 0xCD853F);
	else
		draw_cub(data.x, data.y, lst, 0x2F4F4F);
}

void	draw_map(char	**map, t_graph *lst)
{
	t_graph	data;

	data.i = 0;
	data.j = 0;
	data.x = 0;
	data.y = 0;
	lst->x1 = lst->map.unit;
	lst->y1 = lst->map.unit;
	while (map[data.i])
	{
		while (map[data.i][data.j])
		{
			draw_all_map(map, lst, data);
			data.x += lst->map.unit;
			lst->x1 += lst->map.unit;
			data.j++;
		}
		data.x = 0;
		data.y += lst->map.unit;
		lst->y1 += lst->map.unit;
		lst->x1 = lst->map.unit;
		data.j = 0;
		data.i++;
	}
}
