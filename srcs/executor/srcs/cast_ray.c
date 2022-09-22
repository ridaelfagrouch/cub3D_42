/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/22 14:15:31 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    draw_rect(int x, int y, int x1, int y1, t_graph *lst, int i, double wallheight)
{
	double	posX;
	double	posY;
	int		s;
	int		pixel_color;
	int		width;
	int		height;
	double		ds;

	(void)x1;
	pixel_color = 0;
	width = 0;
	height = 0;
	posX = 0;
	s = 0;
	posY = 0;;
	get_width_height(lst, &width, &height, i);
	posX = get_x_of_texture(lst, i, width);
	ds = 0;
	while (y <= y1)
    {
		ds = y + (wallheight / 2) - ((lst->map.height) / 2);
		posY = ds * (double)height / wallheight;
		pixel_color = get_texture(lst, posY, posX, i);
        my_mlx_pixel_put(lst , x, y, pixel_color);
		s++;
        y++;
	}
}

void	rendringwalls(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	wallstripeheight;
	double	distance;
	int		startpointy;
	int		endpointy;
	int		x;

	x = 0;
	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_horiz, lst->plyr.y_plyr, lst->raycast.yintercept_horiz);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_vertic, lst->plyr.y_plyr, lst->raycast.yintercept_vertic);
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	wallstripeheight = (lst->map.unit / distance) * distanceprojectionplane;
	x = 1;
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

void	draw_rays(t_graph *lst, int j, int i)
{
	if (j == 1)
	{
		rendringwalls(lst, i, 1);
		drawline(lst->map.minimap * lst->plyr.x_plyr,
			lst->map.minimap * lst->plyr.y_plyr,
			lst->map.minimap * lst->raycast.xintercept_vertic,
			lst->map.minimap * lst->raycast.yintercept_vertic,
			lst, lst->map.player_color);
	}
	else
	{
		rendringwalls(lst, i, 0);
		drawline(lst->map.minimap * lst->plyr.x_plyr,
			lst->map.minimap * lst->plyr.y_plyr,
			lst->map.minimap * lst->raycast.xintercept_horiz,
			lst->map.minimap * lst->raycast.yintercept_horiz,
			lst, lst->map.player_color);
	}
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
		normilizeAngle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		draw_rays(lst, j, i);
		lst->raycast.ray_angle += lst->plyr.fov / rays_num;
		i++;
	}
}
