/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/29 18:41:29 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void checking_where_plyr_facing(t_graph *lst)
{
	int	i;

	i = 0;
	if (lst->raycast.ray_angle > M_PI && lst->raycast.ray_angle < (2 * M_PI))
	{
		lst->raycast.facingup = 1;
		lst->raycast.facingdown = 0;
	}
	else if (lst->raycast.ray_angle < M_PI && lst->raycast.ray_angle > 0)
	{
		lst->raycast.facingup = 0;
		lst->raycast.facingdown = 1;
	}
	else
	{
		lst->raycast.facingup = 0;
		lst->raycast.facingdown = 0;
	}
	if (lst->raycast.ray_angle >= (0.5 * M_PI) && lst->raycast.ray_angle <= (1.5 * M_PI))
	{
		lst->raycast.facingright = 0;
		lst->raycast.facingleft = 1;
	}
	else
	{
		lst->raycast.facingright = 1;
		lst->raycast.facingleft = 0;
	}
}

// void cast_rays(t_graph *lst)
// {
// 	double ray_angle;
// 	double fov;
// 	int i;
// 	int rays_num;

// 	lst->raycast.xintercept = 0;
// 	lst->raycast.yintercept = 0;
// 	fov = 1.0472;
// 	ray_angle = lst->plyr.rotationangle - fov / 2;
// 	i = 0;
// 	rays_num = 320;
// 	// while (i < rays_num)
// 	// {
		
// 	// 	drawline(lst->plyr.x_plyr,
// 	//    		lst->plyr.y_plyr,
// 	//     	lst->plyr.x_plyr + cos(ray_angle) * lst->unit * 2,
// 	//     	lst->plyr.y_plyr + sin(ray_angle) * lst->unit * 2,
// 	//     	lst, lst->plyr.player_color);
// 	//     lst->raycast.yintercept = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
// 	// 	if (lst->raycast.facingdown)
// 	// 		lst->raycast.yintercept += lst->unit;
// 	//     lst->raycast.xintercept = lst->plyr.x_plyr + ((lst->raycast.yintercept - lst->plyr.y_plyr) / tan(ray_angle));

// 	//     my_mlx_pixel_put(lst , lst->raycast.xintercept, lst->raycast.yintercept, 16711680);
// 	// 	ray_angle += fov / rays_num;
// 	// 	i++;
// 	// }
// 	lst->raycast.ray_angle = lst->plyr.rotationangle;
// 	checking_where_plyr_facing(lst);
// 	drawline(lst->plyr.x_plyr,
// 			 lst->plyr.y_plyr,
// 			 lst->plyr.x_plyr + cos(lst->plyr.rotationangle) * lst->unit * 2,
// 			 lst->plyr.y_plyr + sin(lst->plyr.rotationangle) * lst->unit * 2,
// 			 lst, lst->plyr.player_color);
// 	if (lst->raycast.facingup)
// 	{
// 		lst->raycast.yintercept = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
// 		lst->raycast.xintercept = lst->plyr.x_plyr + ((lst->raycast.yintercept - lst->plyr.y_plyr) / tan(lst->plyr.rotationangle));
// 	}
// 	else
// 	{
// 		lst->raycast.yintercept = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
// 		lst->raycast.yintercept += lst->unit;
// 		lst->raycast.xintercept = lst->plyr.x_plyr + ((lst->raycast.yintercept - lst->plyr.y_plyr) / tan(lst->plyr.rotationangle));
// 	}
// 	lst->raycast.ystep = lst->unit;
// 	if (lst->raycast.facingup)
// 		lst->raycast.ystep *= -1;
// 	lst->raycast.xstep = lst->unit / tan(lst->plyr.rotationangle);
// 	if (lst->raycast.facingleft && lst->raycast.xstep > 0)
// 		lst->raycast.xstep *= -1;
// 	if (lst->raycast.facingright && lst->raycast.xstep < 0)
// 		lst->raycast.xstep *= -1;
// 	my_mlx_pixel_put(lst, lst->raycast.xintercept, lst->raycast.yintercept, 16711680);
// }


void	horizantal_intersaction(t_graph *lst)
{
	double	nextx;
	double	nexty;
	
	lst->raycast.yintercept = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
	if (lst->raycast.facingdown)
		lst->raycast.yintercept += lst->unit;
	// lst->raycast.xintercept = lst->plyr.x_plyr + (lst->raycast.yintercept - lst->plyr.y_plyr) / tan(lst->raycast.ray_angle);
	lst->raycast.xintercept = lst->plyr.x_plyr + (lst->raycast.yintercept - lst->plyr.y_plyr) * (cos(lst->raycast.ray_angle) / sin(lst->raycast.ray_angle));
	printf("%f + (%f - %f) * (%f / %f)) = %f\n",lst->plyr.x_plyr ,lst->raycast.yintercept , lst->plyr.y_plyr , cos(lst->raycast.ray_angle), sin(lst->raycast.ray_angle),lst->raycast.xintercept);
	lst->raycast.ystep = lst->unit;
	if (lst->raycast.facingup)
		lst->raycast.ystep *= -1;
	lst->raycast.xstep = lst->unit / tan(lst->raycast.ray_angle);
	if (lst->raycast.facingleft && lst->raycast.xstep > 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingright && lst->raycast.xstep < 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingup)
		lst->raycast.yintercept--;
	while ((lst->raycast.xintercept >= 0 && lst->raycast.xintercept <= lst->unit * lst->j) && (lst->raycast.yintercept >= 0 && lst->raycast.yintercept <= lst->unit * lst->i))
	{
		if (check_wall(lst, lst->raycast.xintercept, lst->raycast.yintercept))
		{
			drawline(lst->plyr.x_plyr,
				lst->plyr.y_plyr,
				lst->raycast.xintercept,
			 	lst->raycast.yintercept,
				lst, lst->plyr.player_color);
			break ;
		}
		else
		{
			lst->raycast.xintercept += lst->raycast.xstep;
			lst->raycast.yintercept += lst->raycast.ystep;
		}
	}
}

void cast_rays(t_graph *lst)
{
	double	fov;
	int		i;
	int		rays_num;
	int		nextx;
	int		nexty;

	lst->raycast.xintercept = 0;
	lst->raycast.yintercept = 0;
	nextx = 0;
	nexty = 0;
	fov = 1.0472;
	// lst->raycast.ray_angle = lst->plyr.rotationangle;
	lst->raycast.ray_angle = lst->plyr.rotationangle - fov / 2;
	i = 0;
	rays_num = 320;
	while (i < rays_num)
	{
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		lst->raycast.ray_angle += fov / rays_num;
		i++;
	}

	
	// my_mlx_pixel_put(lst, lst->raycast.xintercept, lst->raycast.yintercept, 16711680);
}