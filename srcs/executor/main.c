/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/21 16:52:22 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "executor.h"
#include <fcntl.h>
#include <unistd.h>


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
    lst.x = 0;
	lst.y = 0;
	lst.x1 = 50;
	lst.y1 = 0;
    lst.mlx = mlx_init();
    i = 0;
    j = 0;
    fd = open("cub3d.cub", O_RDONLY);
    line = get_next_line1(fd);
    lst.map = ft_split(line, '\n');
    while (lst.map[i])
        i++;
    while (lst.map[0][j])
        j++;
    lst.wind = mlx_new_window(lst.mlx, j * 50, i * 50, "cub3d");
    free(line);
    draw_everything(lst.map, &lst);
    mlx_key_hook(lst.wind, deal_key, &lst);
    mlx_loop(lst.mlx);
    return (0);
}