/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 17:12:22 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void checking_where_plyr_facing(t_graph *lst)
{
	if (lst->raycast.ray_angle >= M_PI && lst->raycast.ray_angle <= (2 * M_PI))
	{
		lst->raycast.facingup = 1;
		lst->raycast.facingdown = 0;
	}
	else
	{
		lst->raycast.facingup = 0;
		lst->raycast.facingdown = 1;
	}
	if (lst->raycast.ray_angle > (0.5 * M_PI) && lst->raycast.ray_angle < (1.5 * M_PI))
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


void	vertical_intersaction(t_graph *lst)
{
	lst->raycast.vertic_intersaction = 0;
	lst->raycast.xintercept_vertic = floor(lst->plyr.x_plyr / lst->unit) * lst->unit;
	if (lst->raycast.facingright)
		lst->raycast.xintercept_vertic += lst->unit;
	lst->raycast.yintercept_vertic = lst->plyr.y_plyr + (lst->raycast.xintercept_vertic - lst->plyr.x_plyr) * tan(lst->raycast.ray_angle);
	lst->raycast.xstep = lst->unit;
	if (lst->raycast.facingleft)
		lst->raycast.xstep *= -1;
	lst->raycast.ystep = lst->unit * tan(lst->raycast.ray_angle);
	if (lst->raycast.facingup && lst->raycast.ystep > 0)
		lst->raycast.ystep *= -1;
	if (lst->raycast.facingdown && lst->raycast.ystep < 0)
		lst->raycast.ystep *= -1;
	if (lst->raycast.facingleft)
		lst->raycast.xintercept_vertic--;
	while ((lst->raycast.xintercept_vertic >= 0 && lst->raycast.xintercept_vertic <= lst->unit * lst->j) && (lst->raycast.yintercept_vertic >= 0 && lst->raycast.yintercept_vertic <= lst->unit * lst->i))
	{
		if (check_wall(lst, lst->raycast.xintercept_vertic, lst->raycast.yintercept_vertic))
		{
			lst->raycast.vertic_intersaction = 1;
			return ;
		}
		else
		{
			lst->raycast.xintercept_vertic += lst->raycast.xstep;
			lst->raycast.yintercept_vertic += lst->raycast.ystep;
		}
	}
	lst->raycast.vertic_intersaction = 0;
}


void	horizantal_intersaction(t_graph *lst)
{
	lst->raycast.horiz_intersaction = 0;
	lst->raycast.yintercept_horiz = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
	if (lst->raycast.facingdown)
		lst->raycast.yintercept_horiz += lst->unit;
	lst->raycast.xintercept_horiz = lst->plyr.x_plyr + (lst->raycast.yintercept_horiz - lst->plyr.y_plyr) / tan(lst->raycast.ray_angle);
	lst->raycast.ystep = lst->unit;
	if (lst->raycast.facingup)
		lst->raycast.ystep *= -1;
	lst->raycast.xstep = lst->unit / tan(lst->raycast.ray_angle);
	if (lst->raycast.facingleft && lst->raycast.xstep > 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingright && lst->raycast.xstep < 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingup)
		lst->raycast.yintercept_horiz--;
	while ((lst->raycast.xintercept_horiz >= 0 && lst->raycast.xintercept_horiz <= lst->unit * lst->j) && (lst->raycast.yintercept_horiz >= 0 && lst->raycast.yintercept_horiz <= lst->unit * lst->i))
	{
		if (check_wall(lst, lst->raycast.xintercept_horiz, lst->raycast.yintercept_horiz))
		{
			lst->raycast.horiz_intersaction = 1;
			return ;
		}
		else
		{
			lst->raycast.xintercept_horiz += lst->raycast.xstep;
			lst->raycast.yintercept_horiz += lst->raycast.ystep;
		}
	}
	lst->raycast.horiz_intersaction = 0;
}

double	distance_points(double x1, double x2, double y1, double y2)
{
	double square_root;
	
	square_root = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (square_root);
}

double	calculate_intersactions(t_graph *lst)
{
	double	distance_horiz;
	double	distance_vertic;

	distance_horiz = 0;
	distance_vertic = 0;
	if (lst->raycast.horiz_intersaction)
		distance_horiz = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_horiz, lst->plyr.y_plyr, lst->raycast.yintercept_horiz);
	else
		distance_horiz = -1;
	if (lst->raycast.vertic_intersaction)
		distance_vertic = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_vertic, lst->plyr.y_plyr, lst->raycast.yintercept_vertic);
	else
		distance_vertic = -1;

	if (distance_horiz == -1 && distance_vertic == -1)
		return (2);
	if (distance_horiz == -1)
		return (1);
	else if (distance_vertic == -1)
		return (0);
	if (distance_horiz > distance_vertic)
		return (1);
	else
		return (0);
}

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
	else if (j == 0)
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
	lst->raycast.ray_angle = lst->plyr.rotationangle - fov / 2;
	i = 0;
	j = 0;
	rays_num = 600;
	while (i < rays_num)
	{
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		draw_rays(lst, j);
		lst->raycast.ray_angle += fov / rays_num;
		i++;
	}
}