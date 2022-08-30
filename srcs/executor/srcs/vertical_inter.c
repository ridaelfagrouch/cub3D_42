/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:25:36 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 18:26:09 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

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
