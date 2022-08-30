/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 16:45:21 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "executor.h"
#include <fcntl.h>
#include <unistd.h>


void    init_player(t_graph *lst)
{
    lst->plyr.radius = 2;
    lst->plyr.rotationangle = M_PI;
    lst->plyr.speed = 5.0;
    lst->plyr.rotationspeed = 10 * (M_PI / 180);
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
    lst.unit = 40;
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
    mlx_put_image_to_window(lst.mlx, lst.wind, lst.img, 0, 0);
    mlx_hook(lst.wind, 2, 0L, deal_key, &lst);
    mlx_loop(lst.mlx);
    return (0);
}