/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/01 16:40:13 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    draw_rect(int x, int y, int x1, int y1, t_graph *lst, int i)
{
	int	j;

	j = x;
	while (y < y1)
    {
        while (j < x1)
		{
            my_mlx_pixel_put(lst ,j, y, i);
			j++;
		}
		j = x;
        y++;
    }
}

void	rendringwalls(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	wallstripeheight;
	double	distance;
	int		x;

	x = 0;
	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_horiz, lst->plyr.y_plyr, lst->raycast.yintercept_horiz);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_vertic, lst->plyr.y_plyr, lst->raycast.yintercept_vertic);
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	distanceprojectionplane = ((lst->width * lst->map.unit) / 2) / tan(lst->plyr.fov / 2);
	wallstripeheight = (lst->map.unit / distance) * distanceprojectionplane;
	x = (lst->width * lst->map.unit) / 320;
	draw_rect((i * x),
			((lst->height * lst->map.unit) / 2) - (wallstripeheight / 2),
			(i * x) + x,
			wallstripeheight + ((lst->height * lst->map.unit) / 2) - (wallstripeheight / 2), lst, 16777215);
	
}

void	draw_rays(t_graph *lst, int j, int i)
{
	if (j == 1)
	{
		drawline(lst->map.minimap * lst->plyr.x_plyr,
			lst->map.minimap * lst->plyr.y_plyr,
			lst->map.minimap * lst->raycast.xintercept_vertic,
			lst->map.minimap * lst->raycast.yintercept_vertic,
			lst, lst->map.player_color);
		rendringwalls(lst, i, 1);
	}
	else
	{
		drawline(lst->map.minimap * lst->plyr.x_plyr,
			lst->map.minimap * lst->plyr.y_plyr,
			lst->map.minimap * lst->raycast.xintercept_horiz,
			lst->map.minimap * lst->raycast.yintercept_horiz,
			lst, lst->map.player_color);
		rendringwalls(lst, i, 0);
	}
}

void cast_rays(t_graph *lst)
{
	double	fov;
	int		i;
	int		rays_num;
	int		j;

	lst->raycast.xintercept_horiz = 0;
	lst->raycast.yintercept_horiz = 0;
	fov = 1.0472;
	lst->raycast.ray_angle = lst->plyr.rotationangle - fov / 2;
	i = 0;
	j = 0;
	rays_num = 319;
	while (i < rays_num)
	{
		normilizeAngle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		draw_rays(lst, j, i);
		lst->raycast.ray_angle += fov / rays_num;
		i++;
	}
}