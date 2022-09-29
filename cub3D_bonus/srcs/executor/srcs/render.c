/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:45:02 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 01:16:04 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    draw_walls(t_graph *lst)
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

void    draw_map(char	**map, t_graph *lst)
{
    int	i;
    int j;
    int x;
    int y;

	i = 0;
    j = 0;
    x = 0;
	y = 0;
	lst->x1 = lst->map.unit;
	lst->y1 = lst->map.unit;
	while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == '0' || map[i][j] == 'V')
                draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.floor_color);
            else if (map[i][j] == '1')
				draw_cub(x, y, lst->x1, lst->y1, lst, 0);
            else if (map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'N' || map[i][j] == 'E')
                draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.floor_color);
            else if (map[i][j] == 'C')
                draw_cub(x, y, lst->x1, lst->y1, lst, 0xFFFF00);
            else if (map[i][j] == 'B')
                draw_cub(x, y, lst->x1, lst->y1, lst, 0xCD853F);
            else
                draw_cub(x, y, lst->x1, lst->y1, lst, 0x2F4F4F);
            x += lst->map.unit;
            lst->x1 += lst->map.unit;
            j++;
        }
        x = 0;
        y += lst->map.unit;
        lst->y1 += lst->map.unit;
        lst->x1 = lst->map.unit;
        j = 0;
        i++;
    }
}