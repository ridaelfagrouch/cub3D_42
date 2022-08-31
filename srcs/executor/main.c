/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/31 11:45:41 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "executor.h"
#include <fcntl.h>
#include <unistd.h>


void    init_player(t_graph *lst)
{
    lst->plyr.rotationangle = M_PI;
    lst->plyr.speed = 2.5;
    lst->plyr.rotationspeed = 4 * (M_PI / 180);
    lst->plyr.rotatedirection = 0;
    lst->plyr.walkdirection = 0;
}

void   init_raycast(t_graph *lst)
{
	lst->raycast.facingup = 0;
	lst->raycast.facingdown = 0;
	lst->raycast.facingright = 0;
	lst->raycast.facingleft = 0;
    lst->raycast.horiz_intersaction = 0;
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
    lst.plyr.player_color = 11393254;
    lst.unit = 32;
    lst.first_time = 0;
    lst.mlx = mlx_init();
    init_player(&lst);
    init_raycast(&lst);
    lst.j = 0;
    fd = open("cub3d.cub", O_RDONLY);
    line = get_next_line1(fd);
    lst.map = ft_split(line, '\n');
    lst.i = 0;
    while (lst.map[lst.i])
        lst.i++;
    while (lst.map[0][lst.j])
        lst.j++;
    lst.wind = mlx_new_window(lst.mlx, 1800, 1100, "cub3d");
    free(line);
    draw_map(lst.map, &lst);
    draw_player(&lst);
    mlx_loop_hook(lst.mlx, routine, &lst);
    mlx_loop(lst.mlx);
    return (0);
}