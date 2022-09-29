/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/28 22:30:18 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    draw_rect(int x, int y, int x1, int y1, t_graph *lst, int i, double wallheight)
{
	double	posX;
	double	posY;
	int		pixel_color;
	int		width;
	int		height;
	double		ds;

	(void)x1;
	pixel_color = 0;
	width = 0;
	height = 0;
	posX = 0;
	posY = 0;
	get_widthheight(lst, &width, &height, i);
	posX = get_x_of_texture(lst, i, width);
	ds = 0;
	while (y <= y1)
    {
		ds = y + (wallheight / 2) - ((lst->map.height) / 2);
		posY = ds * (double)height / wallheight;
		pixel_color = get_texture(lst, posY, posX, i);
        my_mlx_pixel_put(lst , x, y, pixel_color);
        y++;
	}
}

void    draw_rect_sprite(int x, int y, int x1, int y1, t_graph *lst, int i, double wallheight)
{
	double	posX;
	double	posY;
	int		pixel_color;
	int		width;
	int		height;
	double	ds;

	(void)x1;
	pixel_color = 0;
	width = lst->sprite.widthsprite;
	height = lst->sprite.heightsprite;
	posX = 0;
	posY = 0;
	posX = get_x_of_texture_sprite(lst, i, width);
	ds = 0;
	while (y <= y1)
    {
		ds = y + (wallheight / 2) - ((lst->map.height) / 2);
		posY = ds * (double)height / wallheight;
		pixel_color = lst->sprite.addrsprite[(int)((abs((int)posY) * width) + posX)];
		if (pixel_color != 16777215)
        	my_mlx_pixel_put(lst , x, y, pixel_color);
        y++;
	}
}

void	get_widthheightdoor(t_graph *lst, int *width, int *height)
{
	if (lst->door.door_number == 1)
	{
		*width = lst->door.widthdoor1;
		*height = lst->door.heightdoor1;
	}
	else if (lst->door.door_number == 2)
	{
		*width = lst->door.widthdoor2;
		*height = lst->door.heightdoor2;
	}
	else if (lst->door.door_number == 3)
	{
		*width = lst->door.widthdoor3;
		*height = lst->door.heightdoor3;
	}
	else if (lst->door.door_number == 4)
	{
		*width = lst->door.widthdoor4;
		*height = lst->door.heightdoor4;
	}
}

void    draw_rect_door(int x, int y, int x1, int y1, t_graph *lst, int i, double wallheight)
{
	double	posX;
	double	posY;
	int		pixel_color;
	int		width;
	int		height;
	double	ds;

	(void)x1;
	pixel_color = 0;
	get_widthheightdoor(lst, &width, &height);
	posX = get_x_of_texture_doors(lst, i, width);
	i = 0;
	while (y <= y1)
    {
		ds = y + (wallheight / 2) - ((lst->map.height) / 2);
		posY = ds * (double)height / wallheight;
		pixel_color = get_texture_door(lst, posY, posX);
		if (pixel_color != 16777215)
       		my_mlx_pixel_put(lst , x, y, pixel_color);
        y++;
	}
}

void	checkdoorstatus(t_graph *lst, double distance)
{
	int closetodoor;
	
	closetodoor = lst->map.width * 70 / 1000;
	if (distance > closetodoor)
	{
		lst->door.door_number = 1;
		return ;
	}
	else if (distance <= closetodoor && distance > (closetodoor * 0.8))
	{
		lst->door.door_number = 2;
		return ;
	}
	else if (distance <= (closetodoor * 0.6) && distance > (closetodoor * 0.4))
	{
		lst->door.door_number = 3;
		return ;
	}
	else if (distance < (closetodoor * 0.3))
	{
		lst->door.door_number = 4;
		return ;
	}
	return ;
}

void	rendringwalls(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	wallstripeheight;
	double	distance;
	int		startpointy;
	int		endpointy;

	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_horiz, lst->plyr.y_plyr, lst->raycast.yintercept_horiz);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_vertic, lst->plyr.y_plyr, lst->raycast.yintercept_vertic);
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	lst->sprite.distancetowall = distance;
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	wallstripeheight = (lst->map.unit / distance) * distanceprojectionplane;
	startpointy = (lst->map.height / 2) - (wallstripeheight / 2);
	if (startpointy < 0)
		startpointy = 0;
	endpointy = wallstripeheight + ((lst->map.height) / 2) - (wallstripeheight / 2);
	if (endpointy > lst->map.height)
		endpointy = lst->map.height;
	draw_rect(i,
			startpointy,
			i,
			endpointy, lst, j, wallstripeheight);
}

void	rendringdoors(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	wallstripeheight;
	double	distance;
	int		startpointy;
	int		endpointy;

	if (j == 3)
		return ;
	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->door.xintercept_horiz, lst->plyr.y_plyr, lst->door.yintercept_horiz);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->door.xintercept_vertic, lst->plyr.y_plyr, lst->door.yintercept_vertic);
	if (lst->sprite.distancetowall < distance)
		return ;
	lst->sprite.distancetowall = distance;
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	checkdoorstatus(lst, distance);
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	wallstripeheight = (lst->map.unit / distance) * distanceprojectionplane;
	startpointy = (lst->map.height / 2) - (wallstripeheight / 2);
	if (startpointy < 0)
		startpointy = 0;
	endpointy = wallstripeheight + ((lst->map.height) / 2) - (wallstripeheight / 2);
	if (endpointy > lst->map.height)
		endpointy = lst->map.height;
	draw_rect_door(i,
			startpointy,
			i,
			endpointy, lst, j, wallstripeheight);
}

void	rendringsprite(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	wallstripeheight;
	double	distance;
	int		startpointy;
	int		endpointy;
	int		x;

	x = 0;
	if (!lst->sprite.spritefoundhorz && !lst->sprite.spritefoundvert)
		return ;
	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->sprite.xintercept_horiz, lst->plyr.y_plyr, lst->sprite.yintercept_horiz);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->sprite.xintercept_vertic, lst->plyr.y_plyr, lst->sprite.yintercept_vertic);
	if (lst->sprite.distancetowall < distance)
		return ;
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	wallstripeheight = ((lst->map.unit / 2) / distance) * distanceprojectionplane;
	x = 1;
	startpointy = (lst->map.height / 2) - (wallstripeheight / 2);
	if (startpointy < 0)
		startpointy = 0;
	endpointy = wallstripeheight + ((lst->map.height) / 2) - (wallstripeheight / 2);
	if (endpointy > lst->map.height)
		endpointy = lst->map.height;
	draw_rect_sprite(i,
			startpointy,
			i,
			endpointy, lst, j, wallstripeheight);
}


void cast_rays(t_graph *lst)
{
	int		i;
	int		rays_num;
	int		j;

	lst->raycast.xintercept_horiz = 0;
	lst->raycast.yintercept_horiz = 0;
	lst->raycast.ray_angle = lst->plyr.rotationangle - lst->plyr.fov / 2;
	i = 0;
	j = 0;
	rays_num = lst->map.width;
	while (i < rays_num)
	{
		lst->door.foundoor = 0;
		normilizeAngle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		rendringwalls(lst, i, j);
		j = calculate_intersactions_door(lst);
		rendringdoors(lst, i, j);
		j = calculate_intersactions_sprite(lst);
		rendringsprite(lst, i, j);
		lst->sprite.spritefoundvert = 0;
		lst->sprite.spritefoundhorz = 0;
		lst->raycast.ray_angle += lst->plyr.fov / rays_num;
		i++;
	}
}