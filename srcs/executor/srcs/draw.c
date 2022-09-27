/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:48:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/27 21:24:03 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"

void    my_mlx_pixel_put(t_graph   *lst, int x, int y, int color)
{
	char	*test;

    if ((x >= 0 && x < lst->map.width) && (y >= 0 && y < lst->map.height))
    {
        test = &lst->map.addr[(y * lst->map.size_line) + (x * lst->map.bpp / 8)];
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

void    new_x_y(int *new_x, int *new_y, int j, int y, t_graph *lst)
{
    *new_x = j - (lst->plyr.x_plyr - 100);
    *new_y = y - (lst->plyr.y_plyr - 100);
}

void    draw_cub(int x, int y, int x1, int y1, t_graph *lst, int i)
{
	int	j;
    int new_x;
    int new_y;

	j = x;
	while (y < y1)
    {
        while (j <= x1)
		{
            new_x_y(&new_x, &new_y, j, y, lst);
            if (new_x > 0 && new_x < 200 && new_y > 0 && new_y < 200)
                my_mlx_pixel_put(lst , new_x, new_y, i);
			j++;
		}
		j = x;
        y++;
    }
}

void    draw_cub1(int x, int y, int x1, int y1, t_graph *lst, int i)
{
	int	j;

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
    int i;

    i = 99;
    while (++i <= 105)
        drawline(100, i, 105, i, lst, 0xFF0000);
}

void    draw_minimap_border(t_graph *lst)
{
    int i;

    i = 199;
    while (++i <= 202)
    {
        drawline(i, 0, i, 202, lst, 0);
        drawline(0, i, 202, i, lst, 0);
    }
}

void    rotate_player(t_graph *lst)
{
    if (lst->plyr.rotatedirection == -1)
        lst->plyr.rotationangle += (-1 *  lst->plyr.rotationspeed);
    if (lst->plyr.rotatedirection == 1)
        lst->plyr.rotationangle +=  lst->plyr.rotationspeed;
	normilizeAngle(&lst->plyr.rotationangle);
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
    if (check_wall_movement(lst, save1, save2, lst->plyr.x_plyr, lst->plyr.y_plyr))
			return ;
	lst->plyr.x_plyr = save1;
	lst->plyr.y_plyr = save2;
}

void    player_movement(t_graph *lst)
{
    double save1;
    double save2;
    
    if (lst->plyr.walkdirection == -1)
    {
        save1 = lst->plyr.x_plyr - (lst->plyr.speed * cos(lst->plyr.rotationangle));
		save2 = lst->plyr.y_plyr - (lst->plyr.speed * sin(lst->plyr.rotationangle));
		if (check_wall_movement(lst, save1, save2, lst->plyr.x_plyr, lst->plyr.y_plyr))
		    return ;
		lst->plyr.x_plyr = save1;
		lst->plyr.y_plyr = save2;
    }
    if (lst->plyr.walkdirection == 1)
    {
        save1 = lst->plyr.x_plyr + (lst->plyr.speed * cos(lst->plyr.rotationangle));
		save2 = lst->plyr.y_plyr + (lst->plyr.speed * sin(lst->plyr.rotationangle));
		if (check_wall_movement(lst, save1, save2, lst->plyr.x_plyr, lst->plyr.y_plyr))
			return ;
		lst->plyr.x_plyr = save1;
		lst->plyr.y_plyr = save2;
    }
    if (lst->plyr.walkdirectionleftright == 1)
        turningleftright(lst, 0);
    if (lst->plyr.walkdirectionleftright == -1)
        turningleftright(lst, 1);
}

void    draw_walls(t_graph *lst)
{
    rotate_player(lst);
    player_movement(lst);
    checkcollectible(lst);
    cast_rays(lst);
    draw_minimap_border(lst);
    draw_map(lst->map.map, lst);
    draw_player(lst);
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
            if (map[i][j] == '0' || map[i][j] == 'V')
                draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.floor_color);
            else if (map[i][j] == '1')
				draw_cub(x, y, lst->x1, lst->y1, lst, 0);
            else if (map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'N' || map[i][j] == 'E')
                draw_cub(x, y, lst->x1, lst->y1, lst, lst->map.floor_color);
            else if (map[i][j] == 'C')
                draw_cub(x, y, lst->x1, lst->y1, lst, 0xFFFF00);
            else if (map[i][j] == 'B')
                draw_cub(x, y, lst->x1, lst->y1, lst, 0xCD853F);
            else
                draw_cub(x, y, lst->x1, lst->y1, lst, 0x2F4F4F);
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