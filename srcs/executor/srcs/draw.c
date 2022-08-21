/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:48:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/21 16:56:51 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"

void drawline(int x0, int y0, int x1, int y1, t_graph *lst, int j)
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
            if (j == 0)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->floor_color);
            else  if (j == 1)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->wall_color);
            else  if (j == 2)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->plyr.player_color);
            else
                mlx_pixel_put(lst->mlx, lst->wind , x, y, 0);
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            if (j == 0)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->floor_color);
            else if (j == 1)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->wall_color);
            else  if (j == 2)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->plyr.player_color);
            else
                mlx_pixel_put(lst->mlx, lst->wind , x, y, 0);
            p = p + 2 * dy;
        }
        x++;
    }
}

void    draw_cub(int x, int y, int save, int x1, int y1, t_graph *lst, int i)
{
    while (y < save + 50)
    {
        drawline(x, y, x1, y1, lst, i);
        y++;
    } 
}


void    draw_everything(char	**map, t_graph *lst)
{
    int	i;
    int j;
    int save;

	i = 0;
    j = 0;
    save = 0;
	while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == '0')
                draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, 0);
            else if (map[i][j] == '1')
				draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, 1);
            else if (map[i][j] == 'P')
            {
                draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, 0);
                lst->plyr.x_plyr = lst->x;
                lst->plyr.y_plyr = lst->y;
				// draw_cub(lst->x + 12, lst->y + 12, save - 10, lst->x1 - 12, lst->y1 - 12, lst, 2);
                // drawline(lst->x + 25, lst->y + 25, lst->x1 + 25, lst->y1 - 25, lst, 2);
            }
            else
                draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, 3);
            lst->x += 50;
            lst->x1 += 50;
            lst->y = save;
            j++;
        }
        lst->x = 0;
        lst->y += 50;
        save = lst->y;
        j = 0;
        lst->x1 = 50;
        i++;
    }
    draw_cub(lst->plyr.x_plyr + 12, lst->plyr.y_plyr + 12, lst->plyr.y_plyr - 10, lst->plyr.x_plyr + 50 - 12, lst->plyr.y_plyr - 12, lst, 2);
    drawline(lst->plyr.x_plyr + 25, lst->plyr.y_plyr + 25, lst->plyr.x_plyr + 150, lst->plyr.y_plyr + 50 - 25, lst, 2);
}