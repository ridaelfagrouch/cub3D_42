/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:48:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 11:41:06 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"


// void drawline(int x0, int y0, int x1, int y1, t_graph *lst, int j)
// {
//     int dx; 
// 	int dy;
// 	int p;
// 	int x; 
// 	int y;
 
//     dx = x1 - x0;
//     dy = y1 - y0;
//     x = x0;
//     y = y0;

//     p = 2 * dy - dx;    
//     while (x <= x1)
//     {
//         if(p >= 0)
//         {
//             if (j == 0)
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->floor_color);
//             else if (j == 1)
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->wall_color);
//             else if (j == 2)
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->plyr.player_color);
//             else
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, 0);
//             y++;
//             p = p + 2 * dy - 2 * dx;
//         }
//         else
//         {
//             if (j == 0)
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->floor_color);
//             else if (j == 1)
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->wall_color);
//             else  if (j == 2)
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->plyr.player_color);
//             else
//                 mlx_pixel_put(lst->mlx, lst->wind , x, y, 0);
//             p = p + 2 * dy;
//         }
//         x++;
//     }
// }

void    my_mlx_pixel_put(t_graph   *lst, int x, int y, int color)
{
	char	*test;

    if ((x >= 0 && x <= lst->j * lst->unit) && (y >= 0 && y <= lst->i * lst->unit))
    {
        test = &lst->addr[(y * lst->size_line) + (x * lst->bpp / 8)];
	    *(unsigned int*)test = color;   
    }
}

void drawline(double x0, double y0, int x1, int y1, t_graph *lst, int j)
{
    double 	dx;
	double	dy;
	int	    steps;
	double	x;
	double	y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	i = 0;
    steps = 0;
    if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x = dx / steps;
	y = dy / steps;
	while (i < steps)
	{
        my_mlx_pixel_put(lst , x0, y0, j);
		x0 = x0 + x;
		y0 = y0 + y;
		i++;
	}
}

void    draw_cub(int x, int y, int x1, int y1, t_graph *lst, int i)
{
	int	j;
    int save;

	j = x;
	while (y < y1)
    {
        while (j <= x1)
		{
            my_mlx_pixel_put(lst ,j, y, i);
			j++;
		}
		j = x;
        y++;
    }
}

void    draw_player(t_graph *lst)
{
    // draw_cub(lst->plyr.x_plyr, lst->plyr.y_plyr, lst->plyr.x1_plyr, lst->plyr.y1_plyr, lst, lst->plyr.player_color);
    cast_rays(lst);
}

void    draw_map(char	**map, t_graph *lst)
{
    int	i;
    int j;

	i = 0;
    j = 0;
    lst->x = 0;
	lst->y = 0;
	lst->x1 = lst->unit;
	lst->y1 = lst->unit;
    lst->img = NULL;
    lst->addr = NULL;
    lst->img = mlx_new_image(lst->mlx, lst->j * lst->unit, lst->i * lst->unit);
    lst->addr = mlx_get_data_addr(lst->img, &lst->bpp, &lst->size_line, &lst->endian);
	while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == '0')
                draw_cub(lst->x, lst->y, lst->x1, lst->y1, lst, lst->floor_color);
            else if (map[i][j] == '1')
				draw_cub(lst->x, lst->y, lst->x1, lst->y1, lst, lst->wall_color);
            else if (map[i][j] == 'P')
            {
                draw_cub(lst->x, lst->y, lst->x1, lst->y1, lst, lst->floor_color);
                if (lst->first_time == 0)
                {
                    lst->plyr.x_plyr = lst->x + lst->unit / 4;
                    lst->plyr.y_plyr = lst->y + lst->unit / 4;
                    lst->plyr.x1_plyr = lst->plyr.x_plyr + (lst->unit / 4);
                    lst->plyr.y1_plyr = lst->plyr.y_plyr + (lst->unit / 4);
                }
            }
            else
                draw_cub(lst->x, lst->y, lst->x1, lst->y1, lst, 20);
            lst->x += lst->unit;
            lst->x1 += lst->unit;
            j++;
        }
        lst->x = 0;
        lst->y += lst->unit;
        lst->y1 += lst->unit;
        lst->x1 = lst->unit;
        j = 0;
        i++;
    }
}