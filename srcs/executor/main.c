/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/24 18:20:13 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "executor.h"
#include <fcntl.h>
#include <unistd.h>


void    init_player(t_graph *lst)
{
    lst->plyr.radius = 3;
    lst->plyr.Turndirection = 0;
    lst->plyr.Walkdirection = 0;
    lst->plyr.rotationangle = M_PI / 4;
    lst->plyr.speed = 3.0;
    lst->plyr.rotationspeed = 3 * (M_PI / 180);
}

int main()
{
    t_graph lst;
    int     i;
    int     j;
    int     fd;
    char    *line;

    lst.floor_color = 16777215;
    lst.wall_color = 8421504;
    lst.plyr.player_color = 14423100;
    lst.unit = 40;
    lst.x = 0;
	lst.y = 0;
	lst.x1 = 50;
	lst.y1 = 0;
    lst.mlx = mlx_init();
    init_player(&lst);
    lst.i = 0;
    lst.j = 0;
    fd = open("cub3d.cub", O_RDONLY);
    line = get_next_line1(fd);
    lst.map = ft_split(line, '\n');
    while (lst.map[lst.i])
        lst.i++;
    while (lst.map[0][lst.j])
        lst.j++;
    lst.wind = mlx_new_window(lst.mlx, 1800, 1100, "cub3d");
    free(line);
    draw_map(lst.map, &lst);
    draw_player(&lst);
    // mlx_hook(lst.wind, 2, 0L, deal_key, &lst);
    mlx_loop(lst.mlx);
    return (0);
}