/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:27:30 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 18:28:01 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

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
	if (distance_horiz == -1)
		return (1);
	else if (distance_vertic == -1)
		return (0);
	if (distance_horiz > distance_vertic)
		return (1);
	else
		return (0);
}
void	normilizeAngle(double	*ray_angle)
{
	*ray_angle = fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle = (2 * M_PI) + *ray_angle;
}

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