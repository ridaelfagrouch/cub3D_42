/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/01 16:54:21 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "executor.h"

int main()
{
    t_graph lst;
    int     fd;

    fd = 0;
    init_map(&lst);
    init_player(&lst);
    init_raycast(&lst);
    init_everything(&lst, fd);
    draw_map(lst.map.map, &lst);
    draw_walls(&lst);
    mlx_loop_hook(lst.mlx, routine, &lst);
    mlx_loop(lst.mlx);
    return (0);
}