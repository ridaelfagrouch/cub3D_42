/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:48:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/02 16:41:46 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"

void    my_mlx_pixel_put(t_graph   *lst, int x, int y, int color)
{
	char	*test;

    if ((x >= 0 && x < lst->width * lst->map.unit) && (y >= 0 && y < lst->height * lst->map.unit))
    {
        test = &lst->addr[(y * lst->map.size_line) + (x * lst->map.bpp / 8)];
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

	j = x;
	while (y < y1)
    {
        while (j <= x1)
		{
            my_mlx_pixel_put(lst ,lst->map.minimap * j, lst->map.minimap * y, i);
			j++;
		}
		j = x;
        y++;
    }
}

void    rotate_player(t_graph *lst)
{
    if (lst->plyr.rotatedirection == -1)
    {
        lst->plyr.rotationangle += (-1 *  lst->plyr.rotationspeed);
		normilizeAngle(&lst->plyr.rotationangle);
    }
    else if (lst->plyr.rotatedirection == 1)
    {
        lst->plyr.rotationangle +=  lst->plyr.rotationspeed;
		normilizeAngle(&lst->plyr.rotationangle);
    }
}


void    turningleftright(t_graph *lst, int direction)
{
    double	newangle;
    int		save1;
    int		save2;

	if (direction == 0)
	{
		newangle = lst->plyr.rotationangle + M_PI / 2;
		normilizeAngle(&newangle);
		save1 = lst->plyr.x_plyr + (lst->plyr.speed * cos(newangle));
		save2 = lst->plyr.y_plyr + (lst->plyr.speed * sin(newangle));
	}
	else
	{
		newangle = lst->plyr.rotationangle - M_PI / 2;
		normilizeAngle(&newangle);
		save1 = lst->plyr.x_plyr + (lst->plyr.speed * cos(newangle));
		save2 = lst->plyr.y_plyr + (lst->plyr.speed * sin(newangle));
	}
    if (check_wall(lst, save1, save2))
			return ;
	lst->plyr.x_plyr = save1;
	lst->plyr.y_plyr = save2;
	lst->plyr.x1_plyr = lst->plyr.x_plyr + (lst->map.unit / 4);
	lst->plyr.y1_plyr = lst->plyr.y_plyr + (lst->map.unit / 4);
}

void    player_movement(t_graph *lst)
{
    double save1;
    double save2;
    
    if (lst->plyr.walkdirection == -1)
    {
        save1 = lst->plyr.x_plyr - (lst->plyr.speed * cos(lst->plyr.rotationangle));
		save2 = lst->plyr.y_plyr - (lst->plyr.speed * sin(lst->plyr.rotationangle));
		if (check_wall(lst, save1, save2))
			return ;
		lst->plyr.x_plyr = save1;
		lst->plyr.y_plyr = save2;
		lst->plyr.x1_plyr = lst->plyr.x_plyr + (lst->map.unit / 4);
		lst->plyr.y1_plyr = lst->plyr.y_plyr + (lst->map.unit / 4);
    }
    else if (lst->plyr.walkdirection == 1)
    {
        save1 = lst->plyr.x_plyr + (lst->plyr.speed * cos(lst->plyr.rotationangle));
		save2 = lst->plyr.y_plyr + (lst->plyr.speed * sin(lst->plyr.rotationangle));
		if (check_wall(lst, save1, save2))
			return ;
		lst->plyr.x_plyr = save1;
		lst->plyr.y_plyr = save2;
		lst->plyr.x1_plyr = lst->plyr.x_plyr + (lst->map.unit / 4);
		lst->plyr.y1_plyr = lst->plyr.y_plyr + (lst->map.unit / 4);
    }
    else if (lst->plyr.walkdirection == 2)
        turningleftright(lst, 0);
    else if (lst->plyr.walkdirection == 3)
        turningleftright(lst, 1);
}

void    draw_walls(t_graph *lst)
{
    rotate_player(lst);
    player_movement(lst);
    cast_rays(lst);
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
            if (map[i][j] == '0')
                draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.floor_color);
            else if (map[i][j] == '1')
				draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.wall_color);
            else if (map[i][j] == 'P')
            {
                draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.floor_color);
                if (lst->first_time == 0)
                {
                    lst->plyr.x_plyr = x + lst->map.unit / 4;
                    lst->plyr.y_plyr = y + lst->map.unit / 4;
                    lst->plyr.x1_plyr = lst->plyr.x_plyr + (lst->map.unit / 4);
                    lst->plyr.y1_plyr = lst->plyr.y_plyr + (lst->map.unit / 4);
                }
            }
            else
                draw_cub(x, y, lst->x1, lst->y1, lst, 20);
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