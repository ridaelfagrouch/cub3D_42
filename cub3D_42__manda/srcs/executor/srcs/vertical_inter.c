/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:25:36 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/28 20:59:23 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	searchforverticalinter(t_graph *lst, int check)
{
	while ((lst->raycast.xinter_ve > 0 && lst->raycast.xinter_ve < \
	lst->x * lst->map.unit) && (lst->raycast.yinter_ve > 0 && \
	lst->raycast.yinter_ve < lst->y * lst->map.unit))
	{
		if (checkwall(lst, lst->raycast.xinter_ve - check, \
		lst->raycast.yinter_ve))
		{
			lst->raycast.vertic_intersaction = 1;
			return ;
		}
		else
		{
			lst->raycast.xinter_ve += lst->raycast.xstep;
			lst->raycast.yinter_ve += lst->raycast.ystep;
		}
	}
	lst->raycast.vertic_intersaction = 0;
}

void	vertical_intersaction(t_graph *lst)
{
	int	check;

	check = 0;
	lst->raycast.vertic_intersaction = 0;
	lst->raycast.xinter_ve = floor(lst->plyr.x_plyr / lst->map.unit) \
	* lst->map.unit;
	if (lst->raycast.facingright)
		lst->raycast.xinter_ve += lst->map.unit;
	lst->raycast.yinter_ve = lst->plyr.y_plyr + (lst->raycast.xinter_ve - \
	lst->plyr.x_plyr) * tan(lst->raycast.ray_angle);
	lst->raycast.xstep = lst->map.unit;
	if (lst->raycast.facingleft)
		lst->raycast.xstep *= -1;
	lst->raycast.ystep = lst->map.unit * tan(lst->raycast.ray_angle);
	if (lst->raycast.facingup && lst->raycast.ystep > 0)
		lst->raycast.ystep *= -1;
	if (lst->raycast.facingdown && lst->raycast.ystep < 0)
		lst->raycast.ystep *= -1;
	if (lst->raycast.facingleft)
		check = 1;
	searchforverticalinter(lst, check);
}
