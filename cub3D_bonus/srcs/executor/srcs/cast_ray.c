/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:09:41 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_rect(int x, int y, int y1, t_graph *lst)
{
	double	posx;
	double	posy;
	int		width;
	int		height;
	double	ds;

	width = 0;
	height = 0;
	posx = 0;
	posy = 0;
	get_widthheight(lst, &width, &height, lst->raycast.j);
	posx = get_x_of_texture(lst, lst->raycast.j, width);
	ds = 0;
	while (y <= y1)
	{
		ds = y + (lst->raycast.wallheight / 2) - ((lst->map.height) / 2);
		posy = ds * (double)height / lst->raycast.wallheight;
		my_mlx_pixel_put(lst, x, y, get_texture(lst, posy, posx, \
		lst->raycast.j));
		y++;
	}
}

void	rendringwalls(t_graph *lst, int i)
{
	double	distanceprojectionplane;
	double	distance;
	int		startpointy;
	int		endpointy;

	if (lst->raycast.j == 0)
		distance = distance_points(lst->plyr.x_plyr, \
		lst->raycast.xinter_ho, lst->plyr.y_plyr, lst->raycast.yinter_ho);
	else
		distance = distance_points(lst->plyr.x_plyr, \
		lst->raycast.xinter_ve, lst->plyr.y_plyr, lst->raycast.yinter_ve);
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	lst->sprite.distancetowall = distance;
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
	draw_rect(i,
		startpointy,
		endpointy, lst);
}

void	cast_rays(t_graph *lst)
{
	int		i;
	int		rays_num;

	lst->raycast.xinter_ho = 0;
	lst->raycast.yinter_ho = 0;
	lst->raycast.ray_angle = lst->plyr.rotationangle - lst->plyr.fov / 2;
	i = 0;
	rays_num = lst->map.width;
	while (i < rays_num)
	{
		lst->door.foundoor = 0;
		normilizeangle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		lst->raycast.j = calculate_intersactions(lst);
		rendringwalls(lst, i);
		lst->raycast.j = calculate_intersactions_door(lst);
		rendringdoors(lst, i);
		lst->raycast.j = calculate_intersactions_sprite(lst);
		rendringsprite(lst, i);
		lst->sprite.spritefoundhorz = 0;
		lst->sprite.spritefoundvert = 0;
		lst->raycast.ray_angle += lst->plyr.fov / rays_num;
		i++;
	}
}
