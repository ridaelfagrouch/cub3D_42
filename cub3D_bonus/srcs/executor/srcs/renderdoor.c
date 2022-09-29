/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderdoor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:26:52 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:09:29 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	calculate_intersactions_door(t_graph *lst)
{
	double	distance_horiz;
	double	distance_vertic;

	distance_horiz = 0;
	distance_vertic = 0;
	if (!lst->door.horiz_intersaction && !lst->door.vertic_intersaction)
		return (3);
	if (lst->door.horiz_intersaction)
		distance_horiz = distance_points(lst->plyr.x_plyr, \
		lst->door.xinter_ho, lst->plyr.y_plyr, lst->door.yinter_ho);
	else
		distance_horiz = -1;
	if (lst->door.vertic_intersaction)
		distance_vertic = distance_points(lst->plyr.x_plyr, \
		lst->door.xinter_ve, lst->plyr.y_plyr, lst->door.yinter_ve);
	else
		distance_vertic = -1;
	if (distance_horiz == -1)
		return (1);
	else if (distance_vertic == -1)
		return (0);
	if (distance_horiz > distance_vertic)
		return (1);
	else
		return (0);
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

void	checkdoorstatus(t_graph *lst, double distance)
{
	int	closetodoor;

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

void	draw_rect_door(int x, int y, int y1, t_graph *lst)
{
	double	posx;
	double	posy;
	int		width;
	int		height;
	double	ds;

	get_widthheightdoor(lst, &width, &height);
	posx = get_x_of_texture_doors(lst, lst->raycast.j, width);
	while (y <= y1)
	{
		ds = y + (lst->raycast.wallheight / 2) - ((lst->map.height) / 2);
		posy = ds * (double)height / lst->raycast.wallheight;
		if (get_texture_door(lst, posy, posx) != 16777215)
			my_mlx_pixel_put(lst, x, y, get_texture_door(lst, posy, posx));
		y++;
	}
}

void	rendringdoors(t_graph *lst, int i)
{
	double	distanceprojectionplane;
	double	distance;
	int		startpointy;
	int		endpointy;

	if (lst->raycast.j == 3)
		return ;
	if (lst->raycast.j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->door.xinter_ho, \
		lst->plyr.y_plyr, lst->door.yinter_ho);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->door.xinter_ve, \
		lst->plyr.y_plyr, lst->door.yinter_ve);
	if (lst->sprite.distancetowall < distance)
		return ;
	lst->sprite.distancetowall = distance;
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	checkdoorstatus(lst, distance);
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	lst->raycast.wallheight = (lst->map.unit / distance) * \
	distanceprojectionplane;
	startpointy = (lst->map.height / 2) - (lst->raycast.wallheight / 2);
	if (startpointy < 0)
		startpointy = 0;
	endpointy = lst->raycast.wallheight + ((lst->map.height) / 2) - \
	(lst->raycast.wallheight / 2);
	if (endpointy > lst->map.height)
		endpointy = lst->map.height;
	draw_rect_door(i,
		startpointy,
		endpointy, lst);
}