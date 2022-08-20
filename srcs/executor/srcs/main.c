/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/20 12:55:30 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../executor.h"

typedef struct s_graph {

    void    *mlx;
    void    *wind;

} t_graph;

void drawline(int x0, int y0, int x1, int y1, t_graph *lst)
{
    int dx, dy, p, x, y;
 
    dx= x1-x0;
    dy= y1-y0;
    
    x= x0;
    y= y0;
    
    p = 2 * dy - dx;
    
    while(x < x1)
    {
        if(p >= 0)
        {
            mlx_pixel_put(lst->mlx, lst->wind , x, y, 3319890);
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            mlx_pixel_put(lst->mlx, lst->wind , x, y, 3319890);
            p = p + 2 * dy;
        }
        x++;
    }
}

int main()
{
    t_graph lst;

    lst.mlx = mlx_init();
    lst.wind = mlx_new_window(lst.mlx, 1080, 720, "cub3d");
    drawline(0, 0, 100, 90, &lst);
    mlx_loop(lst.mlx);
    return (0);
}