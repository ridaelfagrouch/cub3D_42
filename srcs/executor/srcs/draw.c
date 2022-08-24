/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:48:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/24 18:22:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"

// void    my_mlx_pixel_put(int x, int y, t_data *data, int color)
// {
//     char    *dst;

//     if ((x >= 0 && x < W) && (y >= 0 && y < H))
//     {
//         dst = data->mlx_vars->buffer + (y * data->mlx_vars->line_lenght + x * (data->mlx_vars->bpp / 8));
//         *(unsigned int *)dst = color;
//     }
// }

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
// void    my_mlx_pixvel_put(int x, int y, t_data *data, int color)
// {
//     char    *dst;

//     if ((x >= 0 && x < W) && (y >= 0 && y < H))
//     {
//         dst = data->mlx_vars->buffer + (y * data->mlx_vars->line_lenght + x * (data->mlx_vars->bpp / 8));
//         *(unsigned int *)dst = color;
//     }
// }
void    my_mlx_pixel_put(t_graph   *lst, int x, int y, int color)
{
	char	*test;
	
	test = &lst->addr[(y * lst->size_line) + (x * lst->bpp / 8)];
	// test = lst->addr + ((y * lst->size_line) + (x * lst->bpp / 8));
	*(unsigned int*)test = color;
    // lst->addr[(y * 1100) + (x * 1800)];
}

void drawline(int x0, int y0, int x1, int y1, t_graph *lst, int j)
{
    int 	dx;
	int		dy;
	int		steps;
	float	x;
	float	y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	i = 0;
    if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x = dx / steps;
	y = dy / steps;
	while (i < steps)
	{
        my_mlx_pixel_put(lst ,x0, y0, j);
		// mlx_pixel_put(lst->mlx, lst->wind , j, y, i);
		x0 = x0 + x;
		y0 = y0 + y;
		i++;
	}
	
}

void    draw_cub(int x, int y, int save, int x1, int y1, t_graph *lst, int i)
{
	int	j;

	// while (x < 1800)
	// {
	// 	y = 0;
	// 	while (y < 1100)
	// 	{
	// 		my_mlx_pixel_put(lst ,x, y, i);
	// 		y++;
	// 	}
	// 	x++;
	// }
	j = x;
	while (y < save + lst->unit)
    {
        while (j < x1)
		{
			my_mlx_pixel_put(lst ,j, y, i);
			// mlx_pixel_put(lst->mlx, lst->wind , j, y, i);
			j++;
		}
		j = x;
        y++;
    }
}

void    cast_ray(t_graph *lst)
{
    drawline(lst->plyr.x_plyr,  
       		lst->plyr.y_plyr, 
        	lst->plyr.x_plyr + cos(lst->plyr.rotationangle) * 50, 
        	lst->plyr.y_plyr + sin(lst->plyr.rotationangle) * 50, 
        	lst, lst->plyr.player_color);
}

void    draw_player(t_graph *lst)
{
    draw_cub(lst->plyr.x_plyr, lst->plyr.y_plyr, lst->plyr.y_plyr - 25, lst->plyr.x1_plyr, lst->plyr.y1_plyr, lst, 2);
    cast_ray(lst);
}

void    draw_map(char	**map, t_graph *lst)
{
    int	i;
    int j;
    int save;
    int t;
    int c;
    int y;

	i = 0;
    j = 0;
    save = 0;
    lst->img = mlx_new_image(lst->mlx, lst->j * lst->unit, lst->i * lst->unit);
    lst->addr = mlx_get_data_addr(lst->img, &lst->bpp, &lst->size_line, &lst->endian);
	while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == '0')
                draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, lst->floor_color);
            else if (map[i][j] == '1')
				draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, lst->wall_color);
            else if (map[i][j] == 'P')
            {
                draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, lst->plyr.player_color);
                lst->plyr.x_plyr = lst->x;
                lst->plyr.y_plyr = lst->y;
                lst->plyr.x1_plyr = lst->plyr.x_plyr + cos(lst->plyr.rotationangle) * 30;
                lst->plyr.y1_plyr = lst->plyr.y_plyr + sin(lst->plyr.rotationangle) * 30;
				// lst->plyr.x1_plyr = lst->x1 - 12;
                // lst->plyr.y1_plyr = lst->y1 - 12;
            }
            else
                draw_cub(lst->x, lst->y, save, lst->x1, lst->y1, lst, 3);
            lst->x += lst->unit;
            lst->x1 += lst->unit;
            lst->y = save;
            j++;
        }
        lst->x = 0;
        lst->y += lst->unit;
        save = lst->y;
        j = 0;
        lst->x1 = lst->unit;
        i++;
    }
	mlx_put_image_to_window(lst->mlx, lst->wind, lst->img, 0, 0);
}