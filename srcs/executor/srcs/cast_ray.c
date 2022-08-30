/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 18:37:24 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_rays(t_graph *lst, int j)
{
	if (j == 1)
	{
		drawline(lst->plyr.x_plyr,
			lst->plyr.y_plyr,
			lst->raycast.xintercept_vertic,
			lst->raycast.yintercept_vertic,
			lst, lst->plyr.player_color);
	}
	else
	{
		drawline(lst->plyr.x_plyr,
			lst->plyr.y_plyr,
			lst->raycast.xintercept_horiz,
			lst->raycast.yintercept_horiz,
			lst, lst->plyr.player_color);
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
	lst->raycast.ray_angle = lst->plyr.rotationangle - (fov / 2);
	i = 0;
	j = 0;
	rays_num = 320;
	while (i < rays_num)
	{
		normilizeAngle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		draw_rays(lst, j);
		lst->raycast.ray_angle += fov / rays_num;
		i++;
	}
}